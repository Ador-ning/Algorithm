//
// Created by ning on 2019/8/14.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


// 物品无限背包 -- 要求在容积为 C 条件下 最重重量
void test_package1() {
	int n, C, t, c;
	cin >> n >> C;      // C 为容量
	vector<int> v(n), w(n);     // 体积 + 重量
	for (int i = 0; i < n; ++i) {
		cin >> t >> c;
		v[i] = t, w[i] = c;
	}

	vector<int> f(C + 1, 0);
	for (int i = 1; i <= C; ++i) {          // 背包容量
		for (int j = 0; j < n; ++j) {       // 物品编号
			if (i >= v[j] && f[i - v[j]] + w[j] > f[i])
				f[i] = f[i - v[j]] + w[j];  // 更新重量
		}
	}
	cout << "Result : " << f[C] << endl;
}

// 0-1背包  每种物品只有一个
void test_package() {
	int n, C, t, c;
	cin >> n >> C;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> t >> c;
		v[i] = t, w[i] = c;
	}

	// n+1 行 C+1 列
	// 多阶段
	vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= C; ++j) {
			dp[i][j] = dp[i - 1][j]; // 不选 第 i-1 个 物体 (0 开始编号)
			// 状态转移方程 选条件
			if (j > v[i - 1] && dp[i - 1][j - v[i - 1]] + w[i - 1])
				dp[i][j] = dp[i - 1][j - v[i - 1]] + w[i - 1];  // 打印路径
		}
	}
	cout << "Result: " << dp[n][C] << endl;
}

// 滚动数组 -- 根据状态依赖情况 优化内存空间