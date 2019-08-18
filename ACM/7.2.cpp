//
// Created by ning on 2019/8/18.
//
#include <iostream>
#include <vector>

using namespace std;

// 枚举 -- 控制枚举范围

// 枚举排列     // 递归枚举 // 直接枚举

// 1. 生成 1-n 的排列
// 递归
void print_permutation(vector<int> &arr, int cur) {
	int n = arr.size();
	if (cur == n) {
		for (int i = 0; i < n; ++i)
			cout << arr[i] << ' ';
		cout << endl;
	} else {
		for (int i = 1; i <= n; ++i) {  // 1-n
			int ok = 1;
			for (int j = 0; j < cur; ++j) {
				if (arr[j] == i) {      // arr[0->cur-1] 检查是否 有 i
					ok = 0;
					break;
				}
			}

			if (ok) {   // arr[0->cur-1] 中没有 i
				arr[cur] = i;
				print_permutation(arr, cur + 1);
			}
		}
	}
}

// 2. 生成可重集的排列
// p数组 先排序 - 输入数据数组
void print_permutation2(vector<int> &p, vector<int> &a, int cur) {
	int n = p.size();
	if (cur == n) {
		for (int i = 0; i < n; ++i)
			cout << a[i] << ' ';
		cout << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			if (!i || p[i] != p[i - 1]) {
				int c1 = 0, c2 = 0;

				for (int j = 0; j < cur; ++j) {
					if (a[j] == p[i])       // 统计 a[0->cur-1] 中 p[i] 出现次数
						++c1;
				}
				for (int j = 0; j < n; ++j) {
					if (p[i] == p[j])       // 统计 p 中 p[i] 出现次数 / 可优化
						++c2;
				}
				// p[i] 可以放在 a[cur] 上
				if (c1 < c2) {
					a[cur] = p[i];
					print_permutation2(p, a, cur + 1);
				}
			}
		}
	}
}