//
// Created by ning on 2018/12/8.
//

#include <algorithm>
#include "problem.h"

// 子集问题解法：  增量 / 位标志

// leetcode subsets
// nums 无重复数据
std::vector<std::vector<int>> Algorithm::subsets(std::vector<int> &nums) {
	std::vector<std::vector<int>> res;
	if (nums.size() <= 0)
		return res;
	std::vector<int> path;
	std::sort(nums.begin(), nums.end());

	// 增量
	for (int i = 0; i <= nums.size(); ++i) {
		path.clear();
		helper(nums, res, path, 0, 0, i);
	}
	return res;
}

void Algorithm::helper(std::vector<int> &nums, std::vector<std::vector<int>> &res, std::vector<int> &path, int start,
                       int count, int max_count) {
	// 终止
	if (count == max_count) {
		res.push_back(path);
		return;
	}

	// 递归
	// 选 or 不选
	for (int i = start; i < nums.size(); ++i) {
		path.push_back(nums[i]);
		helper(nums, res, path, i + 1, count + 1, max_count);
		path.pop_back();
	}
}

// leetcode subsets
// nums 有重复数据