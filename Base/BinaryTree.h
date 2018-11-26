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
	class BinTreeNode {
	public:

		BinTreeNode() : val(0), left(nullptr), right(nullptr) {}

		BinTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}


	public:
		int val;
		BinTreeNode *left;
		BinTreeNode *right;
	};

	void ConnectBinaryNodes(BinTreeNode *pParent, BinTreeNode *left, BinTreeNode *right);

	void PrintBinTreeNode(const BinTreeNode *pNode);

	BinTreeNode *stringToBinTreeNode(std::string &input);

	void pre_oder(const BinTreeNode *pRoot);

	void pre_order_iterate(const BinTreeNode *root);

	void in_order(const BinTreeNode *pRoot);

	void post_order(const BinTreeNode *pRoot);

	void PrintTreeTopBottom(const BinTreeNode *pRoot);

	void DestroyTree(BinTreeNode *pRoot);

	void test_stringToBinTreeNode();
}


#endif //ALGORITHM_BINARYTREE_H
