#define DEBUG 0

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include "Benchmarker.h"
#include "Sorter.h"
#include "utils.h"

using namespace std;
using namespace chrono;

int main() {
	Sorter<int> sorter;
	Benchmarker<int> benchmarker([](int* arr, int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}
	});

	cout << scientific;

	cout << "Random Order:" << endl << "Size\t\tMerge Sort\t\tQuick Sort\t\tHeap Sort\t\tMerge-Insertion Sort" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << "\t\t" << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeSort(arr, size); }, SIZES[i], DataArrangement::RANDOM)
			 << "\t\t" << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.quickSort(arr, size); }, SIZES[i], DataArrangement::RANDOM) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.heapSort(arr, size); }, SIZES[i], DataArrangement::RANDOM) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeInsertionSort(arr, size); }, SIZES[i], DataArrangement::RANDOM) << "\t\t"
			 << endl;
	}

	cout << endl << "Reverse Order:" << endl << "Size\t\tMerge Sort\t\tQuick Sort\t\tHeap Sort\t\tMerge-Insertion Sort" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeSort(arr, size); }, SIZES[i], DataArrangement::REVERSE) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.quickSort(arr, size); }, SIZES[i], DataArrangement::REVERSE) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.heapSort(arr, size); }, SIZES[i], DataArrangement::REVERSE) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeInsertionSort(arr, size); }, SIZES[i], DataArrangement::REVERSE) << "\t\t"
			 << endl;
	}

	cout << endl << "Almost Sorted:" << endl << "Size\t\tMerge Sort\t\tQuick Sort\t\tHeap Sort\t\tMerge-Insertion Sort" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeSort(arr, size); }, SIZES[i], DataArrangement::ALMOST_SORTED) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.quickSort(arr, size); }, SIZES[i], DataArrangement::ALMOST_SORTED) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.heapSort(arr, size); }, SIZES[i], DataArrangement::ALMOST_SORTED) << "\t\t"
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeInsertionSort(arr, size); }, SIZES[i], DataArrangement::ALMOST_SORTED)
			 << "\t\t" << endl;
	}

	return 0;
}