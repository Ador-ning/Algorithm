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

#define Line() std::cout << std::endl


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

#endif //ALGORITHM_BASE_H
