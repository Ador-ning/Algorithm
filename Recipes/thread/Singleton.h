//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_SINGLETON_H
#define ALGORITHM_SINGLETON_H

#include <boost/noncopyable.hpp>
#include <pthread.h>
#include <stdlib.h>

namespace Recipes {
	template<typename T>
	class Singleton : boost::noncopyable {
	public:
		static T &instance() {
			pthread_once(&ponce_, &Singleton::init);
			return *value_;
		}

	private:
		Singleton();

		~Singleton();

		static void init() {
			value_ = new T();
			::atexit(destory);
		}

		static void destory() {
			delete value_;
		}

		static pthread_once_t ponce_;
		static T *value_;
	};

	template<typename T>
	pthread_once_t Singleton::ponce_ = PTHREAD_ONCE_INIT;
	template<typename T>
	T *Singleton<T>::value_ = nullptr;
}

#endif //ALGORITHM_SINGLETON_H
