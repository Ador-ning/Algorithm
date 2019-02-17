#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "Base.h"

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


int main(int argc, const char *argv[]) {
	cout << "main test: " << endl;
	vector<int> data = {14, 50, 90, 6, 2, 12, 7, 8, 2, 3};

	GetLeastNumbers_Solution(data, 5);
}