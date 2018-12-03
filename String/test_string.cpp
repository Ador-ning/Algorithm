//
// Created by ning on 2018/11/26.
//
#include <iostream>
#include <vector>
#include "problem.h"

// "2" * "3" = "6"
std::string multiply(std::string num1, std::string num2) {
	std::string res;
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0 || num1 == "0" || num2 == "0")
		return "0";

	int k = n1 + n2 - 2, carry = 0;
	std::vector<int> v(n1 + n2, 0);

	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
		}
	}

	for (int i = 0; i < n1 + n2; ++i) {
		v[i] += carry;
		carry = v[i] / 10;
		v[i] %= 10;
	}

	int i = n1 + n2 - 1;
	while (v[i] == 0)
		--i;
	while (i > 0)
		res.push_back(v[i--] + '0');
	return res;
}

int main() {
	std::cout << "string test: " << std::endl;
}
