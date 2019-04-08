//
// Created by ning on 2018/11/26.
//

#include <cassert>
#include <ctime>
#include "Base.h"

using namespace Algorithm;

// Leetcode pre-process code

std::vector<std::string> Algorithm::stringToStringVector(std::string &str, const char delimiter) {
	std::vector<std::string> res;
	if (str.empty())
		return res;
	std::string str_tmp;
	int index;
	while (true) {
		index = str.find(delimiter);

		if (-1 == index) {
			str_tmp = str.substr(0, index);
			res.push_back(str_tmp);
			break;
		}
		str_tmp = str.substr(0, index);
		res.push_back(str_tmp);
		str.erase(0, index + 1);
	}
	return res;
}

std::vector<std::string> Algorithm::inputStrVector1D(const char delimiter) {
	if (DEBUG)
		std::cout << "Input the data: " << std::endl;

	std::string line;
	getline(std::cin, line);
	auto res = stringToStringVector(line, delimiter);
	return res;
}

// 测试用例
// "+-42" "-+42" == 42
// "   -42" == 42
// "4193 with words" == 4193
// "words and 987" == 0
// "-91283472332" == -2147483648
int myAtoi(std::string s) {
	int num = 0;
	int sign = 1;
	bool tag = false; // +-
	const int len = s.size();
	int i = 0;

	// 行首空白符
	while (s[i] == ' ' && i < len)
		i++;

	// 符号位
	if (s[i] == '+') {
		if (tag)
			return 0;
		tag = true;
		i++;
	}

	if (s[i] == '-') {
		if (tag)
			return 0;
		tag = true;
		sign = -1;
		i++;
	}

	for (; i < len; ++i) {
		if (s[i] < '0' || s[i] > '9')
			break;

		// 数据溢出
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) {
			return sign == -1 ? INT_MIN : INT_MAX;
		}

		num = num * 10 + s[i] - '0';
	}
	return num * sign;
}

int myStrlen(const char *str) {
	const char *s = str;
	for (; *s; ++s) {

	}
	return (s - str);
}

char *myStrcpy(char *to, const char *from) {
	assert(to != nullptr && from != nullptr);
	char *p = to;
	while ((*p++ = *from++) != '\0');
	return to;
}

// substr O(mn) 暴力求解
char *myStrstr(const char *haystack, const char *needle) {
	// if needle is empty return the full string
	if ((!*needle))
		return (char *) haystack;

	const char *p1;
	const char *p2;
	const char *p1_advance = haystack;

	for (p2 = &needle[1]; *p2; ++p2) {
		p1_advance++; // advance p1_advance M-1 times
	}

	for (p1 = haystack; *p1_advance; p1_advance++) {
		char *p1_old = (char *) p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2)
			return p1_old;
		p1 = p1_old + 1;
	}
	return nullptr;
}

// 递归二分法求 pow(x, n)
double myPow(double x, int n) {
	if (n < 0)
		return 1 / power(x, n);
	return power(x, n);
}

double power(double x, int n) {
	if (n == 0)
		return 1;

	double half = power(x, n / 2);
	if (n % 2 == 0)
		return half * half;
	else
		return x * half * half;
}

int myRandom(int n) {
	return rand() % n + 1;
}

int rand5() {
	return myRandom(5);
}

// 由 rand5() 生成
int rand7() {
	while (1) {

		// 生成等概率 0 -> 24
		int x = (rand5() - 1) * 5 + (rand5() - 1);

		if (x >= 21) { // 剔除 21 22 23 24
			continue;
		} else
			return x % 7 + 1;  // 0 -> 20
	}
}

void test_rand5() {

	int i = 0;
	int n = 5;
	int a[100] = {0};

	// 初始化随机种子
	srand(time(nullptr));

	// 测试 100 万次
	for (; i < 1000000; ++i)
		a[rand5() - 1]++;

	for (i = 0; i < 5; ++i)
		std::cout << a[i] << " ";
}

void test_rand7() {
	int i = 0;
	int n = 7;
	int a[7] = {0};

	srand(time(nullptr));

	for (; i < 7000000; ++i)
		a[rand7() - 1]++;

	for (i = 0; i < n; ++i)
		std::cout << a[i] << " ";
}
