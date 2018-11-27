//
// Created by ning on 2018/11/23.
//

#include <stack>
#include "BinaryTree.h"
#include "../Base.h"
#include "../Base.cpp"

using namespace std;
using namespace Algorithm;

// 基本操作
// ----------------------------------------------------------------------------------------
// 连接结点
void Algorithm::ConnectBinaryNodes(BinTreeNode *pParent, BinTreeNode *left, BinTreeNode *right) {
	if (pParent != nullptr) {
		pParent->right = right;
		pParent->left = left;
	}
}

// 打印结点
void Algorithm::PrintBinTreeNode(const BinTreeNode *pNode) {
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
BinTreeNode *Algorithm::stringToBinTreeNode(std::string &input) {
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

	std::vector<BinTreeNode *> vt;
	for (int i = 0; i < in_data.size(); ++i) {
		if (in_data[i] == "#")
			vt.push_back(nullptr);
		else
			vt.push_back(new BinTreeNode(stoi(in_data[i])));
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
void Algorithm::pre_oder(const BinTreeNode *pRoot) {
	if (pRoot != nullptr) {

		cout << pRoot->val << '\t';

		if (pRoot->left != nullptr)
			pre_oder(pRoot->left);

		if (pRoot->right != nullptr)
			pre_oder(pRoot->right);
	}
}

void Algorithm::pre_order_iterate(const BinTreeNode *root) {
	if (root == nullptr)
		return;

	std::stack<BinTreeNode *> s;
	s.push((BinTreeNode *) root);
	while (!s.empty()) {
		BinTreeNode *p = s.top();
		s.pop();
		std::cout << p->val << '\t';    // 根
		// 左 右
		if (p->right)
			s.push(p->right);
		if (p->left)
			s.push(p->left);
	}
}

// 中序  左-根-右
void Algorithm::in_order(const BinTreeNode *pRoot) {
	if (pRoot != nullptr) {
		if (pRoot->left != nullptr)
			in_order(pRoot->left);

		cout << pRoot->val << '\t';

		if (pRoot->right != nullptr)
			in_order(pRoot->right);
	}
}

void Algorithm::in_order_iterate(const Algorithm::BinTreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	std::stack<BinTreeNode *> s;
	BinTreeNode *p = (BinTreeNode *) pRoot;
	while (p != nullptr || !s.empty()) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;        // 左
		} else {
			p = s.top();
			s.pop();
			std::cout << p->val << '\t'; // 根
			p = p->right;  // 右
		}
	}
}

// 后序 左-右-根
void Algorithm::post_order(const BinTreeNode *pRoot) {
	if (pRoot != nullptr) {
		if (pRoot->left != nullptr)
			post_order(pRoot->left);

		if (pRoot->right != nullptr)
			post_order(pRoot->right);

		cout << pRoot->val << '\t';
	}
}

void Algorithm::post_order_iterate(const Algorithm::BinTreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	std::stack<BinTreeNode *> s;
	std::vector<int> res;
	s.push((BinTreeNode *) pRoot);
	while (!s.empty()) {
		BinTreeNode *p = s.top();
		s.pop();
		res.push_back(p->val);
		if (p->left != nullptr)
			s.push(p->left);
		if (p->right != nullptr)
			s.push(p->right);
	}

	// 根-右-左 reverse
	reverse(res.begin(), res.end());
	auto it = res.begin();
	Print(it, res.end());
}

// 同层，按照从左到右顺序. 队列辅助实现
void Algorithm::PrintTreeTopBottom(const BinTreeNode *pRoot) {
	if (pRoot == nullptr)
		return;

	std::deque<const BinTreeNode *> dequeBinTreeNode;
	dequeBinTreeNode.push_back(pRoot);

	while (dequeBinTreeNode.size()) {
		const BinTreeNode *pNode = dequeBinTreeNode.front();
		dequeBinTreeNode.pop_front();

		cout << pNode->val << '\t';

		if (pNode->left)
			dequeBinTreeNode.push_back(pNode->left);

		if (pNode->right)
			dequeBinTreeNode.push_back(pNode->right);
	}
}

// 删除树
void Algorithm::DestroyTree(BinTreeNode *pRoot) {
	if (pRoot != nullptr) {
		BinTreeNode *left = pRoot->left;
		BinTreeNode *right = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(left);
		DestroyTree(right);
	}
}

void Algorithm::test_stringToBinTreeNode() {
	std::string s = "1 2 3 4 5 6 7 # 8 # # 9 10 # # # # # # # #";
	BinTreeNode *root = stringToBinTreeNode(s);
	if (root != nullptr) {
		PrintTreeTopBottom(root);
		Line();
		pre_oder(root);
		Line();
		pre_order_iterate(root);
		Line();
		in_order(root);
		Line();
		in_order_iterate(root);
		Line();
		post_order(root);
		Line();
		post_order_iterate(root);
		Line();
	}
	DestroyTree(root);
}

// root to leaf path
/*
 * 函数功能：结点值 0->9， leetcode
 * */
void Algorithm::rootToLeaf(BinTreeNode *root, std::vector<std::string> &res, std::string s) {
	if (root == nullptr)
		return;
	s += std::to_string(root->val);
	if (root->left == nullptr && root->right == nullptr)
		res.push_back(s);

	if (root->left != nullptr)
		rootToLeaf(root->left, res, s);
	if (root->right != nullptr)
		rootToLeaf(root->right, res, s);
}

int sumNumbers(BinTreeNode *root) {
	if (root == nullptr)
		return 0;

	std::vector<std::string> res;
	rootToLeaf(root, res);

	int result = 0;
	for (int i = 0; i < res.size(); ++i) {
		result += atoi(res[i].c_str());
	}
	return result;
}

bool Algorithm::hasPathSum(BinTreeNode *root, int sum) {
	if (root == nullptr)
		return false;
	if (root->left == nullptr && root->right == nullptr) {
		if (root->val == sum)
			return true;
		else
			return false;
	}

	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int Algorithm::treeMaxDepth(Algorithm::BinTreeNode *root) {
	if (root == nullptr)
		return 0;
	return std::max(treeMaxDepth(root->left), treeMaxDepth(root->right)) + 1;
}

bool isBalanced(BinTreeNode *root) {
	if (root == nullptr)
		return true;
	else
		return std::abs(treeMaxDepth(root->left) - treeMaxDepth(root->right)) < 2 &&
		       isBalanced(root->left) && isBalanced(root->right);
}

void Algorithm::test_path() {
	// "1 2 3 4 5 6 7 # 8 # # 9 # # # # # # # #"
	// "1 # 2 # # # 3"
	std::string s = "1 2 3 4 5 6 7 # 8 # # 9 # # # # # # # #";
	BinTreeNode *root = stringToBinTreeNode(s);
	if (root != nullptr) {
		Line();
		/*
		/*
		 *  1248
		 *  125
		 *  1369
		 *  137
		 * */
		/* std::vector<std::string> res;
		rootToLeaf(root, res);
		auto it = res.begin();
		Print(it, res.end());
		Line();
		// 2879
		std::cout << sumNumbers(root) << std::endl;

		if (hasPathSum(root, 11))
			std::cout << "True" << std::endl;
		*/
		if (isBalanced(root))
			std::cout << "Balanced tree.";
		Line();
		std::cout << treeMaxDepth(root->left) << ' '
		          << treeMaxDepth(root->right) << ' '
		          << treeMaxDepth(root->left->left) << ' '  // 4 # 8
		          << treeMaxDepth(root->right->right); // 7
		Line();
	}

	DestroyTree(root);
}
