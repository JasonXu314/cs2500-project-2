#define DEBUG 0

#include <iomanip>
#include <iostream>

#include "Benchmarker.h"
#include "Sorter.h"

using namespace std;

int main() {
	Sorter<int> sorter;
	Benchmarker<int> benchmarker([](int* arr, int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = i;
		}
	});

	cout << scientific;

	for (int size = 200; size <= 400; size += 10) {
		cout << size << " elements:" << endl;
		cout << "Merge Sort: " << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.mergeSort(arr, size); }, size, DataArrangement::RANDOM)
			 << "ns, Insertion Sort: "
			 << benchmarker.benchmark([&sorter](int* arr, int size) { sorter.insertionSort(arr, size); }, size, DataArrangement::RANDOM) << "ns" << endl;
	}

	return 0;
}