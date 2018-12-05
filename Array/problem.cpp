//
// Created by ning on 2018/12/4.
//

#include "problem.h"
#include <vector>


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
}