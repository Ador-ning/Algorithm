//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_THREAD_H
#define ALGORITHM_THREAD_H

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <pthread.h>
#include "Atomic.h"

namespace Recipes {
	class Thread : boost::noncopyable {
	public:
		typedef boost::function<void()> ThreadFunc;

		explicit Thread(const ThreadFunc &, const std::string &name = std::string());

		~Thread();

		void start();

		void join();

		bool started() const {
			return started_;
		}

		pid_t tid() const {
			return *tid_;
		}

		const std::string &name() const {
			return name_;
		}

		static int numCreated() {
			return numCreated_.get();
		}

	private:
		bool started_;
		bool joined_;
		pthread_t pthreadId_; // 线程 ID
		boost::shared_ptr<pid_t> tid_; // 进程 ID
		ThreadFunc func_;
		std::string name_;
		static AtomicInt32 numCreated_;
	};


	// functions
	namespace CurrentThread {
		pid_t tid();

		const char *name();

		bool isMainThread();
	}
}


#endif //ALGORITHM_THREAD_H
