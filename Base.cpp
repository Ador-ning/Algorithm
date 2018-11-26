//
// Created by ning on 2018/11/26.
//

#include "Base.h"

using namespace Algorithm;

// Leetcode pre-process code

// "       1 2 3 4 5 6 8 9 0 2 34 22   "
std::vector<int> Algorithm::stringToIntegerVector(std::string input) {
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

void test1D() {
	//       1 2 3 4 5 6 8 9.908 0 2.8 34 22
	std::string s = "       1 2 3 4 5 6 8 9 0 2 34 22   ";
	// Algorithm::trimLeftTrailingSpaces(s);
	// Algorithm::trimRightTrailingSpaces(s);
	// std::cout << s << std::endl;
	auto out = Algorithm::stringToIntegerVector(s);
	auto outIt = out.begin();
	Print(outIt, out.end());

	// 1 2 3 4 5 6 8 9.908 0 2.8 34 22  float
	// 1 2 3 4 5 6 8 9 0 2 34 22  int
	// a b c d e g h i j k   char
	auto res = Algorithm::input1D<char>(); // int float char
	auto it = res.begin();
	Print(it, res.end());

	// abd jjl nin898 uibhjk 2233 KK**  string
	auto res_ = Algorithm::inputStrVector1D();
	auto it_ = res_.begin();
	Print(it_, res_.end());
}

