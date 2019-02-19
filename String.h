//
// Created by ning on 2019/2/19.
//

#ifndef ALGORITHM_STRING_H
#define ALGORITHM_STRING_H

#include <iostream>
#include <iomanip>
#include <string.h>

using std::ostream;
using std::istream;

class String {
	friend ostream &operator<<(ostream &, String &); // 重载操作符 <<
	friend istream &operator>>(istream &, String &); // 重载操作符 >>
public:

	String(const char *str = nullptr); //  赋值构造函数 const char *

	String(const String &rhs); // 赋值构造函数 String

	String &operator=(const String &rhs); // 重载操作符 =

	String operator+(const String &rhs) const; // 重载操作符 +

	bool operator==(const String &rhs) const; // 重载操作符 ==

	char &operator[](unsigned int) const; // 重载操作符 []

	String &operator+=(const String &rhs); // 重载操作符 +=

	size_t size() const {
		return strlen(data_);
	}

	~String() {
		delete[] data_;
	}

private:
	char *data_;
};

void test_classString();

#endif //ALGORITHM_STRING_H
