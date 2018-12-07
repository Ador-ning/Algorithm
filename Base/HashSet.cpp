//
// Created by ning on 2018/12/6.
//
#include <algorithm>
#include "HashSet.h"

template<typename elem_t>
hash_set<elem_t>::hash_set(int prime, int capacity) {
	this->prime = prime;
	this->capacity = capacity;
	head = new int[prime];
	node = new node_t[capacity];
	std::fill(head, head + prime, -1);
	std::fill(node, node + capacity, node_t());
	size = 0;
}

template<typename elem_t>
hash_set<elem_t>::~hash_set() {
	this->prime = 0;
	this->capacity = 0;
	delete[] head;
	delete[] node;
	head = nullptr;
	node = nullptr;
	size = 0;
}

template<typename elem_t>
bool hash_set<elem_t>::find(const elem_t &elem) {
	for (int i = head[elem_hash(elem)]; i != -1; i = node[i].next)
		if (elem == node[i].elem)
			return true;
	return false;
}

template<typename elem_t>
bool hash_set<elem_t>::insert(const elem_t &elem) {
	const int hash_code = elem_hash(elem);

	for (int i = head[hash_code]; i != -1; i = node[i].next)
		if (elem == node[i].elem)
			return false; // 存在

	// 不存在，插入在首结点之前
	node[size].next = head[hash_code];
	node[size].elem = elem;
	head[hash_code] = size++;
	return true;
}