//
// Created by ning on 2018/11/26.
//

#include <vector>

#include "BinaryTree.h"
#include "LinkListProblem.h"
#include "UnionFind.h"
#include "Heap.h"

using namespace Algorithm;
using std::vector;

int main() {
	std::cout << "base test: " << std::endl;
	// test_stringToBinTreeNode();
	// test_removeNthFromEnd();
	// test_addTwoNumbers();
	// test_getIntersectionNode();
	// test_UnionFind();

	vector<int> nums = {2, 3, 4, 8, 0, 2, 9, 3};
	HeapSort *heap = new HeapSort(nums);
	heap->build();
	heap->deleteTop();
	// heap->insert(-1);
	heap->insert(7);
	heap->insert(-1);
}