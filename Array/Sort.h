//
// Created by ning on 2018/11/29.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include <vector>

namespace Algorithm {
	// 1. 归并排序
	std::vector<int> merge_(const std::vector<int> &left, const std::vector<int> &right);

	std::vector<int> mergeSort(const std::vector<int> &arr);

	void testMergeSort();

	// 2. 快排
	int partitionQuickSort(std::vector<int> &arr, int low, int high);

	void quickSort(std::vector<int> &arr, int low, int high);

	void testQuickSort();

	// 3. 堆排
	void heapAdjust(std::vector<int> &arr, int i);

	void buildHeap(std::vector<int> &arr);

	void heapSort(std::vector<int> &arr);

	void testHeapSort();

	// 4. 计数排序
	void countSort(std::vector<int> arr);

	void testCountSort();

	// 5. 桶排序
	void bucketSort(std::vector<int> arr, int bucketSize);

	void testBucketSort();

	// 6. 基数排序
	int getMax(const std::vector<int> arr);

	void countSort(std::vector<int> &arr, int exp);

	void radixSort(std::vector<int> &arr);
}

#endif //ALGORITHM_SORT_H
