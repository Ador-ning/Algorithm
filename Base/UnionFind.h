//
// Created by ning on 2018/12/6.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H

#include <stdlib.h>

typedef struct ufs_t {
	int *p;    // 树的双亲表示法
	int size; // 大小
} ufs_t;

// 创建并查集
ufs_t ufs_create(int n) {
	ufs_t *ufs = (ufs_t *) malloc(sizeof(ufs_t));
	int i;
	ufs->p = (int *) malloc(n * sizeof(int));
	for (i = 0; i < n; ++i)
		ufs->p[i] = -1;
	ufs->size = n;
	return ufs;
}

// 销毁并查集合
void ufs_destroy(ufs_t *ufs) {
	free(ufs->p);
	free(ufs);
}

// 查找
int ufs_find(ufs_t *ufs, int x) {
	// 终止条件
	if (ufs->p[x] < 0)
		return x;
	// 回溯时的压缩路径
	return ufs->p[x] = ufs_find(ufs, ufs->p[x]);
}

// 查找
static int ufs_find_naive(ufs_t *ufs, int x) {
	while (ufs->p[x] >= 0) {
		x = ufs->p[x];
	}
	return x;
}

static int ufs_find_iterative(ufs_t *ufs, int x {
	int oldx = x;
	while (ufs->p[x] >= 0)
		x = ufs->p[x];

	while (oldx != x) {
		int temp = ufs->p[oldx];
		ufs->p[oldx] = x;
		x = temp;
	}
	return x;
}

// union 操作, 将 y 并入到 x
int ufs_union(ufs_t *ufs, int x, int y) {
	const int rx = ufs_find(ufs, x);
	const int ry = ufs_find(ufs, y);

	if (rx == ry)
		return -1;

	ufs->p[rx] += ufs->p[ry];
	ufs->p[ry] = rx;
	return 0;
}

// 获取元素所在集合的大小
int ufs_set_size(ufs_t *ufs, int x) {
	const int rx = ufs_find(ufs, x);
	return -ufs->p[rx];
}

#endif //ALGORITHM_UNIONFIND_H
