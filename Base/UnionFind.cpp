//
// Created by ning on 2018/12/6.
//

#include <cassert>
#include <vector>
#include <iostream>
#include "UnionFind.h"


// leetcode 朋友圈
void test_UnionFind() {
	std::vector<std::vector<int>> in_data = {
			{1, 1, 1},
			{1, 1, 1},
			{1, 1, 1}
	};

	int n = in_data.size();

	UnionFind t(n);

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) { // 遍历上三角
			if (in_data[i][j] == 1) {
				t.addUnion(i, j); // i, j --> 0 --> n-1 编号问题
			}
		}
	}
	std::cout << t.size() << std::endl;
}

// leetcode 冗余连接 100%
std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
	int n = edges.size();

	UnionFind t(n);

	for(int i = 0; i < n; ++i){
		t.addUnion(edges[i][0], edges[i][1]);
	}

	auto res = t.getMore();
	return res.back();
}