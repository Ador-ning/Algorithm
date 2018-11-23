//
// Created by ning on 2018/11/23.
//
#include <cstdio>
#include "LinkList.h"
#include <stack>

using namespace std;
using namespace Algorithm;

// 利用 栈
void PrintListReversing_Iterative(ListNode *pHead) {
	std::stack<ListNode *> nodes;

	ListNode *pNode = pHead;

	while (pNode != NULL) {
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while (!nodes.empty()) {
		pNode = nodes.top();
		printf("%d\t", pNode->val);
		nodes.pop();
	}
}

// 递归
void PrintListReversing_Recursive(ListNode *pHead) {
	if (pHead != NULL) {
		if (pHead->next != NULL)
			PrintListReversing_Recursive(pHead->next);

		printf("%d\t", pHead->val);
	}
}

// ====================测试代码====================
void Test(ListNode *pHead) {
	PrintList(pHead);
	PrintListReversing_Iterative(pHead);
	printf("\n");
	PrintListReversing_Recursive(pHead);
}

// 1->2->3->4->5
void Test1() {
	printf("\nTest1 begins.\n");

	ListNode *pNode1 = CreateListNode(1);
	ListNode *pNode2 = CreateListNode(2);
	ListNode *pNode3 = CreateListNode(3);
	ListNode *pNode4 = CreateListNode(4);
	ListNode *pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2() {
	printf("\nTest2 begins.\n");

	ListNode *pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3() {
	printf("\nTest3 begins.\n");

	Test(NULL);
}


int main(int argc, char *argv[]) {
	Test1();
	Test2();
	Test3();

	return 0;
}


