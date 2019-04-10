cmake_minimum_required(VERSION 3.1)
project(Algorithm)
set(CMAKE_CXX_STANDARD 17)

set(THREAD_SRC
		# 原子操作 -- gcc 内置 __sync 系列函数 // C++11 也有 atomic 系列函数
		Atomic.h
		Atomic_test.cpp

		# 队列
		BlockingQueue.h
		BoundedBlockingQueue.h

		# mutex 和 condition
		Condition.h
		CountDownLatch.h

		# 继承 std::exception // 实现其中虚函数 what() / trace()
		Exception.h
		Exception.cpp

		# 信号
		Mutex.h

		# signal callback
		SignalSlot.h
		SignalSlotTrival.h

		Singleton.h

		# 线程实现
		Thread.h
		Thread.cpp
		ThreadPool.h
		ThreadPool.cpp
		ThreadLocalSingleton.h
		ThreadLocal.h

		WeaCallback.h
		main.cpp
		)

add_executable(recipes_thread ${THREAD_SRC})