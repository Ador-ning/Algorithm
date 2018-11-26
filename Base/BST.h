//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_BST_H
#define ALGORITHM_BST_H

#include <iostream>
#include "BinaryTree.h"

namespace Algorithm {
// =========================== base operation =========================== //
// BST 中查找
	void BST_search(BinTreeNode *pRoot, int x) {

		if (pRoot == nullptr) { // 叶节点
			cout << "Search failed\n";
			return;
		}

		if (x == pRoot->val)
			cout << pRoot->val << endl;
		else if (x < pRoot->val)
			BST_search(pRoot->left, x);
		else
			BST_search(pRoot->right, x);
	}

// BST 中插入结点
	void BST_insert(BinTreeNode *&pRoot, int x) {
		if (pRoot == nullptr) {
			pRoot = new BinTreeNode(x);
			return;
		}
		if (x == pRoot->val)
			return;
		else if (x < pRoot->val)
			BST_insert(pRoot->left, x);
		else
			BST_insert(pRoot->left, x);
	}

// 构造 BST
	BinTreeNode *CreateBST(int data[], int n) {
		BinTreeNode *pRoot = nullptr;

		for (int i = 0; i < n; ++i)
			BST_insert(pRoot, data[i]);
		return pRoot;
	}

// 查找到 BST 中最大权值的结点
	BinTreeNode *BST_findMax(BinTreeNode *pRoot) {
		while (pRoot->right != nullptr)
			pRoot = pRoot->right;
		return pRoot;
	}

// 查找到 BST 中最小权值的结点
	BinTreeNode *BST_findMin(BinTreeNode *pRoot) {
		while (pRoot->left != nullptr)
			pRoot = pRoot->left;
		return pRoot;
	}

// BST 删除结点
	void BST_DeleteNode(BinTreeNode *&pRoot, int x) {
		if (pRoot == nullptr)
			return; // base

		if (pRoot->val == x) { // 找到结点

			if (pRoot->right == nullptr && pRoot->left == nullptr)
				pRoot = nullptr; // 叶子结点
			else if (pRoot->left != nullptr) { // 左子树不为空
				// 左子树中找最大，顶替 pRoot
				BinTreeNode *pre = BST_findMax(pRoot->left); // 找 pRoot 前缀
				pRoot->val = pre->val; // 覆盖
				BST_DeleteNode(pRoot->left, pre->val); // 删除该结点
			} else { // 右子树不为空
				// 左子树中找最小，顶替 pRoot
				BinTreeNode *next = BST_findMin(pRoot->left); // 找 pRoot 前缀
				pRoot->val = next->val;
				BST_DeleteNode(pRoot->right, next->val);
			}

		} else if (pRoot->val > x)
			BST_DeleteNode(pRoot->left, x);
		else
			BST_DeleteNode(pRoot->right, x);

	}


// =========================== Work =========================== //

// 输入一个二叉搜索树，将该 BST 转换成一个排序的双向链接
// 要求：不能创建任何新的结点，只能调整树中的指针
	void ConvertNode(BinTreeNode *pNode, BinTreeNode **pLastNodeList) {
		if (pNode == nullptr)
			return;

		BinTreeNode *pCurrent = pNode;

		if (pCurrent->left != nullptr)
			ConvertNode(pCurrent->left, pLastNodeList);

		pCurrent->left = *pLastNodeList;

		if (*pLastNodeList != nullptr)
			(*pLastNodeList)->right = pCurrent;

		*pLastNodeList = pCurrent;

		if (pCurrent->right != nullptr)
			ConvertNode(pCurrent->right, pLastNodeList);
	}

	BinTreeNode *Convert(BinTreeNode *pRoot) {
		BinTreeNode *pLastNodeList = nullptr;
		ConvertNode(pRoot, &pLastNodeList);

		// pLastNodeList指向双链表的尾端
		// 需要返回头节点
		BinTreeNode *pHeadList = pLastNodeList;
		while (pHeadList != nullptr && pHeadList->left != nullptr) {
			pHeadList = pHeadList->left;
		}
		return pHeadList;
	}


// ======================= 测试 ==============
	void PrintDoubleLinkedList(BinTreeNode *pHeadOfList) {
		BinTreeNode *pNode = pHeadOfList;

		printf("The nodes from left to right are:\n");
		while (pNode != nullptr) {
			printf("%d\t", pNode->val);

			if (pNode->right == nullptr)
				break;
			pNode = pNode->right;
		}

		printf("\nThe nodes from right to left are:\n");
		while (pNode != nullptr) {
			printf("%d\t", pNode->val);

			if (pNode->left == nullptr)
				break;
			pNode = pNode->left;
		}

		printf("\n");
	}

	void DestroyList(BinTreeNode *pHeadOfList) {
		BinTreeNode *pNode = pHeadOfList;
		while (pNode != nullptr) {
			BinTreeNode *pNext = pNode->right;

			delete pNode;
			pNode = pNext;
		}
	}

	void Test(char *testName, BinTreeNode *pRootOfTree) {
		if (testName != nullptr)
			printf("%s begins:\n", testName);

		pre_oder(pRootOfTree);

		BinTreeNode *pHeadOfList = Convert(pRootOfTree);

		PrintDoubleLinkedList(pHeadOfList);
	}


	void Test1() {
		BinTreeNode *pNode10 = new BinTreeNode(10);
		BinTreeNode *pNode6 = new BinTreeNode(6);
		BinTreeNode *pNode14 = new BinTreeNode(14);
		BinTreeNode *pNode4 = new BinTreeNode(4);
		BinTreeNode *pNode8 = new BinTreeNode(8);
		BinTreeNode *pNode12 = new BinTreeNode(12);
		BinTreeNode *pNode16 = new BinTreeNode(16);

		ConnectBinaryNodes(pNode10, pNode6, pNode14);
		ConnectBinaryNodes(pNode6, pNode4, pNode8);
		ConnectBinaryNodes(pNode14, pNode12, pNode16);

		Test("Test1", pNode10);

		DestroyList(pNode4);
	}


	void Test2() {
		BinTreeNode *pNode5 = new BinTreeNode(5);
		BinTreeNode *pNode4 = new BinTreeNode(4);
		BinTreeNode *pNode3 = new BinTreeNode(3);
		BinTreeNode *pNode2 = new BinTreeNode(2);
		BinTreeNode *pNode1 = new BinTreeNode(1);

		ConnectBinaryNodes(pNode5, pNode4, nullptr);
		ConnectBinaryNodes(pNode4, pNode3, nullptr);
		ConnectBinaryNodes(pNode3, pNode2, nullptr);
		ConnectBinaryNodes(pNode2, pNode1, nullptr);

		Test("Test2", pNode5);

		DestroyList(pNode1);
	}


	void Test3() {
		BinTreeNode *pNode1 = new BinTreeNode(1);
		BinTreeNode *pNode2 = new BinTreeNode(2);
		BinTreeNode *pNode3 = new BinTreeNode(3);
		BinTreeNode *pNode4 = new BinTreeNode(4);
		BinTreeNode *pNode5 = new BinTreeNode(5);

		ConnectBinaryNodes(pNode1, nullptr, pNode2);
		ConnectBinaryNodes(pNode2, nullptr, pNode3);
		ConnectBinaryNodes(pNode3, nullptr, pNode4);
		ConnectBinaryNodes(pNode4, nullptr, pNode5);

		Test("Test3", pNode1);

		DestroyList(pNode1);
	}

// 树中只有1个结点
	void Test4() {
		BinTreeNode *pNode1 = new BinTreeNode(1);
		Test("Test4", pNode1);

		DestroyList(pNode1);
	}

// 树中没有结点
	void Test5() {
		Test("Test5", nullptr);
	}

}

#endif //ALGORITHM_BST_H
