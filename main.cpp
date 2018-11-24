#include <iostream>
#include <vector>
#include <string>
#include "Base.h"

using namespace Algorithm;

int main(int argc, const char *argv[]) {
	std::cout << "main: " << std::endl;

	std::string s = "1,2,3,4,5,hahh6,7,8,9,mmn";
	// auto res = stringToVector<std::string>(s, ',');
	auto res = stringToStringVector(s, ',');
	auto it = res.begin();
	Print(it, res.end());

	return 0;
}