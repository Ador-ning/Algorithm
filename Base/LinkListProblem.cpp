//
// Created by ning on 2018/11/26.
//

#include "LinkList.h"
#include <stack>

using namespace Algorithm;

/*
 *  链表题目总结：
 *      1. 指针 / 双指针 / 快慢指针
 *      2. 头插 / 尾插
 *      3. 合并链表
 *
 *
 * */

// 利用 栈
void PrintListReversing_Iterative(ListNode *pHead) {
	std::stack<ListNode *> nodes;

	ListNode *pNode = pHead;

	while (pNode != nullptr) {
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
	if (pHead != nullptr) {
		if (pHead->next != nullptr)
			PrintListReversing_Recursive(pHead->next);

		printf("%d\t", pHead->val);
	}
}


// 题目相关
//----------------------------------------------------------------------------------------
// 删除有序链表中重复结点
void DeleteDup(ListNode **pHead) {
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode *pNode = *pHead;
	ListNode *pPreNode = nullptr;

	while (pNode != nullptr) {

		ListNode *pNext = pNode->next; // 对比是否重复
		bool needDelete = false;

		if (pNext != nullptr && pNext->val == pNode->val)
			needDelete = true;

		if (!needDelete) { // 没有遇到重复, 前移
// pPreNode = pNode;
			pNode = pNode->next;
		} else { // 遇到重复 --> 向前移动直到不重复
			int value = pNode->val;

			ListNode *pDelete = pNext; // 保留重复值的第一个结点

			while (pDelete->val ==
			       value && pDelete
			                != nullptr) {
				pNext = pDelete->next;

				delete
						pDelete;
				pDelete = nullptr;

				pDelete = pNext;
			} // 删除直到 非  value

			pNode->
					next = pNext;
			pNode = pNext;
		}
	}
}

// 合并链表(非有序) 有序-升序
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
	ListNode *p1 = head1;
	ListNode *p2 = head2;

	static ListNode dummy(0); // 做临时头结点
	ListNode *tail = &dummy;

	while (p1 && p2) {
		if (p1->val < p2->val) {
			tail->next = p1;
			p1 = p1->next;
		} else {
			tail->next = p2;
			p2 = p2->next;
		}
		tail = tail->next;
	}
	if (p1)
		tail->next = p1;
	if (p2)
		tail->next = p2;

	return dummy.next;
}

// 链表排序 O(n*logn)
ListNode *sortList(ListNode *head) {
	if (head == nullptr || head->next == nullptr)
		return head;

	// 找链表中间结点
	ListNode *p1 = head, *p2 = head;
	while (p2 && p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}

	p2 = p1->next;
	p1->next = nullptr; // 分割成两个链表

	// 进行递归
	return mergeTwoLists(sortList(head), sortList(p2));
}

// 合并两个排序的链表
ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode *pMergedHead = nullptr;

	if (pHead1->val < pHead2->val) {
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	} else {
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}
	return pMergedHead;
}

// 反转链表
ListNode *ReverseList(ListNode *pHead) {
	ListNode *pReversedHead = nullptr; // 反转后的头结点指针
	ListNode *pNode = pHead; // 用于指向调整的结点
	ListNode *pPrev = nullptr; // 永远指向反转后的第一个结点
	/*
	 * 原理： 利用辅助指针， 从原链表中一次拆分结点，以头插法加入反转后链表
	 * */

	while (pNode != nullptr) {
		ListNode *pNext = pNode->next;

		if (pNext == nullptr) // pNode 指向链表尾端
			pReversedHead = pNode;

		pNode->next = pPrev; // 调整结点，头插
		pPrev = pNode; // 指向下次待头插结点
		pNode = pNext; // 移动到下一个结点
	}

	return pReversedHead;
}

// 链表中倒数第K个结点
ListNode *FindKthToTail(ListNode *pHead, unsigned int k) {
	if (pHead == nullptr || k == 0)
		return nullptr;

	/*
	 * 技巧：两指针相距 K，然后同时后移
	 * */
	ListNode *pAhead = pHead;
	ListNode *pBehind = nullptr;
	for (unsigned int i = 0; i < k - 1; ++i) {
		if (pAhead->next != nullptr)
			pAhead = pAhead->next;
		else // k 大于链表的长度  -- 解决
			return nullptr;
	}
	pBehind = pHead;
	while (pAhead->next != nullptr) {
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}

// 链表结点删除 O(1)  --> 給被删除结点的指针
/*
 * 面试18：给定单向链表的头节点 和 一个结点指针
 * 技巧：将要删除结点的下一个结点信息，复制到该结点。删除其下一个结点空间；注意删除结点的位置
 * */
void DeleteNode(ListNode **pHead, ListNode *pDeleted) {

	if (!pDeleted || !pHead)
		return;

	// 要删除的结点不是尾结点
	if (pDeleted->next != nullptr) {
		ListNode *pNext = pDeleted->next; // 被删除结点的 next
		pDeleted->val = pNext->val;
		pDeleted->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	} else if (*pHead == pDeleted) { // 链表只有头结点，删除结点也是头结点
		delete pDeleted;
		pDeleted = nullptr;
		*pHead = nullptr;
	} else { // 多个结点链表，要删除结点为 尾结点; 遍历到尾部
		ListNode *pNode = *pHead;

		while (pNode->next != pDeleted) {
			pNode = pNode->next;
		}

		pNode->next = nullptr;
		delete pDeleted;
		pDeleted = nullptr;
	}
}

// 一个链表中包含环，如何找出环的入口结点？
/*
 * 面试23：
 * */
ListNode *MeetingNode(ListNode *pHead) {
	if (pHead == nullptr)
		return nullptr;

	ListNode *pSlow = pHead->next;
	if (pSlow == nullptr)
		return nullptr;

	ListNode *pFast = pSlow->next;

	while (pFast != nullptr && pSlow != nullptr) {

		if (pFast == pSlow) // 指向
			return pFast;
		pSlow = pSlow->next;
		pFast = pFast->next;

		if (pFast != nullptr)
			pFast = pFast->next;
	}
	return nullptr;
}

ListNode *EntryNode(ListNode *pHead) {
	ListNode *meetingNode = MeetingNode(pHead);

	if (meetingNode == nullptr)
		return nullptr;

	// 得到环中结点的数目
	int nodeInLoop = 1;
	ListNode *pNode1 = meetingNode;
	while (pNode1->next != meetingNode) {
		pNode1 = pNode1->next;
		++nodeInLoop;
	}

	// 先移动pNode1，次数为环中结点数
	pNode1 = pHead;
	for (int i = 0; i < nodeInLoop; ++i) {
		pNode1 = pNode1->next;
	}

	// 再移动pNode1和pNode2
	ListNode *pNode2 = pHead;
	while (pNode1 != pNode2) {
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}

// 删除倒数第 n 个结点
ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (head == nullptr || n <= 0)
		return head;

	// ListNode *dummy = new ListNode(0);
	// dummy->next = head;

	ListNode *fast = head;
	ListNode *slow = head;
	for (int i = 0; i < n; ++i) {
		if (fast->next != nullptr)
			fast = fast->next;
		else {
			if ((i + 1) == n) {
				return head->next;   // n == list length
			} else
				return head;    // n > list length
		}
	}

	while (fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = slow->next->next;
	return head;
}

// (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int flag = 0;
	ListNode *tail = new ListNode(0);
	ListNode *ptr = tail;

	while (l1 != nullptr || l2 != nullptr) {
		int val1 = 0;
		if (l1 != nullptr) {
			val1 = l1->val;
			l1 = l1->next;
		}

		int val2 = 0;
		if (l2 != nullptr) {
			val2 = l2->val;
			l2 = l2->next;
		}

		int tmp = val1 + val2 + flag;
		ptr->next = new ListNode(tmp % 10);
		flag = tmp / 10;
		ptr = ptr->next;
	}

	if (flag == 1) {
		ptr->next = new ListNode(1);
	}
	return tail->next;
}

// ====================测试代码====================

void test_removeNthFromEnd() {
	std::string s = "1";
	ListNode *head = stringToListNode(s);
	if (head != nullptr) {
		Line();
		std::cout << "Pointer is not nullptr.";
		Line();
		// 1->2  n = 2
		// 1    n = 1
		// 1->2->3->4->5
		auto h = removeNthFromEnd(head, 2);
		PrintList(h);
	}
	DestroyList(head);
}

void test_addTwoNumbers() {
	std::string s1 = "9 9";
	std::string s2 = "9";
	ListNode *l1 = stringToListNode(s1);
	ListNode *l2 = stringToListNode(s2);
	if (l1 != nullptr && l2 != nullptr) {
		ListNode * h = addTwoNumbers(l1, l2);
		Line();
		PrintList(h);
	}
}