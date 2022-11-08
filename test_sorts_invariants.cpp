#define DEBUG 1

#include <algorithm>
#include <cassert>
#include <ctime>
#include <random>

#include "Incomparable.h"
#include "Sorter.h"
#include "utils.h"

using namespace std;

int main() {
	default_random_engine rand(time(nullptr));
	int arr[100];
	// Incomparable arr[100];
	Sorter<int> sorter;
	// Sorter<Incomparable> sorter;

	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}

	shuffle(arr, arr + 100, rand);
	sorter.mergeSort(arr, 100);
	assert(sorted(arr, 100));

	shuffle(arr, arr + 100, rand);
	sorter.quickSort(arr, 100);
	assert(sorted(arr, 100));

	shuffle(arr, arr + 100, rand);
	sorter.heapSort(arr, 100);
	assert(sorted(arr, 100));

	shuffle(arr, arr + 100, rand);
	sorter.mergeInsertionSort(arr, 100);
	assert(sorted(arr, 100));

	return 0;
}