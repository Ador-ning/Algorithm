//
// Created by ning on 2018/11/26.
//
#include <iostream>
#include "problem.h"


using namespace Algorithm;

// Given an array of integers, every element appears twice except for one. Find that single one.
int singleNumber(int A[], int n) {
	for (int i = 1; i < n; ++i) {
		A[0] ^= A[i];
	}
	return A[0];
}

//  every element appears three except for one. Find that single one.
// 利用三个变量分别保存各个二进制位上 1 出现一次、两次、三次的分布情况，最后只需返回变量一就行了
int singleNumber2(int A[], int n) {
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < n; i++) {
		two |= one & A[i];
		one ^= A[i];
		// std::cout << one << std::endl;
		three = one & two;
		one &= ~three;
		two &= ~three;
	}
	return one;
}


int main() {
	std::cout << "array test: " << std::endl;
	int A[10] = {1, 3, 1, 3, 1, 6, 6, 0, 6, 3};
	// std::cout << singleNumber2(A, 10);
	test_search();
}