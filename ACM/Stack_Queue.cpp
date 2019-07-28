//
// Created by ning on 2019/7/28.
//
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <cstdio>
#include "Stack_Queue.h"

using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::endl;


/*
 * 矩阵链乘
 * */
void MatrixMulti() {
	stack<Matrix> s;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		int k = name[0] - 'A';
		cin >> m[k].a >> m[k].b;    // 输入维度
	}

	string expr;    // A(BC)  (AB)C
	while (cin >> expr) {
		int len = expr.size();
		bool error = false;
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			if (isalpha(expr[i]))
				s.push(m[expr[i] - 'A']);
			else if (expr[i] == ')') {
				Matrix m2 = s.top();
				s.pop();
				Matrix m1 = s.top();
				s.pop();
				if (m1.b != m2.a) {
					error = true;
					break;
				}
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a, m2.b));
			}
			if (error)
				cout << "error" << endl;
			else
				cout << ans << endl;
		}
	}
}


void rails() {
	const int maxn = 1000 + 10;
	int n, target[maxn];

	// A -- 火车进站顺序
	// B -- 火车出战顺序
	while (cin >> n) {
		stack<int> s;
		int A = 1, B = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> target[i];
		}

		int ok = 1;
		while (B <= n) {
			if (A == target[B]) {
				++A;
				++B; // 相同
			} else if (!s.empty() && s.top() == target[B]) {
				s.pop();
				++B;    // 同栈顶
			} else if (A <= n)
				s.push(A++); // 都不同 继续入栈
			else {
				ok = 0;
				break;
			}
			cout << (ok ? "Yes" : "No");
		}
	}
}

// This_is_a_[Beiju]_text -> BeijuThis_is_a_text
// 重点是 数组移动费时
void broken_Keyboard() {
	const int maxn = 100000 + 5;
	int last, cur, next[maxn];
	char s[maxn];

	while (scanf("%s", s + 1) == 1) {
		int n = strlen(s + 1);
		last = cur = 0;
		next[0] = 0;
		for (int i = 1; i <= n; ++i) {
			char ch = s[i];
			if (ch == '[')
				cur = 0;
			else if (ch == ']')
				cur = last;
			else {
				next[i] = next[cur];
				next[cur] = i;
				if (cur == last)
					last = i;
				cur = i;

			}
		}
		for (int i = next[0]; i != 0; i = next[i]) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
}