//
// Created by ning on 2019/7/30.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cctype>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::string;
using std::pair;

/*
 题意：    理想路径 UVa1599
    n个点 m 条变 的无向图 / 2 <= n <= 100000    1 <= m <= 200000 / 每条边都图有颜色
    / 求结点 1 到 结点 n 的一条路径 / 经过的边数尽可能少然后颜色序的字典序最少

 思路
    BFS -- 最短路径
    带权 -- 颜色
    多解路径找最优 -- 依据颜色字典序最小 / 还是多条
 * */

#define MAXN 100000
struct node {
	int v, c;   // v 代表 edge[u] 的另一端口，c 代表该边的颜色
	node *next;
} edge[MAXN * 4 + 10];

// 存储图 -- 链表法
node *adj[MAXN + 10];
node *ecnt = edge;  // ecnt 是当前边列表的末尾

inline void addEdge(const int &u, const int &v, const int &c) {
	node *p = ++ecnt;
	p->v = v;
	p->c = c;
	p->next = adj[u]; // adj[u] 是所有以 u 为起点的链表
	adj[u] = p;
}

int dd[MAXN + 10], pathD[MAXN + 10]; //
bool visited2[MAXN + 10];
queue<int> q1;
queue<pair<int, int>> q2;

// 求以 n 为终点到各个点的最短距离 / 保存在 dd 数组中
void bfs1(int s) {
	memset(dd, 0, sizeof(dd));
	dd[s] = 1; // 终点长度为 1
	q1.push(s);
	while (!q1.empty()) {
		int u = q1.front(); // 以终点为起始点
		q1.pop();
		for (node *p = adj[u]; p != nullptr; p = p->next) {
			int v = p->v;
			if (!dd[v]) { // 未访问过
				dd[v] = dd[u] + 1;
				q1.push(v);
			}
		}
	}

}

void bfs2(int s) {
	memset(pathD, 0x3f, sizeof(pathD));
	memset(visited2, false, sizeof(visited2));

	q2.push(std::make_pair(s, 0));
	pathD[0] = 0;
	while (!q2.empty()) {
		int u = q2.front().first;
		int cy = q2.front().second;
		q2.pop();
		if (pathD[dd[1] - dd[u]] != cy || visited2[u])
			continue;
		visited2[u] = true; // 访问过 u 节点
		for (node *p = adj[u]; p != nullptr; p = p->next) {
			int v = p->v;
			int c = p->c;
			if (dd[u] != dd[v] + 1 || pathD[dd[1] - dd[v]] <= c)
				continue;
			pathD[dd[1] - dd[v]] = c;   // 标记节点 1 -> 的颜色最小值

		}

		for (node *p = adj[u]; p != nullptr; p = p->next) {
			int v = p->v;
			int c = p->c;
			// 条件变
			if (dd[u] != dd[v] + 1 || pathD[dd[1] - dd[v]] != c)
				continue;
			q2.push(std::make_pair(v, c)); // 将满足条件入队
		}
	}

	//
	--dd[1];
	int i;
	cout << dd[1] << endl;
	for (i = 1; i <= dd[1]; ++i) {
		cout << pathD[i] << (pathD[i] == dd[1] ? '\n' : ' ');
	}
}

void testIdealPath() {
	int n, m;
	int u, v, w;
	while (cin >> n >> m && n && m) {
		memset(adj, 0, sizeof(adj));
		ecnt = edge;

		// 处理输入边
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			addEdge(u, v, w);
			addEdge(v, u, w);   // 无向图
		}
		bfs1(n); // 逆向 统计所有点到终点的距离
		bfs2(1); // 正向输出结果
	}
}

