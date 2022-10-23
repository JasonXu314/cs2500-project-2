#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include "Sorter.h"
#include "utils.h"

using namespace std;
using namespace chrono;

int main() {
	Sorter<int> sorter;
	default_random_engine rand(time(nullptr));

	cout << scientific;

	cout << "Random Order:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << " elements:" << endl;

		double trials[5] = {0};

		for (int trial = 0; trial < 5; trial++) {
			int* arr = new int[SIZES[i]];

			for (int j = 0; j < SIZES[i]; j++) {
				arr[j] = j;
			}

			shuffle(arr, arr + SIZES[i], rand);

			double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			sorter.mergeSort(arr, SIZES[i]);

			double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			double elapsed = end - start;
			cout << elapsed << "ns\t";
			trials[trial] = elapsed;

			delete[] arr;
		}

		cout << endl << "Average: " << averageTimes(trials, 5) << "ns" << endl << endl;
	}

	cout << "Reverse Order:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << " elements:" << endl;

		double trials[5] = {0};

		for (int trial = 0; trial < 5; trial++) {
			int* arr = new int[SIZES[i]];

			for (int j = 0; j < SIZES[i]; j++) {
				arr[j] = SIZES[i] - j;
			}

			double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			sorter.mergeSort(arr, SIZES[i]);

			double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			double elapsed = end - start;
			cout << elapsed << "ns\t";
			trials[trial] = elapsed;

			delete[] arr;
		}

		cout << endl << "Average: " << averageTimes(trials, 5) << "ns" << endl << endl;
	}

	cout << "Almost Sorted:" << endl;

	for (int i = 0; i < NUM_SIZES; i++) {
		cout << SIZES[i] << " elements:" << endl;

		double trials[5] = {0};

		for (int trial = 0; trial < 5; trial++) {
			int* arr = new int[SIZES[i]];

			// Perform random swaps for 10% of the array
			for (int j = 0; j < SIZES[i] / 10; j++) {
				int a = rand() % SIZES[i], b = rand() % SIZES[i];

				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}

			double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			sorter.mergeSort(arr, SIZES[i]);

			double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

			double elapsed = end - start;
			cout << elapsed << "ns\t";
			trials[trial] = elapsed;

			delete[] arr;
		}

		cout << endl << "Average: " << averageTimes(trials, 5) << "ns" << endl << endl;
	}

	return 0;
}