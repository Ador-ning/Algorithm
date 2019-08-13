//
// Created by ning on 2019/8/7.
//

#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <stack>
#include <utility>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 	最短路径问题
 		Dijkstra 算法 -- 单源 / 边权为正 / 同时可以有向图 无向图
			-- 二维矩阵
			-- 邻接表
			-- 优先队列
 * */

const int maxn = 1005;
int n, m;
int gD[maxn][maxn], dist[maxn], fa[maxn];
bitset<maxn> vis;
const int INF = 0x7f7f7f7f;

/**
 * 使用二维数组存储图 复杂度 o(n2)
 * */
void test_dijkstra() {
	freopen("11.4.in", "r", stdin);
	int u, v, w;
	cin >> n >> m;
	memset(gD, INF, sizeof(gD));
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		gD[u][v] = w; // DAG
		// gD[u][v] = gD[v][v] = w;
	}

	int source = 1;
	fa[source] = source;
	memset(dist, INF, sizeof(dist));
	dist[source] = 0;
	vis.reset();

	// 算法核心部分
	for (int i = 1; i <= n; ++i) {
		// 1. 在所有未标号结点中，选择 dist 值最小的结点 x
		int m = INF, x;
		for (int y = 1; y <= n; ++y) {
			if (!vis[y] && dist[y] <= m)
				m = dist[x = y];
		}
		// 2. 标记 x 结点
		vis[x] = 1;
		// 3. 从 x 出发的所有边 x->y
		// 更新 dist[y]  / 标记 y 的父节点为 x
		for (int y = 1; y <= n; ++y) {
			if (m + gD[x][y] < dist[y]) {   // m == dist[x]
				dist[y] = m + gD[x][y];
				fa[y] = x;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << "dist[" << i << "] = " << dist[i] << endl;

	/**
	 * 打印路径  从终点出发，不断顺着 dist[i] + w[i][j] == dist[j]
	 * */
	// print path1
	typedef pair<int, int> pii;
	stack<pii> s1;
	int dest = n;
	while (dest != source) {
		for (int i = 1; i <= n; ++i) {
			if (dist[i] + gD[i][dest] == dist[dest]) {
				s1.push(make_pair(i, gD[i][dest]));
				dest = i;
				break;
			}
		}
	}
	while (!s1.empty()) {
		cout << s1.top().first << "----(" << s1.top().second << ")---->";
		s1.pop();
	}
	cout << n << endl;

	/*
	 * 利用 fa 数组 打印路径
	 * */
	// print path 2
	stack<pii> s2;
	dest = n;
	while (fa[dest] != dest) {
		s2.push(make_pair(fa[dest], gD[fa[dest]][dest]));
		dest = fa[dest];
	}

	while (!s2.empty()) {
		cout << s2.top().first << "----(" << s2.top().second << ")---->";
		s2.pop();
	}
	cout << n << endl;
}

/*
 * 使用邻接表 时间复杂度优化到 o(m x logn)
 * */
void test_dijkstra2() {
	int n, m; // n 个结点 m 条边
	cin >> n >> m;
	vector<int> first(n, -1); // first[u] 保存结点 u 的第一条边的编号
	vector<int> u(m), v(m), w(m), next(m); // next[e] 表示编号为 e 的边下一条边的编号
	int ui, vi, wi;
	for (int i = 0; i < m; ++i) {
		cin >> ui >> vi >> wi;
		u[i] = ui, v[i] = vi, w[i] = wi;
		next[i] = first[u[i]];  // 插入链表     ---- 搞不懂
		first[u[i]] = i;
	}
}

/**
 *
 *
 * */
struct Edge {
	int from, to, dist;

	Edge(int u, int v, int w) : from(u), to(v), dist(w) {}
};

struct HeapNode {
	int d, u;

	bool operator<(const HeapNode &rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<vector<int>> G;  // 保存 边的编号
	vector<bool> done;  // 是否已永久标记
	vector<int> d;      // s 到各个点的距离
	vector<int> p;      // 最短路中的上一条弧

	void init(int n) {
		this->n = n;
		G.resize(n);
		edges.clear();
		done.resize(n, false);
		d.resize(n);
		p.resize(n);
	}

	void AddEdge(int u, int v, int w) {
		edges.push_back(Edge(u, v, w));
		m = edges.size();
		G[u].push_back(m - 1);
	}

	void Dijkstra(int s) {
		priority_queue<HeapNode> q; // 按 d 排序
		for (int i = 0; i < n; ++i) {
			d[i] = INF;
		}
		d[s] = 0;
		q.push((HeapNode) {0, s}); // dist == 0  source == s
		while (!q.empty()) {
			HeapNode x = q.top();
			q.pop();
			int u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); ++i) {
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					q.push((HeapNode) {d[e.to], e.to});
				}
			}
		}
	}
};