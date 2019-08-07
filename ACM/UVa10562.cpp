//
// Created by ning on 2019/8/7.
//

#include <vector>
#include <iostream>
#include <cstring>


using std::cout;
using std::cin;
using std::endl;


// 多叉树转括号表示法
const int maxN = 200 + 5;
char buf[maxN][maxN];

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
		fgets(buf[n], maxN, stdin);
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
	fgets(buf[0], maxN, stdin);
	sscanf(buf[0], "%d", &T);
	while (T--)
		solveBrace();
}