//
// Created by ning on 2019/8/15.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

/*
    最长上升子序列问题 LIS
 * */

/*
    最长公共子序列问题 LCS
 * */

/*
    划分成回文串 -- 将字符串划分为回文串 / 给出最少划分次数
 * */

/*
    括号序列   -- UVa1626 // 添加最少的括号得到规整序列
 * */

/*
    切木棍 -- UVa10003 //
 * */


/*
    最优矩阵链乘
		-- 给出运算次数最少 方案 ---> 打印选择
 * */

extent int INF;

int f(vector<vector<int>> &dp, vector<int> &p, int i, int j) {
	if (dp[i][j] >= 0)
		return dp[i][j];    // 计算过
	int ans = INF;
	int t;
	// 依次分割
	for (int k = i; k < j; ++k) {
		t = f(dp, p, i, k) + f(dp, p, k + 1, j) + p[i - 1] * p[k] * p[j];
		if (t < ans)
			ans = t;
	}
	return ans;
}

void test_matrixMulti() {
	int n, t;
	cin >> n;
	vector<int> p(n + 1); // n 个矩阵维度
	for (int i = 0; i <= n; ++i) {
		cin >> t;
		p[i] = t;
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	// 自身初始化
	for (int i = 0; i <= n; ++i)
		dp[i][i] = 0;
	// 相邻矩阵初始化

	cout << "Result: " << f(dp, p, 1, n) << endl;
}

// 递推
void test_matrixMulti2() {
	int n, t;
	cin >> n;
	vector<int> p(n + 1); // n 个矩阵维度
	for (int i = 0; i <= n; ++i) {
		cin >> t;
		p[i] = t;
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int sep = 0; sep < n; ++sep) { // 区间长度 j - i
		for (int i = 1; i + sep < n; ++i) {
			int j = i + sep;
			dp[i][j] = i == j ? 0 : INF;
			for (int k = i; k < j; ++k) {
				int t = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < dp[i][j])
					dp[i][j] = t;
			}
		}
	}
	cout << "Result: " << dp[1][n] << endl;
}