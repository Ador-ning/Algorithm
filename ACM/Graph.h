//
// Created by ning on 2019/7/28.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

#include <vector>

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


Node walk(const Node &u, int turn);

bool inside(int r, int c);

bool readCase();

void print_ans(Node u);

void solve();

void test_bfs();

// 拓扑排序
typedef vector<vector<int>> Graph;

bool dfs(const Graph &g, int u, vector<bool> &visited, vector<int> &r)

vector<int> topoSort(const Graph &g);

void test_topo();

// 欧拉回路
const int N = 100000;
vector<int> end[26];  // 26 行数组
int inAlpha[26], outAlpha[26];

void init_data();

void dfs(int u);

bool solveOla();

void testOla();

// 多叉树转括号表示法
const int maxN = 200 + 5;
char buf[maxN][maxN];

void testBrace();


// 雕塑体积/表面积计算
int n2;
const int maxn2 = 50 + 5;
const int maxc = 1000 + 1;
int x0[maxn2], y0[maxn2], z0[maxn2], x1[maxn2], y1[maxn2], z1[maxn2];
int xs[maxn2 * 2], ys[maxn2 * 2], zs[maxn2 * 2], nx, ny, nz;
int color[maxn2 * 2][maxn2 * 2][maxn2 * 2];
int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {-1, 1, 0, 0, 0, 0};

struct Cell {
	int x, y, z;

	Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

	void setVis() const {
		color[x][y][z] = 2;
	}

	int volume() const {
		return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
	}

	Cell neighbor(int i) const {
		return Cell(x + dx[i], y + dy[i], z + dz[i]);
	}

	bool valid() const {
		return x >= 0 && x < nx - 1 && y >= 0 && y < ny - 1 && z >= 0 && z < nz - 1;
	}

	bool solid() const {
		return color[x][y][z] = 1;
	}

	int area(int i) const {
		if (dx[i] != 0)
			return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
		else if (dy[i] != 0)
			return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
		else return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
	}

	bool getVis() const {
		return color[x][y][z] == 2;
	}
};

#endif //ALGORITHM_GRAPH_H
