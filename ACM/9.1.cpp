//
// Created by ning on 2019/8/13.
//

#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
/*
    测试数据：
4
1
3 2
4 10 1
4 3 2 20
 * */

/*
    回溯解决 -- 递归
 * */
void trace(vector<vector<int>> &data, int x, int y, int s, int &ans, int &cnt) {
	if (x == data.size() - 1) { // 最后一行
		if (s > ans)
			ans = s;
		++cnt;
		return;
	}
	trace(data, x + 1, y, (s + data[x + 1][y]), ans, cnt);
	trace(data, x + 1, y + 1, (s + data[x + 1][y + 1]), ans, cnt);
}

void test_trace() {
	int n, t;
	cin >> n;
	vector<vector<int>> data(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> t;
			data[i][j] = t;
		}
	}

	int ans = 0, cnt = 0;
	trace(data, 0, 0, data[0][0], ans, cnt);
	cout << "Result: " << ans << " " << cnt << " routines in total." << endl;
}

/*
 *  记忆化搜索
 * */

int f(vector<vector<int>> &d, vector<vector<int>> &a, int i, int j) {
	if (a[i][j] >= 0)
		return a[i][j];
	return a[i][j] = d[i][j] + (i == a.size() - 1 ? 0 : max(f(d, a, i + 1, j + 1), f(d, a, i + 1, j)));
}

void test_memorize() {
	int n, t;
	cin >> n;
	vector<vector<int>> data(n, vector<int>(n));
	vector<vector<int>> a(n, vector<int>(n, -1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> t;
			data[i][j] = t;
		}
	}
	cout << f(data, a, 0, 0) << endl;
}

/*
 * 递归计算
 * */
int f1(vector<vector<int>> &d, int i, int j) {
	if (i == d.size() - 1)
		return d[i][j];
	return max(f1(d, i + 1, j), f1(d, i + 1, j + 1)) + d[i][j];
}

int df(vector<vector<int>> &d, int i, int j) {
	return d[i][j] + (i == d.size() - 1 ? 0 : max(df(d, i + 1, j), df(d, i + 1, j + 1)));
}

void test_Digui() {
	int n, t;
	cin >> n;
	vector<vector<int>> data(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> t;
			data[i][j] = t;
		}
	}
	cout << "Result: " << df(data, 0, 0) << endl;
}

/**
 * 递推计算 	-- 动态规划
 * */
void test_DiTui() {
	int n, t;
	cin >> n;
	// 空间优化 f
	vector<vector<int>> a(n, vector<int>(n, 0)), f(n, vector<int>(n, 0));

	// 输入前 n-1 行
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < i; ++j) {
			cin >> t;
			a[i][j] = t;
		}
	}
	// 最后一行 / 边界处理
	for (int i = 0; i < n; ++i) {
		cin >> t;
		f[n][i] = a[n][i] = t;
	}

	for (int i = n - 2; i >= 0; --i) { // 倒数第二行向上
		for (int j = 0; j < i; ++j) {
			f[i][j] = a[i][j] + max(f[i + 1][j], f[i + 1][j + 1]); // 递归公式
		}
	}
	cout << "Result: " << f[0][0] << endl;
}
