//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_LINKLIST_H
#define ALGORITHM_LINKLIST_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "../Base.h"

namespace Algorithm {
	class ListNode {
	public:
		// 构造函数
		ListNode(int x) : val(x), next(nullptr) {}

		ListNode() : val(0), next(nullptr) {}

	public:
		int val;
		ListNode *next;
	};

	ListNode *stringToListNode(std::string &input);

	std::string ListNodeToString(ListNode *node);

	int getValueAndMoveNext(ListNode *l);

	void PrintList(ListNode *pHead);

	void DestroyList(ListNode *pHead);

	void RemoveNode(ListNode **pHead, int value);

	ListNode *CreateListNode(int value);

	void AddToTail(ListNode **pHead, int value);

	void ConnectListNodes(ListNode *pCurrent, ListNode *pNext);

	void PrintListNode(ListNode *pNode);

	int ListLength(ListNode *head);
}

#endif //ALGORITHM_LINKLIST_H
