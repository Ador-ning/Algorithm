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

	/*
	 * type: int / double / char
	 * */
	template<typename Type=int>
	std::vector<Type> stringToVector(std::string &str, const char delimiter = ' ') {
		std::vector<Type> res;
		if (str.empty())
			return res;

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

}
#endif //ALGORITHM_BASE_H
