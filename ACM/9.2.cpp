//
// Created by ning on 2019/8/13.
//
#include <iostream>
#include <vector>

using namespace std;

/*
	题目： 矩形嵌套问题  n 个矩形， a b 表示矩形的长宽 / 嵌套规则
        任务 - 选出尽可能多的矩形排成一行，使得除了最后一个之外
        每个矩形都可以嵌套在下一个矩形内/ 输出矩形编号
	输入用例
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2
 * */

int dp(vector<vector<int>> &G, vector<int> &d, int i) {
	int &ans = d[i];
	if (ans > 0)
		return ans;
	ans = 1;
	for (int j = 0; j < G.size(); ++j) {
		if (G[i][j])
			ans = max(ans, dp(G, d, j) + 1);    // 递推公式
	}
	return ans;
}

// 路径打印
void print_ans(vector<vector<int>> &G, vector<int> &d, vector<int> &a, vector<int> &b, int i) {
	cout << (i + 1) << "( " << a[i] << ", " << b[i] << ") ";
	// 多个解 ？？
	for (int j = 0; j < G.size(); ++j) {
		if (G[i][j] && d[j] + 1 == d[i])    // 转移方程
			print_ans(G, d, a, b, j);
	}
}

// 打印所有路径
void print_all(vector<vector<int>> &G, vector<int> &d, vector<int> &path, int cur, int i) {
	path[cur] = i;
	if (d[i] == 1) {
		for (int j = 0; j <= cur; ++j)
			cout << path[j] << " ";
		cout << endl;
	}

	for (int j = 0; j < G.size(); ++j) {
		if (G[i][j] && d[i] == d[j] + 1)
			print_all(G, d, path, cur + 1, j);
	}
}

void test_online() {
	int n, ai, bi;
	cin >> n;
	// 输入处理
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> ai >> bi;
		a[i] = ai, b[i] = bi;
	}

	// 建立图
	vector<vector<int>> G(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// 合并条件    第 i 和 第 j 个矩形
			if ((a[i] > a[j] && b[i] > b[j]) || (a[i] > b[j] && b[i] > a[j])) {
				G[i][j] = 1;
			}
		}
	}

	int ans = -1, t, s;
	vector<int> d(n, 0);    // dp 数组
	for (int i = 0; i < n; ++i) {
		t = dp(G, d, i);
		if (ans < t) {
			ans = t;
			s = i;
		}
	}

	cout << "Result: " << ans << endl;
	cout << "print one path: ";
	print_ans(G, d, a, b, s);
	cout << endl;

	cout << "print all paths: " << endl;
	vector<int> path(n, 0);
	print_all(G, d, path, 0, s);
}

/*
	题目：硬币问题
有 n 种硬币，面值分别为 V1, V2, ...  每种有无限多
给定非负整数 S， 可以选择用多个硬币，使得面值之和恰好为 S
	-- 输出硬币数目的最大值 / 最小值  /// 无解？？
	-- 1 <= n <= 100 / 0 <= S <= 10000 /  1 <= Vi <= S

数据用例：
    3 6
    1
    2
    3
 * */

// 常规解
void print_ans(vector<int> &v, vector<int> &d, int s) {
	while (s) {
		cout << d[s] << " ";
		s -= v[d[s]];
	}
}

void test_coins() {
	int n, S, t;
	cin >> n >> S;
	vector<int> v(n), min(S + 1), max(S + 1);
	vector<int> max_coin(S + 1), min_coin(S + 1);   // 打印路径
	for (int i = 0; i < n; ++i) {
		cin >> t;
		v[i] = t;
	}
	const int inf = 123456789;
	max[0] = min[0] = 0;
	for (int i = 1; i <= S; ++i) {
		min[i] = inf, max[i] = -inf;
	}

	// 背包问题
	for (int i = 1; i <= S; ++i) {  // 包容量
		// 遍历重量
		for (int j = 0; j < n; ++j) {
			// 可以选择 V[j]
			if (v[j] <= i) {
				if (min[i - v[j]] + 1 < min[i]) {
					min[i] = min[i - v[j]] + 1;
					min_coin[i] = j; //
				}
				if (max[i - v[j]] + 1 > max[i]) {
					max[i] = max[i - v[j]] + 1;
					max_coin[i] = j; //
				}
			}
		}
	}
	cout << "Max Value : " << max[S] << endl;
	cout << "Choice Path: ";
	print_ans(v, max_coin, S);
	cout << endl;
	cout << "Min Value : " << min[S] << endl;
	cout << "Choice Path: ";
	print_ans(v, min_coin, S);
	cout << endl;
}


// 记忆化搜索方法  -- mind 数组无用 / 没有存结果
int dpMin(vector<int> &v, vector<int> &mind, int s) {
	int &ans = mind[s];
	if (ans != -1)
		return ans;
	ans = 1 << 30;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] <= s)
			ans = min(ans, dpMin(v, mind, s - v[i]) + 1); //
	}
	return ans;
}

void test_coins2() {
	int n, S, t;
	cin >> n >> S;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		v[i] = t;
	}

	vector<int> mind(S + 1, -1);
	mind[0] = 0;
	cout << "Min Value" << dpMin(v, mind, S) << endl;

}
