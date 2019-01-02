//
// Created by ning on 2018/11/29.
//
#include "StringUtils.h"
#include "problem.h"
#include "../Base.h"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace Algorithm {

	// 反转字符串
	// reverse(s.begin(), s.end());
	void Reverse(char *pBegin, char *pEnd) {
		if (pBegin == nullptr || pEnd == nullptr)
			return;

		while (pBegin < pEnd) {
			char temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
			pBegin++;
			pEnd--;
		}
	}

	/*
	 * 功能：upper to lower and remove other character
	 * */
	void removeIgnore(std::string &s) {
		if (s.size() == 0)
			return;
		for (int i = 0; i < s.size();) {
			// upper to lower
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] -= 'A' - 'a';
				++i;
			} else if (s[i] >= 'a' && s[i] <= 'z') {
				++i;
				continue;
			} else {
				// remove
				s.erase(i, 1);
			}
		}
	}

	void test_RemoveIgnore() {
		std::string s("A man, a plan, a canal: Panama");
		std::string s1("race a car");
		removeIgnore(s);
		removeIgnore(s1);
		std::cout << s << std::endl;
		std::cout << s1 << std::endl;
	}

// 字符串排列    --- 递归
/*
 * 面试38：输入一个字符串，打印出该字符串中字符的所有排列
 */
	void Permutation(char *pStr, char *pBegin) {
		if (*pBegin == '\0')
			printf("%s\n", *pStr);
		else {
			for (char *pCh = pBegin; *pCh != '\0'; ++pCh) {
				char temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;

				Permutation(pStr, pBegin + 1);

				temp = *pCh;
				*pCh = *pBegin;
				*pBegin = temp;
			}
		}
	}

	void Permutation(char *pStr) {
		if (pStr == nullptr)
			return;
		Permutation(pStr, pStr);
	}

	void Test(char *pStr) {
		if (pStr == nullptr)
			printf("Test for nullptr.\n");
		else
			printf("Test for %s begins.\n", pStr);

		Permutation(pStr);
		printf("\n");
	}

	void test_main() {
		Test(nullptr);

		char string1[] = "";
		Test(string1);

		char string2[] = "a";
		// Test(string2);

		char string3[] = "ab";
		Test(string3);

		char string4[] = "abc";
// 指针有问题
		Test(string4);
	}

// 按单词 - 反转字符串
/*
 * 面试58：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变
 * 翻转两次 2O(n)
 * */
	char *ReverseSentence(char *pData) {
		if (pData == nullptr)
			return nullptr;

		char *pBegin = pData;
		char *pEnd = pData;

		while (*pEnd != '\0')
			pEnd++;
		pEnd--;

		// 翻转句子
		Reverse(pBegin, pEnd);

		// 翻转句子中的每一个单词
		pBegin = pEnd = pData;
		while (*pBegin != '\0') {
			if (*pBegin == ' ') {
				pBegin++;
				pEnd++;
			} else if (*pEnd == ' ' || *pEnd == '\0') {
				Reverse(pBegin, --pEnd);
				pBegin = ++pEnd;
			} else
				pEnd++;
		}
		return pData;
	}

	// leetcode  stl using
	// 输入: "Let's take LeetCode contest"
	// 输出: "s'teL ekat edoCteeL tsetnoc"
	std::string reverseWords(std::string &s) {
		if (s.size() <= 1)
			return s;

		int i = 0;
		int j = s.find(" ");
		while (j != std::string::npos) {
			reverse(s.begin() + i, s.begin() + j);
			i = j + 1;
			j = s.find(" ", i);
		}
		reverse(s.begin() + i, s.end());
		return s;
	}
}


// 等长滑动
bool checkInclusion(std::string s1, std::string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1 > n2)
		return false;

	std::vector<int> m1(128);
	std::vector<int> m2(128);

	// n1 < n2
	for (int i = 0; i < n1; ++i) {
		++m1[s1[i]];
		++m2[s2[i]];
	}

	if (m1 == m2)
		return true;
	// 窗口大小 n1 --> 右滑
	for (int i = n1; i < n2; ++i) {
		++m2[s2[i]];
		--m2[s2[i - n1]];
		if (m1 == m2)
			return true;
	}
	return false;
}

// 变长滑动
std::string minWindow(std::string s, std::string t) {

	std::unordered_map<char, int> m;
	for (auto item : t) {
		if (m.count(item))
			m[item]++;
		else
			m.insert({item, 1});
	}

	int count = t.size(); // 计数器
	int begin = 0, end = 0; // 窗口 begin -> end
	int head = 0, len = INT_MAX; // 解范围 head + len

	while (end < s.size()) {
		// 右边加，当这个字符是滑动窗缺少的字符时，计数器减一
		if (m.count(s[end])) {
			if (m[s[end++]]-- > 0)
				--count;
		} else
			end++;

		while (count == 0) {
			if (end - begin < len) {
				len = end - begin;
				head = begin;
			}

			// 左边减，当这个字符是滑动窗不缺也不富余的字符时，计数器加一
			if (m.count(s[begin])) {
				if (m[s[begin++]]++ == 0)
					++count;
			} else
				begin++;
		}
	}
	return len == INT_MAX ? "" : s.substr(head, len);
}

// leetcode -- longest common subsequence
void lcs_print(vector<vector<int>> &dp, const string &str1, const string &str2, int m, int n) {
	if (m == 0 || n == 0)
		return;

	if (dp[m][n] == 1) {
		lcs_print(dp, str1, str2, m - 1, n - 1);
		cout << str1[m - 1] << ' ';
	} else if (dp[m][n] == 2) {
		lcs_print(dp, str1, str2, m - 1, n);
	} else if (dp[m][n] == 3) {
		lcs_print(dp, str1, str2, m, n - 1);
	}
}

int lcs(string str1, string str2) {
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	vector<vector<int>> dp_print(str1.size() + 1, vector<int>(str2.size() + 1, 0));

	// 结果 + 行走路径
	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				dp_print[i][j] = 1;
			} else if (dp[i - 1][j] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				dp_print[i][j] = 2;
			} else {
				dp[i][j] = dp[i][j - 1];
				dp_print[i][j] = 3;
			}
		}
	}

	// 打印结果
	lcs_print(dp_print, str1, str2, str1.size(), str2.size());
	cout << endl;
	return dp[str1.size()][str2.size()];
}