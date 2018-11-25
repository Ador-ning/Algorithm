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

// 链表基本操作 -- 调试
	// ----------------------------------------------------------------------------------------
	// 构建链表
	ListNode *stringToListNode(std::string &input) {
		if (input.size() <= 0)
			return nullptr;
		std::vector<int> list = Algorithm::stringToVector<int>(input);

		if (DEBUG) {
			std::cout << "the input data convert to vector int is: ";
			auto it = list.begin();
			Print(it, list.end());
			std::cout << std::endl;
		}

		ListNode *dummyRoot = new ListNode(0);
		ListNode *ptr = dummyRoot;
		for (auto item : list) {
			ptr->next = new ListNode(item);
			ptr = ptr->next;
		}
		ptr = dummyRoot->next;
		delete dummyRoot;
		return ptr;
	}

	// 将链表 val 输出
	std::string ListNodeToString(ListNode *node) {
		if (node == nullptr)
			return "[]";
		ListNode *tmp = node;
		std::string res;
		while (tmp) {
			res += std::to_string(tmp->val) + ", ";
			tmp = tmp->next;
		}
		return "[" + res.substr(0, res.length() - 2) + "]";
	}

	// 之前，保留
	// ----------------------------------------------------------------------------------------
// get value and move next
	int getValueAndMoveNext(ListNode *l) {
		int x = 0;
		if (l != nullptr) {
			x = l->val;
			l = l->next;
		}
		return x;
	}

// 顺序打印 List
	void PrintList(ListNode *pHead) {
		printf("Print List start.\n");

		ListNode *pNode = pHead;

		while (pNode != NULL) {
			printf("%d\t", pNode->val);
			pNode = pNode->next;
		}

		printf("\n Print List end.\n");
	}

// 销毁 List
	void DestroyList(ListNode *pHead) {
		ListNode *pNode = pHead;

		while (pNode != nullptr) {
			pHead = pHead->next;
			delete pNode;
			pNode = pHead;
		}
	}

// 删除 List 结点
	void RemoveNode(ListNode **pHead, int value) {
		if (pHead == NULL || *pHead == NULL)
			return;

		ListNode *pDeleted = NULL;

		if ((*pHead)->val == value) { // 删除链表头部
			pDeleted = *pHead;
			(*pHead) = (*pHead)->next;
		} else {
			ListNode *pNode = *pHead;

			// 移动
			while (pNode->next != NULL && pNode->next->val != value)
				pNode = pNode->next;

			// 删除
			if (pNode->next != NULL && pNode->next->val == value) {
				pDeleted = pNode->next;
				pNode->next = pDeleted->next;
			}
		}

		if (pDeleted != NULL) {
			delete pDeleted;
			pDeleted = NULL;
		}
	}

// 创建 List 结点
	ListNode *CreateListNode(int value) {
		ListNode *pNode = new ListNode();
		pNode->val = value;
		pNode->next = NULL;
		return pNode;
	}

// 链表尾部添加 List 结点
	void AddToTail(ListNode **pHead, int value) {
		ListNode *pNew = new ListNode();
		pNew->val = value;
		pNew->next = NULL;

		if (*pHead != NULL) {
			ListNode *pNode = *pHead;

			while (pNode->next != NULL)
				pNode = pNode->next;

			pNode->next = pNew;
		} else
			*pHead = pNew;
	}

// 连接 List结点
	void ConnectListNodes(ListNode *pCurrent, ListNode *pNext) {
		if (pCurrent == NULL) {
			printf("Error to connect two nodes.\n");
			return;
		}

		pCurrent->next = pNext;
	}

// 打印 List 结点
	void PrintListNode(ListNode *pNode) {
		if (pNode == NULL)
			printf("The node is NULL.\n");
		else
			printf("The key in node is %d.\n", pNode->val);
	}

// 求链表长度 List length
	int ListLength(ListNode *head) {
		if (head == nullptr)
			return 0;
		int i = 0;
		while (head != nullptr) {
			i += 1;
			head = head->next;
		}
		return i;
	}

}

#endif //ALGORITHM_LINKLIST_H
