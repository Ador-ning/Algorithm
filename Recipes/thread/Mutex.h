//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_MUTEX_H
#define ALGORITHM_MUTEX_H

#include "Thread.h"
#include <pthread.h>
#include <assert.h>
#include <boost/noncopyable.hpp>
#include <sys/types.h>


namespace Recipes {
	class MutexLock : boost::noncopyable {
	public:
		MutexLock() : holder_(0) {
			pthread_mutex_init(&mutex_, nullptr);
		}

		~MutexLock() {
			assert(holder_ == 0);
			pthread_mutex_destroy(&mutex_);
		}

		void assertLocked() {
			assert(isLockedByThisThread());
		}

		// internal usage
		void lock() {
			pthread_mutex_lock(&mutex_);
			holder_ = CurrentThread::tid();
		}

		void unlock() {
			holder_ = 0;
			pthread_mutex_unlock(&mutex_);
		}

		pthread_mutex_t *getPthreadMutex() {
			return &mutex_;
		}

	private:
		bool isLockedByThisThread() {
			return holder_ == CurrentThread::tid();
		}

		pthread_mutex_t mutex_; //
		pid_t holder_; //
	};

	class MutexLockGuard : boost::noncopyable {
	public:
		explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex) {
			mutex_.lock();
		}

		~MutexLockGuard() {
			mutex_.unlock();
		}

	private:
		MutexLock &mutex_;
	};
}

// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"

#endif //ALGORITHM_MUTEX_H
