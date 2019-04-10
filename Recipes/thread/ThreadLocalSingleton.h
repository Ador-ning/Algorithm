//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_THREADLOCALSINGLETON_H
#define ALGORITHM_THREADLOCALSINGLETON_H

#include <boost/noncopyable.hpp>

namespace Recipes {
	template<typename T>
	class ThreadLocalSingleton : boost::noncopyable {
	public:
		static T &instance() {
			if (!value_) {
				value_ = new T();
			}
			return *value_;
		}

		static void destory() {
			delete value_;
			value_ = nullptr;
		}

	private:
		ThreadLocalSingleton();

		~ThreadLocalSingleton();

		static __thread T *value_;
	};

	template<typename T>
	__thread T *ThreadLocalSingleton<T>::value_ = nullptr;
}
#endif //ALGORITHM_THREADLOCALSINGLETON_H
