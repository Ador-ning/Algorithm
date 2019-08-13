//
// Created by ning on 2019/8/12.
//

#include <cstdio>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

extern const int INF;

/**
	Floyd 算法  // 求出每两点之间的最短路径
 			// 不必调用 n 次 Dijkstra 或者 Bellman-ford


 * */

/*
5 6
1 2 23
1 3 17
1 5 49
2 3 5
2 4 13
4 5 7
*/
void test_floyd() {
	int n, m;
	cin >> n >> m;
	int d[n + 1][n + 1];

	// 初始化
	memset(d, INF, sizeof(d));
	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;

	int u, v, w;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		d[u][v] = w;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				/*
				 d[i][j] = d[i][j] || (d[i][k] && d[k][j]);     // 无权
				 * */
				if (d[i][k] < INF && d[k][j] < INF) {
					d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << "d[1][" << i << "] = " << d[1][i] << endl;
}