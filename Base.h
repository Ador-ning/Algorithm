//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_BASE_H
#define ALGORITHM_BASE_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <typeinfo>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>

// iterator for printing contents to debug
#define Print(it, end) \
    for(; it != end; ++it) \
        std::cout << *it << '\t'; \

#define TypeProcess(Type, res) \
    if (typeid(Type) == typeid(int)) { \
        int t = stoi(str_tmp); \
        res.push_back(t); \
    } else if (typeid(Type) == typeid(float) || typeid(Type) == typeid(double)) { \
        double t = atof(str_tmp.c_str()); \
        res.push_back(t); \
    } else if (typeid(Type) == typeid(char)) { \
        char t = str_tmp[0]; \
        res.push_back(t); \
    } else { \
        std::cout << "Not this Type." << std::endl; \
        exit(1); } \

#define Line() std::cout << std::endl

// 2^32
#define INT_MIN     -2147483648
#define INT_MAX      2147483647

// leetcode 最小栈
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈
class MinStack {
public:
	MinStack() : capacity_(1), top_(-1), min_(pow(2, 31) - 1) {
		stack_ = (int *) malloc(capacity_ * sizeof(int));
	}

	~MinStack() {
		free(stack_);
	}

	void push(int x) {
		top_++;
		if (top_ >= capacity_) {
			capacity_ *= 2;
			stack_ = (int *) realloc(stack_, capacity_ * sizeof(int));
		}
		stack_[top_] = x;
		if (x < min_)
			min_ = x;
	}

	void pop() {
		if (top_ < 0)
			return;
		top_--;
		min_ = pow(2, 31) - 1;
		for (int i = 0; i <= top_; ++i) {
			if (stack_[i] < min_)
				min_ = stack_[i];
		}
	}

	int top() {
		return stack_[top_];
	}

	int getMin() {
		return min_;
	}

	int size() {
		return top_ + 1;
	}

	bool empty() {
		return (top_ < 0);
	}

private:
	int *stack_;
	int capacity_;
	int top_;
	int min_;
};

namespace Algorithm {
#define  DEBUG true

// ----------------------------------------------------------------------------------------
// 去左侧空格
	inline void trimLeftTrailingSpaces(std::string &input) {
		input.erase(input.begin(), std::find_if(input.begin(), input.end(),
		                                        [](int ch) { return !isspace(ch); }));
	}

// 去除右侧空格
	inline void trimRightTrailingSpaces(std::string &input) {
		input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(),
		            input.end());
	}


	std::vector<int> stringToIntegerVector(std::string input);

	std::vector<std::string> stringToStringVector(std::string &str, const char delimiter = ' ');

	std::vector<std::string> inputStrVector1D(const char delimiter = ' ');

	// ----------------------------------------------------------------------------------------
// type: int / double / char
	template<typename Type=int>
	std::vector<Type> stringToVector(std::string &str, const char delimiter = ' ') {
		std::vector<Type> res;
		if (str.empty())
			return res;
		trimLeftTrailingSpaces(str);
		trimRightTrailingSpaces(str);

		std::string str_tmp;
		int index;
		while (true) {
			index = str.find(delimiter);
			if (-1 == index) {
				str_tmp = str.substr(0, index);
				TypeProcess(Type, res);
				break;
			}
			str_tmp = str.substr(0, index);
			TypeProcess(Type, res);
			str.erase(0, index + 1);
		}
		return res;
	}

	template<typename Type>
	std::vector<Type> input1D(const char delimiter = ' ') {
		if (DEBUG)
			std::cout << "Input the data: " << std::endl;

		std::string line;
		getline(std::cin, line);
		auto res = stringToVector<Type>(line, delimiter);
		return res;
	}

	template<typename Type>
	std::vector<std::vector<Type>> input2D(const int row, const char delimiter = ' ') {
		std::vector<std::vector<Type>> res;
		return res;
	}

}

int myAtoi(std::string s);

int myStrlen(const char *str);

char *myStrcpy(char *to, const char *from);

char *myStrstr(const char *haystack, const char *needle);

// 生成 1 -> n 之间的整数
int myRandom(int n);

// 生成 1, 2, 3, 4, 5
int rand5();

// 由 rand5() 生成
int rand7();

void test_rand5();

void test_rand7();


#endif //ALGORITHM_BASE_H
