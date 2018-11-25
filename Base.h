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



namespace Algorithm {
#define  DEBUG true

// Leetcode pre-process code
// ----------------------------------------------------------------------------------------
	// 去左侧空格
	void trimLeftTrailingSpaces(std::string &input) {
		input.erase(input.begin(), std::find_if(input.begin(), input.end(),
		                                        [](int ch) { return !isspace(ch); }));
	}

	// 去除右侧空格
	void trimRightTrailingSpaces(std::string &input) {
		input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(),
		            input.end());
	}

	// "       1 2 3 4 5 6 8 9 0 2 34 22   "
	std::vector<int> stringToIntegerVector(std::string input) {
		std::vector<int> output;
		trimRightTrailingSpaces(input);
		trimLeftTrailingSpaces(input);

		input = input.substr(1, input.length() - 2);
		//  2 3 4 5 6 8 9 0 2 34 2
		std::cout << "input: " << input << std::endl;

		std::stringstream ss;
		ss.str(input);
		std::string item;
		char delimiter = ' ';
		while (getline(ss, item, delimiter)) {
			output.push_back(stoi(item));   // wrong here
		}
		return output;
	}

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

	}

	std::vector<std::string> stringToStringVector(std::string &str, const char delimiter = ' ') {
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

	std::vector<std::string> inputStrVector1D(const char delimiter = ' ') {
		if (DEBUG)
			std::cout << "Input the data: " << std::endl;

		std::string line;
		getline(std::cin, line);
		auto res = stringToStringVector(line, delimiter);
		return res;
	}
}

void test1D() {
	//       1 2 3 4 5 6 8 9.908 0 2.8 34 22
	std::string s = "       1 2 3 4 5 6 8 9 0 2 34 22   ";
	// Algorithm::trimLeftTrailingSpaces(s);
	// Algorithm::trimRightTrailingSpaces(s);
	// std::cout << s << std::endl;
	auto out = Algorithm::stringToIntegerVector(s);
	auto outIt = out.begin();
	Print(outIt, out.end());

	// 1 2 3 4 5 6 8 9.908 0 2.8 34 22
	// 1 2 3 4 5 6 8 9 0 2 34 22
	// a b c d e g h i j k
	auto res = Algorithm::input1D<char>(); // int float char
	auto it = res.begin();
	Print(it, res.end());

	// abd jjl nin898 uibhjk 2233 KK**
	auto res_ = Algorithm::inputStrVector1D();
	auto it_ = res_.begin();
	Print(it_, res_.end());
}


#endif //ALGORITHM_BASE_H
