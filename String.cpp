//
// Created by ning on 2019/2/19.
//

#include <iostream>
#include "String.h"

using std::cout;
using std::endl;
using std::cin;


inline String::String(const char *str) {
	if (!str)
		data_ = nullptr;
	else {
		data_ = new char[strlen(str) + 1];
		strcpy(data_, str);
	}
}

inline String::String(const String &rhs) {
	if (!rhs.data_)
		data_ = nullptr;
	else {
		data_ = new char[strlen(rhs.data_) + 1];
		strcpy(data_, rhs.data_);
	}
}

inline String &String::operator=(const String &rhs) {
	if (this != &rhs) {
		// 1.
		delete[] data_;

		// 2.
		if (!rhs.data_)
			data_ = nullptr;
		else {
			data_ = new char[strlen(rhs.data_) + 1];
			strcpy(data_, rhs.data_);
		}
	}
	return *this;
}

inline String String::operator+(const String &rhs) const {
	String newStr;
	if (!rhs.data_)
		newStr = *this;
	else if (!data_)
		newStr = rhs;
	else {
		newStr.data_ = new char[strlen(data_) + strlen(rhs.data_) + 1];
		strcpy(newStr.data_, data_);
		strcat(newStr.data_, rhs.data_);
	}
	return newStr;
}

inline bool String::operator==(const String &rhs) const {
	if (strlen(rhs.data_) != strlen(data_))
		return false;
	return strcmp(data_, rhs.data_) ? false : true;
}

inline String &String::operator+=(const String &rhs) {
	if (rhs.data_ != nullptr) {
		char *newData = new char[strlen(this->data_) + strlen(rhs.data_) + 1];
		strcpy(newData, this->data_);
		strcat(newData, rhs.data_);
		delete[] data_;
		data_ = newData;
	}

	return *this;
}

inline char &String::operator[](unsigned int idx) const {
	if (idx >= 0 && idx <= strlen(data_))
		return data_[idx];
}

ostream &operator<<(ostream &os, String &str) {
	os << str.data_;
	return os;
}

istream &operator>>(istream &is, String &str) {
	char temp[255];
	is >> temp;

	delete[] str.data_;
	str.data_ = new char[strlen(temp) + 1];
	strcpy(str.data_, temp);
	return is;
}


void test_classString() {
	String str1 = "Aha!";
	String str2 = "My friend";
	String str3 = str1 + str2;

	cout << str1 << " " << str1.size() << ' ' << str1[0] << ' ' << str1[str1.size() - 1] << endl;
	cout << str3 << endl;

	String str4;
	cin >> str4;
	cout << str4 << endl;
	str4 += str1;
	cout << str4;
}