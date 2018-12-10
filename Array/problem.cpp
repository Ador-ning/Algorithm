//
// Created by ning on 2018/12/4.
//

#include "problem.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

namespace Algorithm {

	// leetcode  盛最多水的容器
	// [1,8,6,2,5,4,8,3,7] -- 49  == 7 * 7
	int maxArea(std::vector<int> &height) {
		// 双指针
		int left = 0;
		int right = height.size() - 1;

		int maxArea = 0;

		while (left < right) {
			maxArea = std::max(maxArea,
			                   std::min(height[left], height[right]) * (right - left));

			// 移动
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return maxArea;
	}

	// leetcode TwoSum -- hash
	// 给定一个整数数组 nums 和一个目标值 target，
	// 请你在该数组中找出和为目标值的那两个 整数，并返回他们的数组下标。
	std::vector<int> twoSum(std::vector<int> &nums, int target) {
		std::vector<int> res;
		if (nums.size() < 2)
			return res;
		std::unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.find(target - nums[i]) != mp.end()) {
				res.push_back(i);
				res.push_back(mp[target - nums[i]]);
				return res;
			}
			mp[nums[i]] = i;
		}
		return res;
	}

	// leetcode ThreeSums -- 暴力求解
	// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
	// 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
	std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
		std::vector<std::vector<int>> result;
		if (nums.size() < 3)
			return result;

		std::sort(nums.begin(), nums.end());
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			// 元素重复
			if (i > 0 && nums[i - 1] == nums[i])
				continue;

			int a = nums[i]; // 固定一个数
			int low = i + 1; // 双指针
			int high = n - 1;
			while (low < high) {
				int b = nums[low];
				int c = nums[high];

				if ((a + b + c) == 0) {
					std::vector<int> v = {a, b, c};
					result.push_back(v);

					// 重复
					while (low < n - 1 && nums[low] == nums[low + 1])
						low++;
					while (high > 0 && nums[high] == nums[high - 1])
						high--;
					// move
					high--;
					low++;
				} else if ((a + b + c) > 0) {
					while (high > 0 && nums[high] == nums[high - 1])
						high--;
					high--;
				} else {
					while (low < n - 1 && nums[low] == nums[low + 1])
						low++;
					low++;
				}
			}
		}
		return result;
	}

	// leetcode closest ThreeSums

	// leetcode FourSums
}