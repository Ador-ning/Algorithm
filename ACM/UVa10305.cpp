//
// Created by ning on 2019/8/7.
//
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using std::vector;
using std::queue;
using std::reverse;
using std::cin;
using std::cout;
using std::endl;

// 拓扑排序
typedef vector<vector<int>> Graph;

// 3. 拓扑排序
// 题目：n个变量， m 个二元组 (u, v) -> 表示 u 小于 v  ---- 输出变量排序可能解
// 存在环则 ->无解 / DFS ->在访问完一个节点之后把它加入到当前拓扑序的首部
bool dfs(const Graph &g, int u, vector<bool> &visited, vector<int> &r) {
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (!visited[v]) {
			visited[v] = true;
			dfs(g, v, visited, r);
		}
	}
	r.push_back(u); // 将访问点加入结果集合
}

vector<int> topoSort(const Graph &g) {
	vector<int> r;
	r.reserve(g.size());
	vector<bool> visited(g.size(), false);
	for (int i = 1; i < g.size(); ++i) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(g, i, visited, r);
		} else {
			return vector<int>();
		}
	}
	reverse(r.begin(), r.end());    // 反转 -- 结果
	return r;
}

// pre 数组 节点入度数
bool topoSortBfs(const Graph &g, vector<int> &pre, vector<int> topo) {
	queue<int> q;
	for (int u = 1; u <= g.size(); ++u) {
		if (!pre[u])   // 入度为 0
			q.push(u);
	}

	while (q.size()) {
		int u = q.front(); // 起点
		q.pop();
		topo.push_back(u);
		for (int i = 0; i < g[u].size(); ++i) {
			int k = g[u][i];
			pre[k] -= 1;   // 去掉 u->k 边
			if (pre[k] == 0)
				q.push(k);
			else if (pre[k] < 0)
				return false;
		}
	}

	// print result
	for (auto item : topo)
		cout << item << ' ';
	cout << endl;

	return topo.size() == (g.size() - 1);
}

/**
 *
// 输入
5 4
1 2
2 3
1 3
1 5
5 0
0 0
// 输出
1 4 2 5 3
1 2 3 4 5			// --- 有问题吧!
 * */
void test_topo() {
	int n, m;   // n个节点 m 个二元组
	while (cin >> n >> m && n) {
		Graph g(n + 1);
		vector<int> pre(n + 1, 0);
		int i = 0;
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u, v;
			if (u == v)
				return;
			g[u].push_back(v);
			++pre[v]; // 节点入度
		}   // 处理输出

		vector<int> r = topoSort(g);    // 排序
		// 结果打印
		if (r.empty())
			cout << "Not result, has cycle";
		for (int i = 0; i < r.size(); ++i) {
			if (i % 2) {
				cout << ' ';
			}
			cout << r[i];
		}
		cout << endl;
	}
}