//
// Created by ning on 2019/8/6.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//  << 算法竞赛入门经典 >>
// 11.1 节 -- 无根树转有根树

/*
 输入形式：
    8
	0 1
	0 2
	0 3
	1 4
	1 5
	5 6
	5 7
	1           -- 根编号
 * */

void dfs(vector<vector<int>> &G, vector<int> &p, int u, int fa) {
	int d = G[u].size();
	for (int i = 0; i < d; ++i) {
		const int v = G[u][i];   // u -> v
		if (v != fa)
			dfs(G, p, v, p[v] = u);
	}
}

void test11_1() {
	int n, root;
	cin >> n;
	if (n <= 1)
		return;

	vector<vector<int>> G(n);
	vector<int> p(n);   // 标明结点的父节点

	int u, v;
	n--;    // n-1条边
	while (n--) {
		cin >> u >> v;
		// 无向图
		G[u].push_back(v);
		G[v].push_back(u);
	}

	cin >> root;
	p[root] = -1;
	dfs(G, p, root, -1);
	for (int i = 0; i < n; ++i)
		cout << "p[" << i << "] = " << p[i] << endl;
}

int main() {
	test11_1();
}