//
// Created by ning on 2018/12/8.
//

#ifndef ALGORITHM_PROBLEM_H
#define ALGORITHM_PROBLEM_H

#include <vector>
#include <string>

namespace Algorithm {
	// leetcode 括号生成
	std::vector<std::string> generateParenthesis(int n);

	void backtrade(std::string sublist, std::vector<std::string> &res, int left, int right);
}


#endif //ALGORITHM_PROBLEM_H
