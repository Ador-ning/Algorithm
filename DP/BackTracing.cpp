//
// Created by ning on 2018/12/8.
//
#include <vector>
#include <string>
#include "problem.h"

std::vector<std::string> Algorithm::generateParenthesis(int n) {
	std::vector<std::string> res;
	backtrade("", res, n, n);
	return res;
}

void Algorithm::backtrade(std::string sublist, std::vector<std::string> &res, int left, int right) {

	// 左右括号均用完
	if (left == 0 && right == 0) {
		res.push_back(sublist);
		return;
	}
	// back tracing
	// 左括号剩余
	if (left > 0)
		backtrade(sublist + "(", res, left - 1, right);
	// 右括号剩余 > 左括号剩余
	if (right > left)
		backtrade(sublist + ")", res, left, right);
}