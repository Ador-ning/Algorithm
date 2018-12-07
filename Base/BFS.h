//
// Created by ning on 2018/12/7.
//

#ifndef ALGORITHM_BFS_H
#define ALGORITHM_BFS_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

// BFS 代码模版

/*
 * 反向生成路径
 * father -- 树
 * target -- 目标结点
 * return -- 起点到target路径
 * */
template<typename state_t>
std::vector<state_t> gen_path(const std::unordered_map<state_t, state_t> &father,
                              const state_t &target) {
	std::vector<state_t> path;
	path.push_back(target);
	state_t cur = target;
	while (father.find(cur) != father.end()) {
		cur = father.at(cur);
		path.push_back(cur);
	}

	std::reverse(path.begin(), path.end());
	return path;
}

/*
 * 广度优先搜索
 * state_t 状态（整数/字符串/一维数组等）
 * start --  起点
 * state_is_target -- 判断状态是否是目标的函数
 * state_extend -- 状态扩展函数
 * return 从起点到目标状态的一条最短路径
 * */
template<typename state_t>
std::vector<state_t> bfs(state_t &start,
                         bool(*state_is_target)(const state_t &),
                         std::vector<state_t> (*state_extend)(const state_t &,
                                                              std::unordered_set<std::string> &visited)) {

	std::queue<state_t> next, current; // 当前层 下一层
	std::unordered_set<state_t> visited; // 判重
	std::unordered_map<state_t, state_t> father;

	int level = 0; // 层次
	bool found = false;
	state_t target;

	current.push(start);
	visited.insert(start);
	while (!current.empty() && !found) {
		++level;
		while (!current.empty() && !found) {
			const state_t state = current.front();
			current.pop();
			std::vector<state_t> new_states = state_extend(state, visited);

			for (auto it : new_states) {
				if (state_is_target(it)) {
					found = true;
					target = it;
					father[it] = state;
					break;
				}
				next.push(it);

				// visited.insert(it); 必􏸱􏺢􏵃 state_extend() 􏶶
				father[it] = state;
			}
		}
		std::swap(current, next);
	}

	if (found) {
		return gen_path(father, target);
	} else {
		return std::vector<state_t>();
	}
}


#endif //ALGORITHM_BFS_H
