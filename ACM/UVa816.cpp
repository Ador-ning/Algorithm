//
// Created by ning on 2019/8/7.
//

#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

// 2. BFS
// 顺时针旋转
struct Node {
	int r, c, dir;

	Node(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) {}
};

const int maxn = 10;
int r0, c0, dir;
int r1, c1;
int r2, c2;
bool has_edge[maxn][maxn][4][3];
int di[maxn][maxn][4];
Node pi[maxn][maxn][4];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const char *dirs = "NESW";
const char *turns = "FLR";

int dir_id(char ch) {
	return strchr(dirs, ch) - dirs;
}

int turn_id(char ch) {
	return strchr(turns, ch) - turns;
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


