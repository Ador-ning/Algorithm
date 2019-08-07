//
// Created by ning on 2019/8/7.
//

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>


using std::vector;
using std::queue;
using std::sort;
using std::unique;
using std::lower_bound;
using std::cin;
using std::cout;
using std::endl;

// 雕塑体积/表面积计算
static int n2;
static const int maxn2 = 50 + 5;
static const int maxc = 1000 + 1;
static int x0[maxn2], y0[maxn2], z0[maxn2], x1[maxn2], y1[maxn2], z1[maxn2];
static int xs[maxn2 * 2], ys[maxn2 * 2], zs[maxn2 * 2], nx, ny, nz;
static int color[maxn2 * 2][maxn2 * 2][maxn2 * 2];
static int dx[] = {0, 0, 0, 0, -1, 1};
static int dy[] = {0, 0, -1, 1, 0, 0};
static int dz[] = {-1, 1, 0, 0, 0, 0};

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

void testSculpture() {
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