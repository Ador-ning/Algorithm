#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Base.h"

using std::cout;
using std::endl;
using std::vector;
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

int main(int argc, const char *argv[]) {
	cout << "main test: " << endl;

	vector<int> vv = {1, 2, 3};
	vector<int> path(vv.size(), 0);
	print_subset(vv, path, 0, 0);
}