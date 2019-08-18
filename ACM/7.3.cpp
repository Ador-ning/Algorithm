//
// Created by ning on 2019/8/18.
//
#include <iostream>
#include <vector>

using namespace std;


// 3. 子集生成 --
// 思路1 -- 一次选取一个元素到集合中      // 增量构造法
void print_subset1(vector<int> &arr, int cur) {
	for (int i = 0; i < cur; ++i) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	// 不理解该代码
	int s = cur ? arr[cur - 1] + 1 : 0;     // 确定当前元素的最小可能值
	for (int i = s; i < arr.size(); ++i) {
		arr[cur] = i;
		print_subset1(arr, cur + 1);
	}
}

// 思路2 -- 构造一个位向量 B[i]  // 位向量法
void print_subset2(vector<int> &B, int cur) {
	if (cur == B.size()) {
		for (int i = 0; i < cur; ++i) {
			if (B[i])
				cout << i << ' ';       // 打印当前集合
		}
		cout << endl;
	}

	B[cur] = 1;
	print_subset2(B, cur + 1);  // 选 B[cur]
	B[cur] = 0;
	print_subset2(B, cur + 1);  // 不选 B[cur]
}

// 思路3 -- 二进制法
void print_subset3(int n, int s) {
	for (int i = 0; i < n; ++i) {
		if (s & (1 << i))
			cout << i << ' ';
	}
	cout << endl;
}

void testSubset3() {
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		print_subset3(n, i);
	}
}