//
// Created by ning on 2019/8/7.
//


#include <iostream>
#include <algorithm>

using namespace std;

/*
无向图最小生成树：

 * */

const int maxn = 100, maxm = 6000;

// r[] p[]
int u[maxm], v[maxm], w[maxm], r[maxm], p[maxn];

int n, m;

static bool cmp(int i, int j) {
	return w[i] < w[j];
}

int find(int x) {
	// 向上查
	// 终止条件 p[x] == x ---- 标识根结点
	return p[x] == x ? x : p[x] = find(p[x]);
}

/*
 * n 个结点 / m 条边
 *      n-1 条边即可
 * */
int kruskal() {
	int ans = 0, k = 0;

	// 边号初始化
	for (int i = 0; i < m; ++i)
		r[i] = i;
	// 并查集初始化
	for (int i = 0; i < n; ++i)
		p[i] = i;

	// 对边 按权重排序
	sort(r, r + m, cmp);

	for (int i = 0; i < m; ++i) {
		int e = r[i];   // 边号

		// u 和 v 所属连通分量
		int x = find(u[e]), y = find(v[e]);
		// 在两个连通分量中
		if (x != y) {
			ans += w[e];
			++k;
			p[x] = y; // 合并分量  x 作为 y 的子节点
		}

		if (k == n - 1)
			break;
	}

	for (int i = 0; i < n; ++i)
		cout << find(i) << endl;

	return (k == n - 1) ? ans : -1;
}

/*
	5 7
	0 1 5
	0 2 1
	0 3 2
	0 4 4
	1 3 1
	2 3 5
	2 4 2
 * */
int main() {
	cin >> n >> m;
	// u v w
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", u + i, v + i, w + i);
	cout << kruskal() << endl;
}