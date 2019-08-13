//
// Created by ning on 2019/8/12.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
    最短路径 -- 负权存在    / 如果最短路径存在，一定存在一个不含环的最短璐
        Bellman-Ford 算法

    环则有 零环 / 正环 / 负环


 * */

extern const int INF;

void test_BellmanFord() {
	const int maxn = 50, maxm = 100;
	int next[maxm], first[maxn], dist[maxn];
	int u[maxm], v[maxm], w[maxm];
	int n, m, ui, vi, wi;
	cin >> n >> m;
	if (n > maxn || m > maxm)
		return;
	for (int i = 1; i <= m; ++i) {
		cin >> ui >> vi >> wi;
		u[i] = ui, v[i] = vi, w[i] = wi;
		next[i] = first[u[i]];  // 不明白
		first[u[i]] = i;
	}

	memset(dist, INF, sizeof(dist));
	int source = 1;
	for (int k = 1; k < n; ++k) {   // 迭代 n - 1 次
		for (int i = 1; i <= m; ++i) {  // 检查每条边
			int x = u[i], y = v[i];
			if (dist[x] < INF && dist[x] + w[i] < dist[y])
				dist[y] = dist[x] + w[i];
		}
	}

	for (int i = 1; i <= m; ++i) {
		int x = u[i], y = v[i];
		if (dist[x] < INF && dist[x] + w[i] < dist[y]) {
			cout << "Negative acyclic graph" << endl;
			break;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << "dist[" << i << "] = " << dist[i] << endl;
	}
}