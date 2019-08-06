//
// Created by ning on 2019/7/30.
//

#include <bits/stdc++.h>

using namespace std;

/**
 题目：
		软件系统安装 移除 过程
 * */

// 将组件名称转化成整数
unordered_map<string, int> trans;
// 存储所有组件名
vector<string> words;
// 存储所有组件之间的依赖关系
vector<vector<int>> graph;
// 组件的安装属性 显示 / 隐式依赖
vector<int> status1, depend, order;

int ID(const string &s) {
	if (!trans.count(s)) {
		trans.insert({s, words.size()});
		words.push_back(s);
		graph.push_back({});
		depend.push_back(0);
		status1.push_back(0);
	}
	return trans[s];
}

void Install(int v, bool source) {
	for (auto i : graph[v])
		Install(i, false);   // 递归安装依赖先
	if (status1[v] == 0) {
		status1[v] = source ? 1 : 2; // 1 or 2
		order.push_back(v);
		cout << words[v] << " Installing." << endl;
	}
	if (!source)
		++depend[v];  // INSTALL 依赖个数
}

void Remove(int v, bool source) {
	depend[v] = max(0, depend[v] - 1);

	// 删除条件
	if (depend[v] == 0 && (source || status1[v] == 2)) {
		status1[v] = 0;
		order.erase(find(order.begin(), order.end(), v));
		cout << words[v] << " Removing." << endl;
	}

	// 移除依赖
	for (auto i : graph[v])
		Remove(i, false);
}

void test506() {
	string line = "", word1, word2, command;
	while (getline(cin, line) && line != "END") {
		stringstream ss;
		ss << line; // 按空格分开
		ss >> command;
		puts(line.c_str());
		if (command == "LIST") {    // 打印所有命令
			for (auto i : order)
				cout << words[i] << endl;
		} else {
			ss >> word1;
			int a = ID(word1);
			if (command == "DEPEND") {  // 建立依赖关系
				while (ss >> word2) {
					int b = ID(word2);
					graph[a].push_back(b);
				}
			} else if (command == "INSTALL") {
				if (status1[a] == 0)
					Install(a, true); // 安装
				else
					cout << words[a] << " is already installed." << endl;
			} else if (command == "REMOVE") {
				if (status1[a] == 0)
					cout << words[a] << " is not installed." << endl;
				else if (depend[a] == 0) {  // 组件没有被依赖的显示安装组件
					Remove(a, true);
				} else
					cout << words[a] << " is still needed." << endl;
			}
		}
	}
	cout << "END" << endl;
}