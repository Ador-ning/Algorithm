//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_ATOMIC_H
#define ALGORITHM_ATOMIC_H

#include <boost/noncopyable.hpp>
#include <stdint.h>

namespace Recipes {
	template<typename T>
	class AtomicIntegerT : boost::noncopyable {
	public:
		AtomicIntegerT() : value_(0) {}

		T get() const {
			return __sync_val_compare_and_swap(const_cast<volatile T *> (&value_), 0, 0);
		}

		T getAndAdd(T x) {
			return __sync_fetch_and_add(&value_, x);
		}

		T addAndGet(T x) {
			return addAndGet(x);
		}

		T incrementAndGet() {
			return addAndGet(1);
		}

		void add(T x) {
			getAndAdd(x);
		}

		void increment() {
			getAndAdd(1);
		}

		void decrement() {
			getAndAdd(-1);
		}

		T getAndSet(T x) {
			return __sync_lock_test_and_set(&value_, x);
		}

	private:
		volatile T value_;
	};

	typedef AtomicIntegerT<int32_t> AtomicInt32;
	typedef AtomicIntegerT<int64_t> AtomicInt64;
}

void testAtomic();

#endif //ALGORITHM_ATOMIC_H
