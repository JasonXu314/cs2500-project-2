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

	// Sorts the given array using the Merge Sort algorithm
	// Pre: size is the length of array arr
	// Post: arr is sorted in ascending order
	void mergeSort(T* arr, int size) const;

	// Sorts the given array using the Quick Sort algorithm
	// Pre: size is the length of array arr
	// Post: arr is sorted in ascending order
	void quickSort(T* arr, int size) const;

	// Sorts the given array using the Heap Sort algorithm
	// Pre: size is the length of array arr
	// Post: arr is sorted in ascending order
	void heapSort(T* arr, int size) const;

	// Sorts the given array using the Insertion Sort algorithm
	// Pre: size is the length of array arr
	// Post: arr is sorted in ascending order
	void insertionSort(T* arr, int size) const;

	// Sorts the given array using the Merge Sort algorithm, but switches to Insertion Sort when the array is small enough
	// Pre: size is the length of array arr
	// Post: arr is sorted in ascending order
	void mergeInsertionSort(T* arr, int size) const;

private:
	// Merges two sorted arrays into the destination array dest
	// Pre: a and b are sorted arrays, aLen and bLen are the lengths of a and b, respectively, dest is an array of size aLen + bLen
	// Post: dest is sorted in ascending order
	void _merge(T* a, T* b, int aLen, int bLen, T* dest) const;

	// Sorts the given array using the Quick Sort algorithm
	// Pre: low and high are both less than the size of array arr
	// Post: arr is sorted in ascending order from index low to index high
	void _quickSort(T* arr, int low, int high) const;

	// Partitions the array on the interval [low, high] around the pivot whose index is returned (using Hoare's partition scheme, because that's what I
	// learned in high school)
	// Pre: arr is an array, in which low and high are valid indices
	// Post: partitions the array according to Hoare's partition scheme and returns the pivot index
	int _partition(T* arr, int low, int high) const;

	// Arranges the elements of the given array into a heap structure
	// Pre: size is the length of array arr
	// Post: arr is arranged into a heap structure
	void _heapify(T* arr, int size) const;

	// Moves the element at the given index down the heap structure of arr until it is in the correct position
	// Pre: arr is in a heap structure, except for the element at start, size is the length of array arr, start and end are valid indices of arr
	// Post: the heap structure of arr is restored
	void _siftDown(T* arr, int start, int end) const;
};

#include "Sorter.hpp"

#endif