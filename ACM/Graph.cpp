//
// Created by ning on 2019/7/28.
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
#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::string;
using std::sort;
using std::unique;
using std::lower_bound;

// 1. 用 DFS 求连通块
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

// 2. 用 BFS 求最短路径       队列 / 递归打印路径
// --- 改代码 太过于繁琐
Node walk(const Node &u, int turn) {
	int dir = u.dir;
	if (turn == 1) {
		dir = (dir + 3) % 4;
	} else if (turn == 2)
		dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

bool inside(int r, int c) {
	return r >= 0 && r <= 9 && c >= 0 && c <= 9;
}

bool readCase() {
	char s[100], s2[100];
	if (scanf("%s%d%d%s%d%d", s, &r0, &c0, s2, &r2, &c2) != 6) {
		return false;
	}
	printf("%s\n", s);
	dir = dir_id(s2[0]);
	r1 = r0 + dr[dir];
	c1 = c0 + dr[dir];
	memset(has_edge, 0, sizeof(has_edge));
	int r, c;
	while (true) {
		scanf("%d", &r);
		if (r == 0) {
			break;
		}
		scanf("%d", &c);
		while (scanf("%s", s) == 1) {
			if (s[0] == '*') {
				break;
			}
			int dir = dir_id(s[0]);
			int len = strlen(s);
			for (int i = 1; i < len; ++i) {
				int turn = turn_id(s[i]);
				has_edge[r][c][dir][turn] = true;
			}
		}
	}
	return true;
}

void print_ans(Node u) {
	vector<Node> nodes; // vector 反向打印结果
	for (;;) {
		nodes.push_back(u);
		if (di[u.r][u.c][u.dir] == 0)
			break;
		u = pi[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0, c0, dir));
	int cnt = 0;
	for (int i = nodes.size() - 1; i >= 0; --i) {
		if (cnt % 10 == 0)
			printf(" ");
		printf(" (%d, %d)", nodes[i].r, nodes[i].c);
		if (++cnt % 10 == 0)
			printf("\n");
	}
}

void solve() {
	queue<Node> q;
	memset(di, -1, sizeof(di));
	Node u(r1, c1, dir);
	di[u.r][u.c][u.dir] == 0;
	q.push(u);
	while (!q.empty()) {
		Node u = q.front();
		q.pop();
		if (u.r == r2 && u.c == c2) {
			print_ans(u);
			return;
		}
		for (int i = 0; i < 3; ++i) {
			Node v = walk(u, i);
			if (has_edge[u.r][u.c][i] && inside(v.r, v.c) &&
			    di[v.r][v.c][v.dir] < 0) {
				di[v.r][v.c][v.dir] = di[u.r][u.c][u.dir] + 1;
				pi[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf(" No Solution possible\n");
}

void test_bfs() {
	if (readCase()) {
		solve();
	}
}

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
			return vector();
		}
	}
	reverse(r.begin(), r.end());    // 反转 -- 结果
	return r;
}

// pre 数组 节点入度数
bool topoSortBfs(const Graph &g, const vector<int> &pre, vector<int> topo) {
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
			pre[k]--;   // 去掉 u->k 边
			if (pre[k] == 0)
				q.push(k);
			else if (pre[k] < 0)
				return false;
		}
	}

	// print result
	for (auto item : topo)
		cout << topo << ' ';
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

// 4. 欧拉回路
// 无向图 节点出入度条件
// 有向图 节点出入度条件
/*
题目
	输入 n 个单词， 单词可以 ( acm malform mouse) 形式 首位相同
    每个单词长度 <= 1000，输入单词可以重复
 * */
void init_data() {
	for (int i = 0; i < 26; ++i) {
		end[i].clear();
	}
	memset(inAlpha, 0, sizeof(inAlpha));
	memset(outAlpha, 0, sizeof(outAlpha));
}

void dfs(int u) {
	while (end[u].size()) {
		int len = end[u].size();
		int k = end[u][len - 1];
		end[u].resize(len - 1);
		dfs(k);
	}
}

bool solveOla() {
	//以下判断有向图的其中一个必要条件：
	//最多只能有两个点的入度不等于出度，
	//而且必须是其中一个点的出度恰好比入度大1，另一个小1
	vector<int> deg;
	int bg;
	for (int i = 0; i < 26; ++i) {
		if (inAlpha[i] || outAlpha[i])
			bg = i;
		if (inAlpha[i] != outAlpha[i])
			deg.push_back(i);
	}
	if (deg.size() == 1 || deg.size() > 2)
		return false;
	if (deg.size() == 2) {
		int i = deg[0];
		if (abs(inAlpha[i] - outAlpha[i]) != 1)
			return false;
		bg = (outAlpha[i] - inAlpha[i] == 1) ? i : deg[1];
	}

	//以下判断有向图欧拉路径的第二个必要条件：
	//图是连通的
	dfs(bg);
	for (int i = 0; i < 26; ++i) {
		if (end[i].size())
			return false;
	}
	return true;
}

void testOla() {
	int kase;
	scanf("%d", &kase);
	int n;
	while (kase--) {
		scanf("%d", &n);
		init_data();
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			int x = s[0] - 'a', y = s[s.size() - 1] - 'a';  // 单词首尾
			end[x].push_back(y);
			++inAlpha[y];
			++outAlpha[x];
		}

		if (solveOla())
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;
	}
}

// 5. 将多叉树转化为括号表示法

// 递归遍历并且输出以字符 buf[r][c] 为根的树
void dfsBrace(int r, int c, int n) {
	cout << buf[r][c] << "(";
	if (r + 1 < n && buf[r + 1][c] == '|') { // 有子树
		int i = c;
		while (i - 1 >= 0 && buf[r + 2][i - 1] == '-')
			--i;    // 左子树
		while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0') {
			if (!isspace(buf[r + 3][i])) {
				dfsBrace(r + 3, i, n);
			}
		}
	}
	cout << ")";
}

void solveBrace() {
	int n = 0;
	for (;;) {
		fgets(buf[n], maxn, stdin);
		if (buf[n][0] == '#')
			break;
		else
			++n;
	}

	cout << "(";
	if (n) {
		for (int i = 0; i < strlen(buf[0]); ++i) {
			if (buf[0][i] != ' ') {
				dfsBrace(0, i, n);
				break;
			}
		}
	}
	cout << ")" << endl;
}

void testBrace() {
	int T;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &T);
	while (T--)
		solveBrace();
}

// 6. n个长方体 组成雕塑的体积/表面积计算  / 重叠  n <= 50
// 连通 / 并查集合
// 输入 长方体 x0 y0 z0 x y z -> 坐标加方向长度    体积 x*y*z  表面积 2*(x*y + y*z + x*z)  1->500  500 * 500 % 500 -> 超时ß
// 离散化

// 对每一维进行降维
void discretize(int *x, int &n) {
	sort(x, x + n);
	n = (int) (unique(x, x + n) - x);
}

// 找到原坐标离散化
int ID(int *x, int n, int x0) {
	return (int) (lower_bound(x, x + n, x0) - x);
}

// 找出连通块 / 找出连通块个数的组成
void floodfill(int &s, int &v) {
	s = v = 0;
	Cell c;
	c.setVis();
	queue<Cell> Q;
	Q.push(c);
	while (!Q.empty()) {
		Cell now = Q.front();
		Q.pop();
		v += now.volume();  // 统计雕塑外围的总体积
		for (int i = 0; i < 6; ++i) {
			Cell next = now.neighbor(i);
			if (!next.valid())
				continue;   // 越界
			if (next.solid())
				s += now.area(i);   // 统计雕塑外围表面积
			else if (!next.getVis()) {
				next.setVis();
				Q.push(next);
			}
		}
	}
	v = maxc * maxc * maxc - v;
}

void test1() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n2;
		nx = ny = nz = 2;
		xs[0] = ys[0] = zs[0] = 0;
		xs[1] = ys[1] = zs[1] = maxc; // 存入边界
		for (int i = 0; i < n2; ++i) {
			cin >> x0[i] >> y0[i] >> z0[i];
			cin >> x1[i] >> y1[i] >> z1[i];
			x1[i] += x0[i], y1[i] += y0[i], z1[i] += z0[i]; // 换成坐标
			xs[nx++] = x0[i], xs[nx++] = x1[i];
			ys[ny++] = y0[i], ys[ny++] = y1[i];
			zs[nz++] = z0[i], zs[nz++] = z1[i]; // 存入 xs ys zs
		}

		discretize(xs, nx);
		discretize(ys, ny);
		discretize(zs, nz); // 离散化
		memset(color, 0, sizeof(color));    // 染色
		for (int i = 0; i < n2; ++i) {
			int X1 = ID(xs, nx, x0[i]), X2 = ID(xs, nx, x1[i]);
			int Y1 = ID(ys, ny, y0[i]), Y2 = ID(ys, ny, y1[i]);
			int Z1 = ID(zs, nz, z0[i]), Z2 = ID(zs, nz, z1[i]);

			// 对离散化后的坐标依次染色
			for (int x = X1; x < X2; ++x) {
				for (int y = Y1; y < Y2; ++y) {
					for (int z = Z1; z < Z2; ++z) {
						color[x][y][z] = 1;
					}
				}
			}
		}
		int s, v;
		floodfill(s, v);
		cout << s << " " << v << endl;
	}
}