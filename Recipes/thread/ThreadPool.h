//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_THREADPOOL_H
#define ALGORITHM_THREADPOOL_H

#include "Mutex.h"
#include "Condition.h"
#include "Thread.h"

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_vector.hpp>


namespace Recipes {
	class ThreadPool : boost::noncopyable {
	public:
		typedef boost::function<void()> Task;

		explicit ThreadPool(const std::string &name = std::string());

		~ThreadPool();

		void start(int numThreads);

		void stop();

		void run(const Task &f);

	private:
		void runInThread();

		Task take();

		MutexLock mutex_;
		Condition cond_;
		std::string name_;
		boost::ptr_vector<Recipes::Thread> threads_;
		std::deque<Task> queue_;
		bool running_;
	};

}


#endif //ALGORITHM_THREADPOOL_H
