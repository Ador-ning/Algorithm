//
// Created by ning on 2019/4/8.
//

#include "Thread.h"
#include <boost/weak_ptr.hpp>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
// #include <sys/prctl.h>  // 进程重命名


namespace Recipes {
	namespace CurrentThread {
		__thread const char *t_threadName = "unknown";
	}
}

namespace {
	__thread pid_t t_cachedTid = 0;

	pid_t gettid() {
		return static_cast<pid_t >(::syscall(SYS_gettid));
	}

	void afterFork() {
		t_cachedTid = gettid();
		Recipes::CurrentThread::t_threadName = "main";
	}

	class ThreadNameInitializer {
	public:
		ThreadNameInitializer() {
			Recipes::CurrentThread::t_threadName = "main";
			pthread_atfork(nullptr, nullptr, &afterFork);
		}
	};

	ThreadNameInitializer init;

	class ThreadData {
	public:
		typedef Recipes::Thread::ThreadFunc ThreadFunc;
		ThreadFunc func_;
		std::string name_;
		boost::weak_ptr<pid_t> wkTid_;

		ThreadData(const ThreadFunc &func,
		           const std::string &name,
		           const boost::shared_ptr<pid_t> &tid)
				: func_(func), name_(name), wkTid_(tid) {

		}

		void runInThread() {
			pid_t tid = Recipes::CurrentThread::tid();
			boost::shared_ptr<pid_t> ptid = wkTid_.lock();

			if (ptid) {
				*ptid = tid;
				ptid.reset();
			}

			Recipes::CurrentThread::t_threadName = name_.empty() ? "recipesThread" : name_.c_str();
			func_();
			Recipes::CurrentThread::t_threadName = "finished";
		}
	};

	void *startThread(void *obj) {
		ThreadData *data = static_cast<ThreadData *>(obj);
		data->runInThread();
		delete data;
		return nullptr;
	}
}

using namespace Recipes;

pid_t CurrentThread::tid() {
	if (t_cachedTid == 0) {
		t_cachedTid = gettid();
	}
	return t_cachedTid;
}

const char *CurrentThread::name() {
	return t_threadName;
}

bool CurrentThread::isMainThread() {
	return tid() == ::getpid(); //  主线程ID == 进程ID
}

AtomicInt32 Thread::numCreated_;

Thread::Thread(const Recipes::Thread::ThreadFunc &f, const std::string &n)
		: started_(false), joined_(false),
		  pthreadId_(0), tid_(new pid_t(0)),
		  func_(f), name_(n) {
	numCreated_.increment();
}

Thread::~Thread() {
	if (started_ && joined_) {
		pthread_detach(pthreadId_);
	}
}

void Thread::start() {
	assert(!started_);
	started_ = true;

	ThreadData *data = new ThreadData(func_, name_, tid_);
	if (pthread_create(&pthreadId_, nullptr, &startThread, data)) {
		started_ = false;
		delete data;
		abort();
	}
}

void Thread::join() {
	assert(started_);
	assert(!joined_);
	joined_ = true;
	pthread_join(pthreadId_, nullptr);
}

