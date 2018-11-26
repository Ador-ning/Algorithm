//
// Created by ning on 2018/11/26.
//

#include "BinaryTree.h"

using namespace Algorithm;


// 二叉树结点的查找、修改 -- 在二叉树中找到所有数据域为给定数据域的结点，并将它们修改为给定的数据
void search(BinTreeNode *root, int x, int newdata) {
	if (root == nullptr)
		return; // base

	if (root->val == x)
		root->val = newdata; // 修改数据

	search(root->left, x, newdata); // 修改左子树
	search(root->right, x, newdata); // 修改右子树
}

// 二叉树所有 根->叶子 路径和为 sum

// 二叉树深度
/*
 * 面试55：输入一棵二叉树的根结点，求该树的深度
 * 从根结点到叶结点一次经过的结点（含根、叶结点）形成树的一条路径，最长路径为其深度
 */
int TreeDepth(const BinTreeNode *pRoot) {
	if (pRoot == nullptr)   // 空树 或者 叶结点
		return 0;

	int nLeft = TreeDepth(pRoot->left);
	int nRight = TreeDepth(pRoot->right);
	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

// 序列化 / 反序列化 二叉树
/*
 * 面试37：
 */
bool ReadStream(istream &stream, int *number) {
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;

	while (!stream.eof() && ch != ',') {
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;

	if (i > 0 && buffer[0] != '$') {
		*number = stoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

void Serialize(const BinTreeNode *pRoot, ostream &stream) {
	if (pRoot == nullptr) {
		stream << "$,";
		return;
	}

	stream << pRoot->val << ',';
	Serialize(pRoot->left, stream);
	Serialize(pRoot->right, stream);
}

void Deserialize(BinTreeNode **pRoot, istream &stream) {
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinTreeNode();
		(*pRoot)->val = number;
		(*pRoot)->left = nullptr;
		(*pRoot)->right = nullptr;

		Deserialize(&((*pRoot)->left), stream);
		Deserialize(&((*pRoot)->right), stream);
	}
}

// BST树 -- 二叉搜索树的第K个结点
/*
 * 面试54：给定一棵二叉搜索树，请找出其中的第K大结点
 * */
const BinTreeNode *KthNodeCore(const BinTreeNode *pRoot, unsigned int &k) {
	const BinTreeNode *target = nullptr;

	if (pRoot->left != nullptr)
		target = KthNodeCore(pRoot->left, k);

	if (target == nullptr) {
		if (k == 1)
			target = pRoot;
		k--;
	}

	if (target == nullptr && pRoot->right != nullptr)
		target = KthNodeCore(pRoot->right, k);

	return target;
}

const BinTreeNode *kthNode(const BinTreeNode *pRoot, unsigned int k) {
	if (pRoot == nullptr || k == 0)
		return nullptr;
	return KthNodeCore(pRoot, k);
}

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

bool T1HaveT2(BinTreeNode *pRoot1, BinTreeNode *pRoot2) {
	if (pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr)
		return false;

	if (!Equal(pRoot1->val, pRoot2->val))
		return false;

	return T1HaveT2(pRoot1->left, pRoot2->left) && T1HaveT2(
			pRoot1->right, pRoot2->right);
}

bool HasSuTree(BinTreeNode *pRoot1, BinTreeNode *pRoot2) {
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

