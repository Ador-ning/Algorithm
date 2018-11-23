//
// Created by ning on 2018/11/23.
//
#include "BinaryTree.h"

using namespace std;
using namespace Algorithm;
namespace Algorithm {
// 树的子结构
/*
 * 面试题26：输入两颗二叉树，判断B是不是A的子结构
 */
	bool Equal(double num1, double num2) {
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}

	bool T1HaveT2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;

		if (!Equal(pRoot1->val, pRoot2->val))
			return false;

		return T1HaveT2(pRoot1->left, pRoot2->left) && T1HaveT2(
				pRoot1->right, pRoot2->right);
	}

	bool HasSuTree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
		bool result = false;

		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			if (Equal(pRoot1->val, pRoot2->val))
				result = T1HaveT2(pRoot1, pRoot2);
			if (!result)
				result = HasSuTree(pRoot1->left, pRoot2);
			if (!result)
				result = HasSuTree(pRoot1->right, pRoot2);
		}
		return result;
	}
}
