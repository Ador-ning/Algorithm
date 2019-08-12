//
// Created by ning on 2019/8/7.
//

#include <cstdio>
#include <cstring>
#include <cctype>

/*
 表达式树：
    二叉树处理表达式        // 难点 - 找到根

 * */

#define maxn 10000

int cnt;
int lc[maxn], rc[maxn];
char data[maxn], str1[maxn];


/**
 * 构建表达式树
 * */
int build(int l, int r) {
	int op1 = 0, op2 = 0, flag = 0;

	// 只有一个字符
	if (l + 1 == r) {
		int u = ++cnt;
		data[u] = str1[l];
		lc[u] = rc[u] = 0;
		return u;
	}

	// 从左到右找最后计算的 operator
	// 遇到左括号 ++flag
	// 遇到右括号 --flag

	for (int i = l; i < r; ++i) {
		switch (str1[i]) {
			case '(':
				++flag;
				break;
			case ')':
				--flag;
				break;
			case '+': // 遇 + -  如果 flag != 0 不处理 / 否则 op1 = this operator
			case '-':
				if (!flag)
					op1 = i;
				break;
			case '*':
			case '/':
				if (!flag)
					op2 = i;
				break;
		}
	}

	if (!op1)
		op1 = op2; // 若没有加减，则用乘除
	if (!op1)
		build(l + 1, r - 1);

	// 连乘除都没有，则整个表达式两端是括号，所以+-* /被忽略了，递归处理内层
	int u = ++cnt;
	data[u] = str1[op1];
	lc[u] = build(l, op1);
	rc[u] = build(op1 + 1, r);
	return u;
}

void in_order_visit(int u) {
	if (!u)
		return;
	if ((data[u] == '*' || data[u] == '/') && (data[lc[u]] == '+' || data[lc[u]] == '-')) {
		printf("(");
		in_order_visit(lc[u]);
		printf(")");
	} else
		in_order_visit(lc[u]);
	printf("%c", data[u]);

	if ((data[u] == '*' || data[u] == '/') && (data[rc[u]] == '+' || data[rc[u]] == '-')) {
		printf("(");
		in_order_visit(rc[u]);
		printf(")");
	} else if (data[u] == '-' && (data[rc[u]] == '-' || data[rc[u]] == '+')) {
		if (data[rc[u]] == '-') data[rc[u]] = '+';
		else data[rc[u]] = '-';
		in_order_visit(rc[u]);
	} else
		in_order_visit(rc[u]);
}

double calc(int u) {
	if (!u)
		return 0;
	if (isdigit(data[u]))
		return data[u] - '0';
	double c1, c2, ans;
	c1 = calc(lc[u]);
	c2 = calc(rc[u]);
	const char &o = data[u];
	switch (o) {
		case '+':
			ans = c1 + c2;
			break;
		case '-':
			ans = c1 - c2;
			break;
		case '*':
			ans = c1 * c2;
			break;
		case '/':
			ans = c1 / c2;
			break;
	}

	return ans;
}

int main() {
	scanf("%s", str1);
	cnt = 0;
	memset(lc, 0, sizeof(lc));
	memset(rc, 0, sizeof(rc));
	int root = build(0, strlen(str1));  // 左开右闭区间

	// 中序遍历
	in_order_visit(root);

	printf("%.2f\n", calc(root));
}