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

	// Partitions the array on the interval [low, high] around the pivot whose index is returned (using Hoare's partition scheme, because that's what I
	// learned in high school)
	// Pre: arr is an array, in which low and high are valid indices
	// Post: partitions the array according to Hoare's partition scheme and returns the pivot index
	int _partition(T* arr, int low, int high) const;

	void _heapify(T* arr, int size) const;

	void _siftDown(T* arr, int start, int end) const;
};

#include "Sorter.hpp"

#endif