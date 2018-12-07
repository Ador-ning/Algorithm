//
// Created by ning on 2018/12/6.
//

#ifndef ALGORITHM_HASHSET_H
#define ALGORITHM_HASHSET_H

template<typename elem_t>
int elem_hash(const elem_t &e);

template<typename elem_t>
bool operator==(const elem_t &e1, const elem_t &e2);

template<typename elem_t>
class hash_set {
public:
	hash_set(int prime, int capacity);

	~hash_set();

	bool find(const elem_t &elem);

	bool insert(const elem_t &elem);

private:
	int prime; // 哈希表取模的质数，也是哈希桶的个数，小于 capacity
	int capacity; // 哈希表容量， 一定要大于元素最大个数
	int *head; // 首结点下标

	struct node_t {
		elem_t elem;
		int next;

		node_t() : next(-1) {}
	} *node; // 静态链表
	int size;
};

#endif //ALGORITHM_HASHSET_H
