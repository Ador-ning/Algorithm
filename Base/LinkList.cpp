//
// Created by ning on 2018/11/23.
//
#include <cstdio>
#include <stack>
#include "LinkList.h"
#include "../Base.h"

using namespace std;
using namespace Algorithm;

// 链表基本操作 -- 调试
// ----------------------------------------------------------------------------------------
// 构建链表
ListNode *Algorithm::stringToListNode(std::string &input) {
	if (input.size() <= 0)
		return nullptr;
	std::vector<int> list = stringToVector<int>(input);

	if (DEBUG) {
		std::cout << "Debug info: the input data convert to vector int is: ";
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
std::string Algorithm::ListNodeToString(ListNode *node) {
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
int Algorithm::getValueAndMoveNext(ListNode *l) {
	int x = 0;
	if (l != nullptr) {
		x = l->val;
		l = l->next;
	}
	return x;
}

// 顺序打印 List
void Algorithm::PrintList(ListNode *pHead) {
	printf("Print List start.\n");

	ListNode *pNode = pHead;

	while (pNode != nullptr) {
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}

	printf("\n Print List end.\n");
}

// 销毁 List
void Algorithm::DestroyList(ListNode *pHead) {
	ListNode *pNode = pHead;

	while (pNode != nullptr) {
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}

// 删除 List 结点
void Algorithm::RemoveNode(ListNode **pHead, int value) {
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode *pDeleted = nullptr;

	if ((*pHead)->val == value) { // 删除链表头部
		pDeleted = *pHead;
		(*pHead) = (*pHead)->next;
	} else {
		ListNode *pNode = *pHead;

		// 移动
		while (pNode->next != nullptr && pNode->next->val != value)
			pNode = pNode->next;

		// 删除
		if (pNode->next != nullptr && pNode->next->val == value) {
			pDeleted = pNode->next;
			pNode->next = pDeleted->next;
		}
	}

	if (pDeleted != nullptr) {
		delete pDeleted;
		pDeleted = nullptr;
	}
}

// 创建 List 结点
ListNode *Algorithm::CreateListNode(int value) {
	ListNode *pNode = new ListNode();
	pNode->val = value;
	pNode->next = nullptr;
	return pNode;
}

// 链表尾部添加 List 结点
void Algorithm::AddToTail(ListNode **pHead, int value) {
	ListNode *pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;

	if (*pHead != nullptr) {
		ListNode *pNode = *pHead;

		while (pNode->next != nullptr)
			pNode = pNode->next;

		pNode->next = pNew;
	} else
		*pHead = pNew;
}

// 连接 List结点
void Algorithm::ConnectListNodes(ListNode *pCurrent, ListNode *pNext) {
	if (pCurrent == nullptr) {
		printf("Error to connect two nodes.\n");
		return;
	}

	pCurrent->next = pNext;
}

// 打印 List 结点
void Algorithm::PrintListNode(ListNode *pNode) {
	if (pNode == nullptr)
		printf("The node is nullptr.\n");
	else
		printf("The key in node is %d.\n", pNode->val);
}

// 求链表长度 List length
int Algorithm::ListLength(ListNode *head) {
	if (head == nullptr)
		return 0;
	int i = 0;
	while (head != nullptr) {
		i += 1;
		head = head->next;
	}
	return i;
}
