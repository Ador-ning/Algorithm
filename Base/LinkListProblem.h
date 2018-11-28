//
// Created by ning on 2018/11/28.
//

#ifndef ALGORITHM_LINKLISTPROBLEM_H
#define ALGORITHM_LINKLISTPROBLEM_H

#include "LinkList.h"

using namespace Algorithm;

void PrintListReversing_Iterative(ListNode *pHead);

void PrintListReversing_Recursive(ListNode *pHead);

void DeleteDup(ListNode **pHead);

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2);

ListNode *sortList(ListNode *head);

ListNode *Merge(ListNode *pHead1, ListNode *pHead2);

ListNode *ReverseList(ListNode *pHead);

ListNode *FindKthToTail(ListNode *pHead, unsigned int k);

void DeleteNode(ListNode **pHead, ListNode *pDeleted);

ListNode *MeetingNode(ListNode *pHead);

ListNode *EntryNode(ListNode *pHead);

ListNode *removeNthFromEnd(ListNode *head, int n);

void test_removeNthFromEnd();

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

void test_addTwoNumbers();

#endif //ALGORITHM_LINKLISTPROBLEM_H
