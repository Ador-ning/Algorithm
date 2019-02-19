#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "Base.h"
#include "String.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::list;
using std::istringstream;
using std::unordered_set;
using std::unordered_map;

/*
 *  cur -- path 的当前位置
 *  ed -- nums 的当前元素  1 / 1 2 / 1 2 3 / 2 / 2 3 / 3
 * */
void print_subset(const vector<int> &nums, vector<int> &path, int cur, int ed) {
	int i, j;
	for (i = ed; i < nums.size(); ++i) {
		path[cur] = nums[i];
		for (int j = 0; j <= cur; ++j)
			cout << path[j] << ' ';
		cout << endl;
		print_subset(nums, path, cur + 1, i + 1);
	}
}

void list_using() {
	cout << "list using: " << endl;
	list<int> myList1, myList2;
	list<int>::iterator it;

	for (int i = 1; i <= 4; ++i)
		myList1.push_back(i); // 1 2 3 4
	for (int i = 1; i <= 3; ++i)
		myList2.push_back(i * 10); // 10 20 30

	it = myList1.begin();
	std::advance(it, 1); // 2

	// list1: 1 10 20 30 2 3 4
	// list2: empty
	// it: list1 -> 2
	myList1.splice(it, myList2);

	// list1: 1 10 20 30
	// list2: 2 3 4
	myList2.splice(myList2.begin(), myList1, it, myList1.end());


	for (it = myList1.begin(); it != myList1.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (it = myList2.begin(); it != myList2.end(); ++it)
		cout << *it << " ";
	cout << endl;

	it = myList1.begin();
	std::advance(it, 3);
	myList1.splice(myList1.begin(), myList1, it);  // 将 it 移动到 myList1 首部
	cout << *it << endl;
	for (it = myList1.begin(); it != myList1.end(); ++it)
		cout << *it << " ";
	cout << endl;

	it = myList1.begin();
	std::advance(it, 2);
	myList1.splice(myList1.end(), myList1, it);  // 将 it 移动到 myList1 尾部
	cout << *it << endl;
	for (it = myList1.begin(); it != myList1.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

// string parse ' ', '/' and so on...
void string_parsing() {
	string s = "root/a 1.txt(abcd) 2.txt(efgh) 3.txt(,,,,)";
	string dir = s.substr(0, s.find(' '));
	string files = s.substr(s.find(' ') + 1, s.size() - s.find(' ') - 1);
	string filename, content;
	cout << dir << '\t' << files << endl;
	while (files.find(' ') != std::string::npos) {
		string file = files.substr(0, files.find(' '));
		files = files.substr(files.find(' ') + 1, files.size() - files.find(' ') - 1);
		cout << file << endl;
		if (file.find('(') == std::string::npos)
			continue;
		filename = file.substr(0, file.find('('));
		content = file.substr(file.find('(') + 1, file.size() - file.find('(') - 2);
		cout << filename << '\t' << content << endl;;
	}
	cout << files << endl;

	// <istream>
	s = "root/a 1.txt(abcd) 2.txt(efgh)";
	std::istringstream is(s);
	string pre = "", t = "";
	// 按空格分割
	is >> pre; // pre == root/a
	while (is >> t) {
		cout << t << '\t'; // 1.txt(abcd) // 2.txt(efgh)
		int idx = t.find_last_of('(');
		string dir = pre + "/" + t.substr(0, idx);
		string content = t.substr(idx + 1, t.size() - idx - 2);
		cout << dir << '\t' << content << endl;
	}
}

vector<vector<int>> io_parse(int lines) {
	vector<vector<int>> res;
	vector<int> vl;
	string line;
	while (lines-- && getline(cin, line)) {
		istringstream is(line);
		string item;
		while (is >> item) {
			vl.push_back(std::stoi(item));
		}
		res.push_back(vl);
		vl.clear();
	}

	return res;
}

void io_test() {
	auto res = io_parse(2);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}

// stl heap 操作
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	int len = input.size();
	if (len <= 0 || k > len)
		return vector<int>();

	vector<int> res(input.begin(), input.begin() + k);

	// 建立大根堆
	std::make_heap(res.begin(), res.end());
	for (int i = k; i < len; ++i) {

		// 需要进入
		if (input[i] < res[0]) {
			// res[0] <--> res[res.size()-1]  互换
			std::pop_heap(res.begin(), res.end());
			// delete res[res.size()-1]
			res.pop_back();
			// insert back input[i]
			res.push_back(input[i]);
			// adjust heap
			std::push_heap(res.begin(), res.end());
		}
	}

	std::sort_heap(res.begin(), res.end());
	auto it = res.begin();
	Print(it, res.end());
	return res;
}

int maxTag;


// 求 data[left, right] --> 中最大值
int maxInt(const vector<int> &data, int left, int right) {
	int res = data[left];
	while (++left <= right) {
		if (data[left] > res)
			res = data[left];
	}
	return res;
}

// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
	vector<int> res(num.size() - size + 1);

	int left = 0, right = size - 1;
	maxTag = maxInt(num, left, right);
	res[0] = maxTag;
	int k = 1;
	while (++right < num.size()) {
		// count -- 优化
		// 1. 出去的值 大于 上一个窗口的最大值
		if (num[left] >= maxTag) {
			if (num[left] < num[right])
				maxTag = num[right];
			else
				maxTag = maxInt(num, left + 1, right); // 重新遍历
		} else {
			if (num[right] > maxTag)
				maxTag = num[right];
		}

		// 保存结果
		res[k++] = maxTag;
		// move
		left++;
	}

	auto it = res.begin();
	Print(it, res.end());

	return res;
}


// 递归
bool check(vector<vector<char>> &data, vector<vector<bool>> tag, int i, int j, string p) {

	if (data[i][j] != p[0])
		return false;

	// 1. 等
	tag[i][j] = true;
	// 2. new path
	p = p.substr(1, p.size() - 1);
	if (p.size() <= 0)
		return true;

	// 四个方向
	bool res = false;
	if ((i - 1) >= 0 && tag[i - 1][j] == false) {
		res = check(data, tag, i - 1, j, p);
	}
	if (res == false && (i + 1) < data.size() && tag[i + 1][j] == false) {
		res = check(data, tag, i + 1, j, p);
	}
	if (res == false && (j - 1) >= 0 && tag[i][j - 1] == false) {
		res = check(data, tag, i, j - 1, p);
	}
	if (res == false && (j + 1) < data[0].size() && tag[i][j + 1] == false) {
		res = check(data, tag, i, j + 1, p);
	}
	return res;
}

bool helper(vector<vector<char>> &data, string path) {
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data[i].size(); ++j) {
			if (data[i][j] == path[0]) {
				vector<vector<bool>> tag(data.size(), vector<bool>(data[0].size(), false));
				if (check(data, tag, i, j, path))
					return true;
			}
		}
	}
	return false;
}

// 剑指offer -- 矩阵中的路径
bool hasPath(char *matrix, int rows, int cols, char *str) {
	vector<vector<char>> data(rows, vector<char>(cols)); // rows * cols

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (*matrix == ' ') {
				matrix++;
			}
			data[i][j] = *matrix++;
		}
	}

	string path;
	while (*str != '\0') {
		path += *str;
		str++;
	}

	return helper(data, path);
}


int main(int argc, const char *argv[]) {
	cout << "main test: " << endl;
	test_classString();
}