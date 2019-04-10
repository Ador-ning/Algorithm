//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_CONDITION_H
#define ALGORITHM_CONDITION_H

#include "Mutex.h"
#include <boost/noncopyable.hpp>
#include <pthread.h>
#include <errno.h>

namespace Recipes {
	class Condition : boost::noncopyable {
	public:
		explicit Condition(MutexLock &mutex) : mutex_(mutex) {
			pthread_cond_init(&pcond_, nullptr);
		}

		~Condition() {
			pthread_cond_destroy(&pcond_);
		}

		void wait() {
			pthread_cond_wait(&pcond_, mutex_.getPthreadMutex());
		}

		bool waitForSeconds(int seconds) {
			struct timespec abstime;
			clock_gettime(CLOCK_REALTIME, &abstime);
			abstime.tv_sec += seconds;
			return ETIMEDOUT == pthread_cond_timedwait(&pcond_, mutex_.getPthreadMutex(), &abstime);
		}

		void notify() {
			pthread_cond_signal(&pcond_);
		}

		void notifyAll() {
			pthread_cond_broadcast(&pcond_);
		}

	private:
		MutexLock &mutex_;
		pthread_cond_t pcond_;  //
	};
}

#endif //ALGORITHM_CONDITION_H
