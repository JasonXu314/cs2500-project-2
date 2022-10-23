#ifndef SORTER_H
#define SORTER_H

#include <cassert>

#include "utils.h"

template <class T>
class Sorter {
public:
	// Note: I believe that this sort of comment is inherently HARMFUL to code readability, but since your rubric requires me to write it, here it is
	// Creates a sorter object
	// Pre: the >, =, and < operators are defined for type T
	// Post: a new Sorter object is created
	Sorter() {}

	void mergeSort(T* arr, int size);

	void quickSort(T* arr, int size);

	void heapSort(T* arr, int size);

	void insertionSort(T* arr, int size);

	void mergeInsertionSort(T* arr, int size);

private:
	void _merge(T* a, T* b, int aLen, int bLen, T* dest);

	void _quickSort(T* arr, int low, int high);

	int _partition(T* arr, int low, int high);

	void _heapify(T* arr, int size);

	void _siftDown(T* arr, int start, int end);
};

#include "Sorter.hpp"

#endif