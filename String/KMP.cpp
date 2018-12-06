//
// Created by ning on 2018/7/18.
//

#include <iostream>
#include <string>
#include "problem.h"
#include "../Base.h"

using namespace std;

void compute_prefix(const std::string &pattern, std::vector<int> &next) {
	int i, j = -1;

	const int m = pattern.size();

	next[0] = j;

	for (i = 1; i < m; ++i) {

		// 如果下一个不同，那么 j 就变成 next[j]，注意next[j]是小于j的，无论j取任何值。
		while (j > -1 && pattern[j + 1] != pattern[i])
			j = next[j]; // 往前回溯

		// 相同
		if (pattern[i] == pattern[j + 1])
			j++;

		// 相同的最大前缀和最大后缀长, 赋给next[i]
		next[i] = j;
	}

	if (DEBUG) {
		auto it = next.begin();
		Print(it, next.end());
		Line();
	}
}

int kmp(const std::string &text, const std::string &pattern) {
	int i = 0;
	int j = -1; // 已经匹配字符数量

	const int n = text.size();
	const int m = pattern.size();

	// "" ""
	if (n == 0 && m == 0)
		return 0;
	// "abn" ""
	if (m == 0)
		return 0;

	// next 数组
	std::vector<int> next(m, 0);
	compute_prefix(pattern, next);

	for (; i < n; ++i) {
		// 失去匹配，查 next 表
		// while changed j, then check again.
		while (j > -1 && pattern[j + 1] != text[i]) {
			j = next[j];
			if (DEBUG) {
				std::cout << "i: " << i << ' ' << "changed j: " << j;
				Line();
			}
		}
		// 匹配
		if (text[i] == pattern[j + 1])
			j++;
		// 匹配完成
		if (j == m - 1)
			return i - j;
	}
	return -1;
}

void test_kmp() {
	const std::string text = "ABC ABCDAB ABCDABCDABDE";
	const std::string pattern = "ABCDABD";

	std::cout << kmp(text, pattern) << std::endl;

}

