//
// Created by ning on 2019/8/7.
//

#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

// 欧拉回路
const int N = 100000;
vector<int> end[26];  // 26 行数组
int inAlpha[26], outAlpha[26];



// 4. 欧拉回路
// 无向图 节点出入度条件
// 有向图 节点出入度条件
/*
题目
	输入 n 个单词， 单词可以 ( acm malform mouse) 形式 首位相同
    每个单词长度 <= 1000，输入单词可以重复
 * */
void init_data() {
	for (int i = 0; i < 26; ++i) {
		end[i].clear();
	}
	memset(inAlpha, 0, sizeof(inAlpha));
	memset(outAlpha, 0, sizeof(outAlpha));
}

void dfs(int u) {
	while (end[u].size()) {
		int len = end[u].size();
		int k = end[u][len - 1];
		end[u].resize(len - 1);
		dfs(k);
	}
}

bool solveOla() {
	//以下判断有向图的其中一个必要条件：
	//最多只能有两个点的入度不等于出度，
	//而且必须是其中一个点的出度恰好比入度大1，另一个小1
	vector<int> deg;
	int bg;
	for (int i = 0; i < 26; ++i) {
		if (inAlpha[i] || outAlpha[i])
			bg = i;
		if (inAlpha[i] != outAlpha[i])
			deg.push_back(i);
	}
	if (deg.size() == 1 || deg.size() > 2)
		return false;
	if (deg.size() == 2) {
		int i = deg[0];
		if (abs(inAlpha[i] - outAlpha[i]) != 1)
			return false;
		bg = (outAlpha[i] - inAlpha[i] == 1) ? i : deg[1];
	}

	//以下判断有向图欧拉路径的第二个必要条件：
	//图是连通的
	dfs(bg);
	for (int i = 0; i < 26; ++i) {
		if (end[i].size())
			return false;
	}
	return true;
}

void testOla() {
	int kase;
	cin >> kase;
	int n;
	while (kase--) {
		cin >> n;
		init_data();
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			int x = s[0] - 'a', y = s[s.size() - 1] - 'a';  // 单词首尾
			end[x].push_back(y);
			++inAlpha[y];
			++outAlpha[x];
		}

		if (solveOla())
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;
	}
}