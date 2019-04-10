//
// Created by ning on 2019/4/8.
//

#ifndef ALGORITHM_EXCEPTION_H
#define ALGORITHM_EXCEPTION_H

#include <string>
#include <exception>

namespace Recipes {
	class Exception : public std::exception {
	public:
		explicit Exception(const char *what);

		virtual ~Exception() throw();

		virtual const char *what() const throw();

		const char *stackTrace() const throw();

	private:
		std::string message_;
		std::string stack_;
	};

}

#endif //ALGORITHM_EXCEPTION_H
