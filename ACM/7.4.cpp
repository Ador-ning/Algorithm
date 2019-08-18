//
// Created by ning on 2019/8/18.
//

#include <iostream>
#include <vector>

using namespace std;

// 回溯法   -- 递归枚举
// 选择可行行 -- 求解问题步骤 / 每个步骤的选择性

// 1. 八皇后问题 -- 数独 /

/*
	素数环     -- 1->n 组成一个环 / 使得相邻两个数之和位素数
 */
void dfs(vector<int> &a, vector<int> &vis, vector<int> &isp, int cur, int &ans) {
	int n = a.size();
	if (cur == n && isp[a[0] + a[n - 1]]) {     // 最后一个 并且检查
		++ans;
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;       // 打印一个解
	} else {
		for (int i = 2; i <= n; ++i) {  // 尝试放置每个 i
			if (!vis[i] && isp[i + a[cur - 1]]) {   // i 没有使用，并且和前一个数和位素数
				a[cur] = i;
				vis[i] = 1;     //  设置标志
				dfs(a, vis, isp, cur + 1, ans);
				vis[i] = 0;     // 清除标志
			}
		}
	}
}

void primeCycle() {
	int n;
	while (cin >> n) {
		int ok;

		// 生成 0-> n 素数表
		vector<int> isp(n + 1, 0);
		for (int i = 2; i <= (n << 1); ++i) {
			ok = 1;
			for (int j = 2; j * j < i; ++j) {
				if (i % j == 0)
					ok = 0;
			}
			if (ok)
				isp[i] = 1;
		}
		vector<int> a(n, 0), vis(n, 0);
		int ans = 0;
		dfs(a, vis, isp, 1, ans);
		cout << "Result: " << ans << endl;
	}
}