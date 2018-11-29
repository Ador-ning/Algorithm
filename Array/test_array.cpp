//
// Created by ning on 2018/11/26.
//
#include <iostream>
#include "problem.h"

// Given an array of integers, every element appears twice except for one. Find that single one.
int singleNumber(int [], int n) {
	return 0;
}


int main() {
	std::cout << "array test: " << std::endl;
	int i = 1, i2 = 1, i3 = 2;
	std::cout << (i & i2) << ' ' << (i & i3) << ' ' << (i & i2 & i3) << ' ' << (i & i3 & i2) << std::endl;
}