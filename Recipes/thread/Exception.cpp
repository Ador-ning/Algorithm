//
// Created by ning on 2019/4/8.
//

#include "Exception.h"
#include <cxxabi.h>
#include <execinfo.h>
#include <stdlib.h>

using namespace Recipes;

Exception::Exception(const char *what) : message_(what) {
	const int len = 200;
	void *buffer[len];
	int nptrs = ::backtrace(buffer, len); // exception
	char **strings = ::backtrace_symbols(buffer, nptrs);
	if (strings) {
		for (int i = 0; i < nptrs; ++i) {
			stack_.append(strings[i]);
			stack_.push_back('\n');
		}
		free(strings);
	}
}

Exception::~Exception() throw() {}

const char *Exception::what() const throw() {
	return message_.c_str();
}

const char *Exception::stackTrace() const throw() {
	return stack_.c_str();
}