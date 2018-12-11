//
// Created by ning on 2018/12/6.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H

#include <vector>
#include <cassert>

class UnionFind {
public:
	UnionFind(int n) {
		// 初始化
		UnionTable_.resize(n, -1);
	}

	// 合并
	void addUnion(int i, int j) {
		// 仅两单个
		if (UnionTable_[i] < 0 && UnionTable_[j] < 0) {
			UnionTable_[i] += UnionTable_[j];
			UnionTable_[j] = i;
		} else {
			int iFind = find(i);
			int jFind = find(j);

			// 同一个
			if (iFind == jFind)
				return;

			UnionTable_[iFind] += UnionTable_[jFind];
			UnionTable_[jFind] = iFind;
		}
	}

	// 查找
	int find(int j) {
		assert(j >= 0);
		while (UnionTable_[j] >= 0) {
			j = UnionTable_[j];
		}
		return j;
	}

	// 结果
	int size() {
		int count = 0;
		for (int i = 0; i < UnionTable_.size(); ++i) {
			if (UnionTable_[i] < 0)
				++count;
		}
		return count;
	}

	void debug() {
		for (int i = 0; i < UnionTable_.size(); ++i)
			std::cout << UnionTable_[i] << ' ';
	}

private:
	std::vector<int> UnionTable_;
};


void test_UnionFind();

#endif //ALGORITHM_UNIONFIND_H
