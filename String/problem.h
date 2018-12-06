//
// Created by ning on 2018/11/29.
//

#ifndef ALGORITHM_PROBLEM_H
#define ALGORITHM_PROBLEM_H

#include <string>
#include <vector>

// leetcode
std::string multiply(std::string num1, std::string num2);

// 1. 字符串排序
// 2. 单词查找树

// 3. 子串查找
// KMP
void compute_prefix(const std::string &pattern, std::vector<int> &next);

int kmp(const std::string &test, const std::string &pattern);

void test_kmp();


#endif //ALGORITHM_PROBLEM_H
