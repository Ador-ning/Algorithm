//
// Created by ning on 2019/7/28.
//
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// 完全二叉树
void dropping_balls() {
	const int maxd = 20; // 层数
	int s[1 << maxd];   // 开关

	int D, I;
	while (cin >> D >> I) {
		memset(s, 0, sizeof(s));
		int k, n = (1 << D) - 1;
		for (int i = 0; i < I; ++i) {
			k = 1;
			for (;;) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;   // 掉落方向
				if (k > n)
					break;
			}
		}
		cout << k / 2;
	}
}

// 二叉树 层序遍历 / 递归遍历