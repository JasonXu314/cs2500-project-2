#ifndef UTILS_H
#define UTILS_H

#define NUM_SIZES 6

int SIZES[] = {10, 1000, 10000, 100000, 200000, 500000};

// Note: I still don't like these things >:(
// Tests whether the array is sorted in ascending order on the interval [0, n)
// Pre: arr is a valid array of size n, the > operator is defined for type T
// Post: returns true if the array is sorted in ascending order on the interval [0, n), false otherwise
template <typename T>
bool sorted(T* arr, int n);

// Note: I still don't like these things >:(
// Tests whether the array is sorted in ascending order on the interval [a, b)
// Pre: arr is a valid array of size n, the > operator is defined for type T
// Post: returns true if the array is sorted in ascending order on the interval [a, b), false otherwise
template <typename T>
bool sorted(T* arr, int a, int b);

// Note: I still don't like these things >:(
// Calculates the average of the times given
// Pre: n is the size of the times array
// Post: returns the average of the times given
double averageTimes(double* times, int n);

#include "utils.hpp"

#endif