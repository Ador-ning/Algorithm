//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::greater;
using std::swap;
using std::cout;
using std::endl;

// 最小堆
class HeapSort {
public:
	explicit HeapSort(vector<int> nums) : data(nums.begin(), nums.end()), size(data.size()) {}

	// 调整 index
	void adjust(vector<int> &data, int index) {
		int left = 2 * index + 1, right = 2 * index + 2;
		int maxIdx = index;

		// data[left] == data[right] --> chose left
		if (left < size && data[left] < data[maxIdx])
			maxIdx = left;
		if (right < size && data[right] < data[maxIdx])
			maxIdx = right;
		if (maxIdx != index) {
			swap(data[maxIdx], data[index]);
			adjust(data, maxIdx); // 递归 调整其它不满足堆性质的部分
		}
	}

	/*
	 * 1. 交换 将最后叶子结点 和 堆顶
	 * 2. 从 堆顶开始调整
	 * */
	void deleteTop() {
		data[0] = data[data.size() - 1];
		data.pop_back();
		size--;
		adjust(data, 0);

		if (DEBUG) {
			cout << "delete top: " << data[0] << endl;
			print();
			cout << endl;
		}
	}

	/*
	 * 1. 插入尾部
	 * 2. 对每一个非叶结点进行堆调整， 最后一个叶结点的父结点开始
	 * */
	void insert(int val) {
		data.push_back(val);
		size++;
		for (int i = size / 2; i >= 0; --i) {
			adjust(data, i);
		}

		if (DEBUG) {
			cout << "insert: " << val << endl;
			print();
			cout << endl;
		}
	}

	void build() {
		// 对每一个非叶结点进行堆调整， 最后一个叶结点的父结点开始
		for (int i = data.size() / 2; i >= 0; --i) {
			adjust(data, i);
		}

		if (DEBUG) {
			cout << "build : " << endl;
			print();
			cout << endl;
		}

	}

	void print() {
		cout << "print heap sort vector: ";
		auto it = data.begin();
		while (it != data.end()) {
			cout << *it << ' ';
			it++;
		}
	}

private:
	vector<int> data;
	int size;
};


// leetcode 703. 数据流中的第K大元素
// 优先级队列实现 最小堆
class KthLargest {
public:
	// k 小顶堆
	KthLargest(int k, vector<int> nums) : len(k) {
		for (auto num : nums) {
			q.push(num);
			if (q.size() > k)
				q.pop();
		}
	}

	int add(int val) {
		q.push(val);
		if (q.size() > len)
			q.pop();
		return q.top();
	}

private:
	priority_queue<int, vector<int>, greater<int>> q;       // 优先级队列实现  小顶堆
	int len;
};


#endif //ALGORITHM_HEAP_H
