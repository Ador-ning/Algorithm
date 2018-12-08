//
// Created by ning on 2018/11/29.
//

#ifndef ALGORITHM_PROBLEM_H
#define ALGORITHM_PROBLEM_H

#include <vector>
#include <iostream>

namespace Algorithm {
// Part one: 有序数组问题 -- log(n) -- 二分查找

	// 题1
	// 找到数组中第一K的下标，如果K不存在，返回-1
	int GetFirstK(const int *data, int length, int k, int start, int ed);

	// 找到数组中最后一个k的下标。如果数组中不存在k，返回-1
	int GetLastK(const int *data, int length, int k, int start, int ed);

	int GetNumberOfK(const int *data, int length, int k);

	void Test(const char *testName, int data[], int length, int k, int expected);

	// 变形题
	int GetMissingNumber(const int *numbers, int length);

	// 假设一个单调递增的数组里的每一个元素都是整数并且是唯一的， 找出数组中任意一个数值等于其下标的元素
	int GetNumberSameAsIndex(const int *numbers, int length);

	// 输入一个递增数组和一个数字s，在数组中查找两个数，使得和为s，如果有多对数字，输出任意一对即可
	bool FindNumbersWithSum(int *data, int length, int sum, int *num1, int *num2);

	// leetcode
	// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
	int removeDuplicates(std::vector<int> &nums);

// Part two: 旋转有序数组问题 -- log(n)
	// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
	int MinInOrder(const int numbers[], int index1, int index2);

	int Min(int numbers[], int length);

	// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
	// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1
	int search(std::vector<int> &nums, int target);

	void test_search();

	void Test(int *numbers, int length, int expected);

	int test_rotatedArray();

// Part three: 查找 / 排序



// Part four: 其他
	// leetcode
	int maxArea(std::vector<int> &height);

	// leetcode -- 子集 subsets  增量
	std::vector<std::vector<int>> subsets(std::vector<int> &nums);

	// BFS
	void
	helper(std::vector<int> &nums, std::vector<std::vector<int>> &res, std::vector<int> &path, int start, int count,
	       int max_count);
}

#endif //ALGORITHM_PROBLEM_H
