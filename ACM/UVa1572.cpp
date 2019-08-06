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
using std::sort;
using std::unique;
using std::lower_bound;

// Self-Assembly  UVa 1752
/*
题意：
    有些种类的正方形，每条边有两个符号，‘00‘’不能与任何边相连，只有字母相同，“+-”相反才能相连，让判断是否用这些已有的正方形铺成无限大的平面
    正方形种类 < 40000 / 每种数量不限 / 正方形可以翻转 旋转
解题思路：
    将字母转化为数字 例如 A+A-转化为2n，2n+1，这样如果一个正方形x（A+）能和另一个正方形y（A-）相连，
    则正方形x每个边都能到达正方形y（A+A-连接了以后A+这个正方形就与y相连了，所以x的任一边都考可到达y）
    想判断是否能无限大，则三角形必须重复出现（
    即他们之间的连接点会重复出现，在有向图中存在环，现在只需判断是否能形成有向环，
    如已经有A+A-相连，再发现一个A+A-相连，这之间是一个重复的过程，则可以无限循环下去

 - 拓扑排序
 * */

#define maxn 52
char ss[10];
int g[maxn][maxn], visited[maxn];

// 将字母边 转化为 整数表示
int id(char a1, char a2) {
	return (a1 - 'A') * 2 + (a2 == '+' ? 0 : 1);
}


// 将配对的结点连边，为有向图建模
void connect(char a1, char a2, char b1, char b2) {
	if (a1 == '0' || b1 == '0')
		return;
	// 边的对应关系：
	// A+ <<-->> A-   所以(a1,a2)一定能和(a1,a2)^1配对连接
	// 又因为(a1,a2)与(b1,b2)存在于同一个正方形，他们两个也一定能连接
	// 所以 (a1,a2)^1 <<-->>(b1,b2)
	int u = id(a1, a2) ^1;  // 什么意思
	int v = id(b1, b2);
	g[u][v] = 1;
	g[v ^ 1][u ^ 1] = 1; // （2n + 1） ^ 1 =  2n,  (2n) ^ 1 = 2 n + 1
}

bool dfs2(int u) {
	visited[u] = -1; // 表示结点正在访问中
	for (int i = 0; i < maxn; ++i) {
		if (g[u][i]) {
			if (visited[i] == -1)
				return true;    // 重复出现点，构成有向环
			else if (!visited[i] && dfs2(i)) { // 向下递归并成功
				return true;
			}
		}
	}
	visited[u] = 1;     // 表示已经访问
	return false;
}

bool judge() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < maxn; ++i) {
		if (!visited[i]) {  // 只找到一个环即可
			if (dfs2(i))
				return true;
		}
	}
	return false;
}

void testSelfAssembly() {
	int n;
	while (cin >> n && n) {
		memset(g, 0, sizeof(g));
		while (n--) {
			cin >> ss;
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					if (i != j) {
						// 同一个正方形的变互相建立
						connect(ss[2 * i], ss[2 * i] + 1, ss[j * 2], ss[j * 2 + 1]);
					}
				}
			}

			if (judge())
				cout << "unbounded" << endl;
			else
				cout << "bounded" << endl;
		}
	}
}



