//
// Created by ning on 2019/7/28.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// 1. 用 DFS 求连通块
// 2. 用 BFS 求最短路径
// 3. 拓扑排序
// 4. 欧拉回路

void dfs(vector<vector<char>> &data, vector<vector<int>> &tag, int r, int c, int cnt) {
	if (r < 0 || r >= data.size() || c < 0 || c >= data[0].size())
		return;
	if (tag[r][c] > 0 || data[r][c] != '@')
		return;
	tag[r][c] = cnt; // 连通分量编号

	//递归 方向
	for (int dr = -1; dr <= 1; ++dr) {
		for (int dc = -1; dc <= 1; ++dc) {
			if (dr != 0 || dc != 0)
				dfs(data, tag, r + dr, c + dc, cnt);
		}
	}
}

// 横竖 对角线方向
void oil_deposits() {
	int m, n;
	while (cin >> m >> n) {
		if (m & n)
			continue;   // 有 0
		vector<vector<char>> data(m, vector<char>(n));
		vector<char> t;
		char c;
		for (int i = 0; i < m; ++i) {
			cin >> c;
			t.push_back(c);
			data.push_back(t);
			t.clear();
		}
		vector<vector<int>> tag(m, vector<int>(n, 0));

		int cnt = 0;    // 编号
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tag[i][j] == 0 && data[i][j] == '@') {
					dfs(data, tag, i, j, ++cnt);
				}
			}
		}
		cout << cnt << endl;
	}

}