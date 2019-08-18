//
// Created by ning on 2019/8/17.
//

#include <iostream>
#include <vector>

using namespace std;

// 1. 归并排序  -- 二路归并
/*
	划分问题    - 把序列分成元素个数尽量相同的两部分
	递归求解    - 把两个部分元素分别排序 --> 递归继续划分到临界 / 然后返回合并
	合并问题    - 将两个有序表合并成一个
 */

void mergeSort(vector<int> &data, vector<int> &t, int l, int r) {
	// 边界条件
	if (l + 1 < r) {
		// 1. 划分
		int m = l + (r - 1) / 2;

		// 2. 递归求解
		mergeSort(data, t, l, m);
		mergeSort(data, t, m, r);

		// 3. 合并
		int p = l, q = m, i = l;
		while (p < m || q < r) { // 边界处理
			if (q >= r || (p < m && data[p] <= data[q]))
				t[i++] = data[p++];
			else
				t[i++] = data[q++];
		}
		for (int i = l; i < r; ++i)
			data[i] = t[i];
	}
}

// -- 延伸问题 ---- 逆序对问题  i < j 但是 Ai > Aj  n <= 1000000 // 分治解决
void countReverse(vector<int> &arr, vector<int> &t, int l, int r, int &ans) {
	if (l + 1 < r) {
		int m = l + (r - 1) / 2;

		// 递归
		countReverse(arr, t, l, m, ans);
		countReverse(arr, t, m, r, ans);

		int p = l, q = m, i = l;
		while (p < m || q < r) {
			if (q >= r || (p < m && arr[p] <= arr[q]))
				t[i++] = arr[p++];
			else {
				t[i++] = arr[q++];
				ans += m - p;   // arr[p->m] > arr[q]
			}
		}
		for (int j = l; j < r; ++j) {
			arr[j] = t[j];
		}
	}
}

// 2. 快排问题
/*
    分治思想
划分  - 把数组的各个元素重排后分成左右两个部分 / 左边的任意元素 <= 右边的任意元素
递归求解 - 把左右两部分分别排序
合并问题 - 不用合并
 */

void Qsort(vector<int> &arr, int low, int high) {
	if (high <= low)
		return;

	int i = low;
	int j = high + 1;    // --j
	int key = arr[low];  // ++i
	while (true) {
		// 从左向右找比key大的值
		while (arr[++i] < key) {
			if (i == high) {
				break;
			}
		}
		// 从右向左找比key小的值
		while (arr[--j] > key) {
			if (j == low) {
				break;
			}
		}
		if (i >= j)
			break;
		swap(arr[i], arr[j]);
	}

	// 中枢值与j对应值交换
	swap(arr[j], arr[low]);
	Qsort(arr, low, j - 1);
	Qsort(arr, j + 1, high);
}

// 3. 二分查找
int bSearch(vector<int> &arr, int l, int r, int target) {
	int m;
	while (l < r) {
		m = l + (r - 1) / 2;
		if (arr[m] == target)
			return m;
		if (arr[m] > target)
			r = m;      // 左闭右开区间
		else
			l = m + 1;
	}
	return -1;
}

// 左
int lower_bound(vector<int> &arr, int l, int r, int target) {
	int m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (arr[m] >= target)       //  等号      左侧移动
			r = m;
		else
			l = m + 1;
	}
	return l;
}

// 右
int upper_bound(vector<int> &arr, int l, int r, int target) {
	int m;
	while (l < r) {
		m = l + (r - 1) / 2;
		if(arr[m] <= target)    //     右侧移动
			l = m+1;
		else
			r = m;
	}
	return l;
}
