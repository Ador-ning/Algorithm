//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_LINKLIST_H
#define ALGORITHM_LINKLIST_H

#include <iostream>
#include <cstdio>

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

		while (pNode != NULL) {
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

//
}

#endif //ALGORITHM_LINKLIST_H
