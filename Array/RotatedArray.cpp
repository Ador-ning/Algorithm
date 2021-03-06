//
// Created by ning on 2018/11/23.
//

#include <cstdio>
#include <exception>
#include <stdexcept>
#include <vector>
#include "problem.h"

/*
面试：
	把数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
	输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素
*/
// 查找 坐标范围内，数组最小值
int Algorithm::MinInOrder(const int numbers[], int index1, int index2) {
	int result = numbers[index1];
	if (index1 < index2) {
		for (int i = index1 + 1; i < index2; ++i) {
			if (result > numbers[i])
				result = numbers[i];
		}
		return result;
	}
}

//
int Algorithm::Min(int numbers[], int length) {
	if (numbers == NULL || length <= 0) {
		std::logic_error ex("Invalid parameters.\n");
		throw std::exception(ex);
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2]) {
		// 如果 index1 和 index2 指向相邻的两个数 ，
		// 则 index1 指向第一递增子数组的最后一个数字，
		// index2指向第二个子数组的第一个数字，也就是数组中的最小数字
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}

		// 如果下标为 index1、index2和indexMid指向的三个数字相等
		// 只能顺序查找
		int indexMid = (index2 + index1) / 2;
		if (numbers[index1] == numbers[2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		// 缩小查找范围   -> 跳过有序部分
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

// 旋转数组中查找某个数字，不存在返回 -1， 存在返回 index
int Algorithm::search(std::vector<int> &nums, int target) {
	int n = nums.size();
	if (n <= 0)
		return -1;
	if (n == 1)
		return nums[0] == target ? 0 : -1;

	int low = 0, high = n - 1;
	while (low <= high) {
		// base
		if (nums[low] < nums[high] && (target < nums[low]))
			return -1;

		// [low, high] 数字相同
		while (low < high && nums[low] == nums[high])
			low++;

		int mid = low + (high - low) / 2;
		// base
		if (nums[low] == target)
			return low;
		if (nums[high] == target)
			return high;
		if (nums[mid] == target)
			return mid;

		// target in non-rotated array s1
		if (nums[low] < nums[mid] && target >= nums[low] && target < nums[mid]) {
			high = mid - 1;
			continue;
		}

		// target in non-rotated array s2
		if (nums[mid] < nums[high] && target >= nums[mid] && target < nums[high]) {
			low = mid + 1;
			continue;
		}

		// target in rotated array s3
		if (nums[low] > nums[mid]) {
			high = mid - 1;
			continue;
		}

		// target in rotated array s4
		if (nums[mid] > nums[high]) {
			low = mid + 1;
			continue;
		}
		low++;
	}
	return -1;
}

// ====================测试代码====================
void Algorithm::Test(int *numbers, int length, int expected) {
	int result = 0;
	try {
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...) {
		if (numbers == NULL)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int Algorithm::test_rotatedArray() {
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = {3, 4, 5, 1, 2};
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = {3, 4, 5, 1, 1, 2};
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = {3, 4, 5, 1, 2, 2};
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = {1, 0, 1, 1, 1};
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = {1, 2, 3, 4, 5};
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = {2};
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入nullptr
	Test(nullptr, 0, 0);

	return 0;
}

void Algorithm::test_search() {

	std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
	std::cout << search(nums1, 0) << " " << search(nums1, 3) << std::endl;

}


// 思考旋转数组的 二分查找
// -- 考虑了 重复元素 / 递增 / 递减（没有考虑）
int Algorithm::minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.size() <= 0)
		return 0;

	int left = 0, right = rotateArray.size() - 1;
	int mid = -1;
	while (rotateArray[left] >= rotateArray[right]) {
		if (right - left == 1) {
			mid = right;
			break;
		}

		mid = left + (right - left) / 2;
		if (rotateArray[mid] >= rotateArray[left]) {
			left = mid;
		}
		if (rotateArray[mid] <= rotateArray[right]) {
			right = mid;
		}
	}

	return mid == -1 ? rotateArray[0] : rotateArray[mid];
}

