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
#define INT_MIN     （-2147483648）
#define INT_MAX      2147483647

#define MAXN 5001
#define INF INT_MAX
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define LL(a) ((a) << 1)
#define RR(a) (((a) >> 1)+1)

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

// leetcode 环形队列
// 插入 / 删除位置
// 栈满 / 栈空判别
class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		data_.resize(k);
		head_ = -1;
		tail_ = -1;
		size_ = k;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;
		if (isEmpty())
			head_ = 0;
		tail_ = (tail_ + 1) % size_;
		data_[tail_] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		if (head_ == tail_) {
			head_ = -1;
			tail_ = -1;
			return true;
		}
		head_ = (head_ + 1) % size_;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return data_[head_];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		return data_[tail_];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return head_ == -1;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {

		return ((tail_ + 1) % size_) == head_;
	}

private:
	std::vector<int> data_;
	int head_;
	int tail_;
	int size_;
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
