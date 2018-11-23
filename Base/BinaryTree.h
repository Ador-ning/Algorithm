//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_BINARYTREE_H
#define ALGORITHM_BINARYTREE_H

#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

namespace Algorithm {
	struct BinaryTreeNode {
		int val;
		BinaryTreeNode *left;
		BinaryTreeNode *right;

		BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}

		BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};


// 创建结点
	BinaryTreeNode *CreateBinaryTreeNode(int val) {
		BinaryTreeNode *pNode = new BinaryTreeNode();
		pNode->val = val;
		pNode->left = nullptr;
		pNode->right = nullptr;

		return pNode;
	}

// 二叉树结点的查找、修改 -- 在二叉树中找到所有数据域为给定数据域的结点，并将它们修改为给定的数据
	void search(BinaryTreeNode *root, int x, int newdata) {
		if (root == nullptr)
			return; // base

		if (root->val == x)
			root->val = newdata; // 修改数据

		search(root->left, x, newdata); // 修改左子树
		search(root->right, x, newdata); // 修改右子树
	}

// 连接结点
	void ConnectBinaryNodes(BinaryTreeNode *pParent, BinaryTreeNode *left, BinaryTreeNode *right) {
		if (pParent != nullptr) {
			pParent->right = right;
			pParent->left = left;
		}
	}

// 打印结点
	void PrintTreeNode(const BinaryTreeNode *pNode) {
		if (pNode != nullptr) {
			cout << "Value of its node is :" << pNode->val << "." << endl;

			if (pNode->left != nullptr)
				cout << "Value of its left child is :" << pNode->left->val << "." << endl;
			else
				cout << " No left child." << endl;

			if (pNode->right != nullptr)
				cout << "Value of its right child is :" << pNode->right->val << "." << endl;
			else
				cout << " No right child." << endl;
		} else {
			cout << "This node is nullptr." << endl;
		}
		cout << endl;
	}

// 删除树
	void DestroyTree(BinaryTreeNode *pRoot) {
		if (pRoot != nullptr) {
			BinaryTreeNode *left = pRoot->left;
			BinaryTreeNode *right = pRoot->right;

			delete pRoot;
			pRoot = nullptr;

			DestroyTree(left);
			DestroyTree(right);
		}
	}

// 打印树 -- 先序  根-左-右
	void pre_oder(const BinaryTreeNode *pRoot) {
		if (pRoot != nullptr) {

			cout << pRoot->val << '\t';

			if (pRoot->left != nullptr)
				pre_oder(pRoot->left);

			if (pRoot->right != nullptr)
				pre_oder(pRoot->right);
		}
	}

// 中序  左-根-右
	void in_order(const BinaryTreeNode *pRoot) {
		if (pRoot != nullptr) {
			if (pRoot->left != nullptr)
				in_order(pRoot->left);

			cout << pRoot->val << '\t';

			if (pRoot->right != nullptr)
				in_order(pRoot->right);
		}
	}

// 后序 左-右-根
	void post_order(const BinaryTreeNode *pRoot) {
		if (pRoot != nullptr) {
			if (pRoot->left != nullptr)
				post_order(pRoot->left);

			if (pRoot->right != nullptr)
				post_order(pRoot->right);

			cout << pRoot->val << '\t';
		}
	}

// 同层，按照从左到右顺序. 队列辅助实现
	void PrintTreeTopBottom(const BinaryTreeNode *pRoot) {
		if (pRoot == nullptr)
			return;

		std::deque<const BinaryTreeNode *> dequeTreeNode;
		dequeTreeNode.push_back(pRoot);

		while (dequeTreeNode.size()) {
			const BinaryTreeNode *pNode = dequeTreeNode.front();
			dequeTreeNode.pop_front();

			cout << "%d\t" << pNode->val;

			if (pNode->left)
				dequeTreeNode.push_back(pNode->left);

			if (pNode->right)
				dequeTreeNode.push_back(pNode->right);
		}
	}

// 二叉树所有 根->叶子 路径和为 sum

// 二叉树深度
/*
 * 面试55：输入一棵二叉树的根结点，求该树的深度
 * 从根结点到叶结点一次经过的结点（含根、叶结点）形成树的一条路径，最长路径为其深度
 */
	int TreeDepth(const BinaryTreeNode *pRoot) {
		if (pRoot == nullptr)   // 空树 或者 叶结点
			return 0;

		int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);
		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	}


	void test_BinaryTree() {
		BinaryTreeNode b1 = BinaryTreeNode(1);
		BinaryTreeNode b2 = BinaryTreeNode(2);
		BinaryTreeNode b3 = BinaryTreeNode(3);
		BinaryTreeNode b4 = BinaryTreeNode(4);
		BinaryTreeNode b5 = BinaryTreeNode(5);
		BinaryTreeNode b6 = BinaryTreeNode(6);

		ConnectBinaryNodes(&b1, &b2, &b3);
		ConnectBinaryNodes(&b2, &b4, nullptr);
		ConnectBinaryNodes(&b3, &b6, &b5);
		pre_oder(&b1);
		cout << endl;
		in_order(&b1);
		cout << endl;
		post_order(&b1);
	}

// =====================================================================//
// =====================================================================//


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

	void Serialize(const BinaryTreeNode *pRoot, ostream &stream) {
		if (pRoot == nullptr) {
			stream << "$,";
			return;
		}

		stream << pRoot->val << ',';
		Serialize(pRoot->left, stream);
		Serialize(pRoot->right, stream);
	}

	void Deserialize(BinaryTreeNode **pRoot, istream &stream) {
		int number;
		if (ReadStream(stream, &number)) {
			*pRoot = new BinaryTreeNode();
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
	const BinaryTreeNode *KthNodeCore(const BinaryTreeNode *pRoot, unsigned int &k) {
		const BinaryTreeNode *target = nullptr;

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

	const BinaryTreeNode *kthNode(const BinaryTreeNode *pRoot, unsigned int k) {
		if (pRoot == nullptr || k == 0)
			return nullptr;
		return KthNodeCore(pRoot, k);
	}
}
#endif //ALGORITHM_BINARYTREE_H
