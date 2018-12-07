//
// Created by ning on 2018/12/6.
//

#ifndef ALGORITHM_INTERVALTREE_H
#define ALGORITHM_INTERVALTREE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string>
#include <limits.h>
#include "../Base.h"

typedef struct node_t {
	int right, left; // 区间
	int max, min; // 本区间里的最大值 / 最小值
} node_t;

int A[MAXN]; // 输入数据， 0 位置未用

// 完全二叉树
node_t node[MAXN * 4];

int minx, maxx; // 存放查询结果

void init() {
	memset(node, 0, sizeof(node));
}

// t 为根结点，区间 [l, r] 建立线段树
void build(int t, int l, int r) {
	node[t].left = l;
	node[t].right = r;
	if (l == r) {
		node[t].max = node[t].min = A[l];
		return;
	}

	const int mid = (l + r) / 2;
	build(LL(t), l, mid);
	build(RR(t), mid + 1, r);
	node[t].max = Max(node[LL(t)].max, node[RR(t)].max);
	node[t].min = Min(node[LL(t)].min, node[RR(t)].min);
}

// 查询根结点为 t, 区间为 A[l, r] 的最大值/最小值
void query(int t, int l, int r) {
	if (node[t].left == l && node[t].right == r) {
		if (maxx < node[t].max)
			maxx = node[t].max;
		if (minx < node[t].min)
			minx = node[t].min;
		return;
	}

	const int mid = (node[t].left + node[t].right) / 2;
	if (l > mid) {
		query(RR(t), l, r);
	} else if (r <= mid) {
		query(LL(t), l, r);
	} else {
		query(LL(t), l, mid);
		query(RR(t), mid + 1, r);
	}
}

void test_IntervalTree() {
	int n, q, i;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%d", &A[i]);
	init();
/* 􏷢􏼌􏳘 tree[1] 􏵌􏸆􏶝􏷾􏳒􏷹􏷺􏵌 A[1,n] 􏳅􏷂􏷰􏷈 */ build(1, 1, n);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		maxx = 0;
		minx = INF;
		query(1, a, b); /* 􏶉􏸗􏷹􏷺 A[a,b] 􏳅􏲝􏴕􏺭􏵣􏲝􏶲􏺭 */ printf("%d\n", maxx - minx);
	}
}

#endif //ALGORITHM_INTERVALTREE_H
