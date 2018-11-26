//
// Created by ning on 2018/11/23.
//

#ifndef ALGORITHM_BINARYTREE_H
#define ALGORITHM_BINARYTREE_H

#include <iostream>
#include <deque>
#include <queue>
#include <fstream>
#include <vector>
#include "../Base.h"

using namespace std;

namespace Algorithm {
	class TreeNode {
	public:

		TreeNode() : val(0), left(nullptr), right(nullptr) {}

		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}


	public:
		int val;
		TreeNode *left;
		TreeNode *right;
	};

	// 基本操作
	// ----------------------------------------------------------------------------------------
	// 连接结点
	void ConnectBinaryNodes(TreeNode *pParent, TreeNode *left, TreeNode *right) {
		if (pParent != nullptr) {
			pParent->right = right;
			pParent->left = left;
		}
	}

	// 打印结点
	void PrintTreeNode(const TreeNode *pNode) {
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

	// 层序生成完全二叉树
	// 1 2 3 4 5 6 7 # 8 # # 9 10 # # # # # # # #
	TreeNode *stringToTreeNode(std::string &input) {
		if (input.size() <= 0)
			return nullptr;

		std::vector<std::string> in_data = Algorithm::stringToStringVector(input);

		if (DEBUG) {
			std::cout << "Debug info: the input data convert to vector string is: ";
			auto it = in_data.begin();
			Print(it, in_data.end());
			std::cout << std::endl;
		}

		if (in_data[0] == "#") {
			std::cout << "The root value must not # !";
			return nullptr;
		}

		std::vector<TreeNode *> vt;
		for (int i = 0; i < in_data.size(); ++i) {
			if (in_data[i] == "#")
				vt.push_back(nullptr);
			else
				vt.push_back(new TreeNode(stoi(in_data[i])));
		}

		int i = 0;
		while ((i + 1) * 2 < vt.size()) {
			if (vt[i] == nullptr && (vt[(i + 1) * 2 - 1] != nullptr || vt[(i + 1) * 2] != nullptr)) {
				std::cout << "The input sequence is not layer." << std::endl;
				return nullptr;
			}

			if (vt[i] == nullptr && vt[(i + 1) * 2 - 1] == nullptr && vt[(i + 1) * 2] == nullptr) {
				i += 1;
				continue; // 继续向后检查
			}

			vt[i]->left = vt[(i + 1) * 2 - 1];
			vt[i]->right = vt[(i + 1) * 2];
			i += 1;
		}

		return vt[0];
	}

	// 树遍历 -- recursive version
	// 打印树 -- 先序  根-左-右
	void pre_oder(const TreeNode *pRoot) {
		if (pRoot != nullptr) {

			cout << pRoot->val << '\t';

			if (pRoot->left != nullptr)
				pre_oder(pRoot->left);

			if (pRoot->right != nullptr)
				pre_oder(pRoot->right);
		}
	}


	// 中序  左-根-右
	void in_order(const TreeNode *pRoot) {
		if (pRoot != nullptr) {
			if (pRoot->left != nullptr)
				in_order(pRoot->left);

			cout << pRoot->val << '\t';

			if (pRoot->right != nullptr)
				in_order(pRoot->right);
		}
	}

	// 后序 左-右-根
	void post_order(const TreeNode *pRoot) {
		if (pRoot != nullptr) {
			if (pRoot->left != nullptr)
				post_order(pRoot->left);

			if (pRoot->right != nullptr)
				post_order(pRoot->right);

			cout << pRoot->val << '\t';
		}
	}

	// 同层，按照从左到右顺序. 队列辅助实现
	void PrintTreeTopBottom(const TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;

		std::deque<const TreeNode *> dequeTreeNode;
		dequeTreeNode.push_back(pRoot);

		while (dequeTreeNode.size()) {
			const TreeNode *pNode = dequeTreeNode.front();
			dequeTreeNode.pop_front();

			cout << pNode->val << '\t';

			if (pNode->left)
				dequeTreeNode.push_back(pNode->left);

			if (pNode->right)
				dequeTreeNode.push_back(pNode->right);
		}
	}

	// 删除树
	void DestroyTree(TreeNode *pRoot) {
		if (pRoot != nullptr) {
			TreeNode *left = pRoot->left;
			TreeNode *right = pRoot->right;

			delete pRoot;
			pRoot = nullptr;

			DestroyTree(left);
			DestroyTree(right);
		}
	}

	void test_stringTorTreeNode() {
		std::string s = "1 2 3 4 5 6 7 # 8 # # 9 10 # # # # # # # #";
		TreeNode *root = stringToTreeNode(s);
		if (root != nullptr) {
			PrintTreeTopBottom(root);
			std::cout << std::endl;
			pre_oder(root);
			std::cout << std::endl;
			in_order(root);
			std::cout << std::endl;
			post_order(root);
			std::cout << std::endl;
		}
		DestroyTree(root);
	}

}


#endif //ALGORITHM_BINARYTREE_H
