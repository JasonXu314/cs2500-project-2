#ifndef SORTER_H
#define SORTER_H

#include <cassert>

#include "utils.h"

template <class T>
class Sorter {
public:
	// Note: I still don't like these things >:(
	// Creates a sorter object
	// Pre: the >, =, and < operators are defined for type T
	// Post: a new Sorter object is created
	Sorter() {}

	void mergeSort(T* arr, int size) const;

	void quickSort(T* arr, int size) const;

	void heapSort(T* arr, int size) const;

	void insertionSort(T* arr, int size) const;

	void mergeInsertionSort(T* arr, int size) const;

private:
	void _merge(T* a, T* b, int aLen, int bLen, T* dest) const;

	void _quickSort(T* arr, int low, int high) const;

	int _partition(T* arr, int low, int high) const;

	void _heapify(T* arr, int size) const;

	void _siftDown(T* arr, int start, int end) const;
};

#include "Sorter.hpp"

#endif