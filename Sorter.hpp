template <class T>
void Sorter<T>::insertionSort(T* arr, int size) const {
	// Outer loop invariant is that the array is sorted up to the current index

#if DEBUG == 1
	assert(sorted(arr, 1));	 // 1 is the initial value of j
#endif

	for (int j = 1; j < size; j++) {
#if DEBUG == 1
		assert(sorted(arr, j));	 // the array is sorted up to (but not including) j
#endif

		T elem = arr[j];
		int i = j - 1;

		for (; i >= 0 && arr[i] > elem; i--) {
			arr[i + 1] = arr[i];
		}

		arr[i + 1] = elem;

#if DEBUG == 1
		assert(sorted(arr, j));	 // the array is still sorted up to j
#endif
	}

#if DEBUG == 1
	assert(sorted(arr, size));	// the array is now fully sorted (array is sorted up to size)
#endif
}

template <class T>
void Sorter<T>::mergeSort(T* arr, int size) const {
	if (size <= 1) {
#if DEBUG == 1
		assert(sorted(arr, size));	// Base Case: the array is trivially sorted if it has 1 element, or vacuously sorted if it has 0 elements
#endif
		return;
	}

	int firstHalfLength = size / 2, secondHalfLength = size - firstHalfLength;

	T *a = new T[firstHalfLength], *b = new T[secondHalfLength];

	for (int i = 0; i < firstHalfLength; i++) {
		a[i] = arr[i];
	}

	for (int i = 0; i < secondHalfLength; i++) {
		b[i] = arr[firstHalfLength + i];
	}

	mergeSort(a, firstHalfLength);
	mergeSort(b, secondHalfLength);

	_merge(a, b, firstHalfLength, secondHalfLength, arr);
#if DEBUG == 1
	assert(sorted(arr, size));	// Post-recombination: The array is now sorted
#endif

	delete[] a;
	delete[] b;
}

template <class T>
void Sorter<T>::mergeInsertionSort(T* arr, int size) const {
	if (size <= 1) {
#if DEBUG == 1
		assert(sorted(arr, size));	// Base Case: the array is trivially sorted if it has 1 element, or vacuously sorted if it has 0 elements
#endif
		return;
	}

	if (size <= 360) {
		insertionSort(arr, size);
#if DEBUG == 1
		assert(sorted(arr, size));	// We can assume insertion sort is implemented correctly, so this becomes another Base Case
#endif
		return;
	}

	int firstHalfLength = size / 2, secondHalfLength = size - firstHalfLength;

	T *a = new T[firstHalfLength], *b = new T[secondHalfLength];

	for (int i = 0; i < firstHalfLength; i++) {
		a[i] = arr[i];
	}

	for (int i = 0; i < secondHalfLength; i++) {
		b[i] = arr[firstHalfLength + i];
	}

	mergeSort(a, firstHalfLength);
	mergeSort(b, secondHalfLength);

	_merge(a, b, firstHalfLength, secondHalfLength, arr);
#if DEBUG == 1
	assert(sorted(arr, size));	// Post-recombination: The array is now sorted
#endif

	delete[] a;
	delete[] b;
}

template <class T>
void Sorter<T>::_merge(T* a, T* b, int aLen, int bLen, T* dest) const {
	int aIndex = 0, bIndex = 0;

	for (int i = 0; i < aLen + bLen; i++) {
		if (aIndex >= aLen) {
			dest[i] = b[bIndex++];
		} else if (bIndex >= bLen) {
			dest[i] = a[aIndex++];
		} else if (a[aIndex] < b[bIndex]) {
			dest[i] = a[aIndex++];
		} else {
			dest[i] = b[bIndex++];
		}
	}
}

template <class T>
void Sorter<T>::quickSort(T* arr, int size) const {
	_quickSort(arr, 0, size - 1);
}

template <class T>
void Sorter<T>::_quickSort(T* arr, int low, int high) const {
	if (low >= 0 && high >= 0 && low < high) {
		int pivot = _partition(arr, low, high);

		_quickSort(arr, low, pivot);
		_quickSort(arr, pivot + 1, high);

#if DEBUG == 1
		assert(sorted(arr, low, high + 1));	 // Post-recombination: The array is now sorted
#endif
	} else {
		// Base Case: The array is trivially sorted if low and high have crossed, since there is no array to sort.
	}
}

template <class T>
int Sorter<T>::_partition(T* arr, int low, int high) const {
	T pivot = arr[(high + low) / 2];
	int i = low - 1, j = high + 1;

	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j) {
			return j;
		}

		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

template <class T>
void Sorter<T>::heapSort(T* arr, int size) const {
	_heapify(arr, size);

	int end = size - 1;

#if DEBUG == 1
	assert(sorted(arr, end, size));	 // Setup: the last 0 elements of the array are sorted (since end is size - 1)
#endif

	while (end > 0) {
#if DEBUG == 1
		assert(sorted(arr, end, size));	 // Initialization: the last (size - end - 1) elements of the array are sorted
#endif

		T temp = arr[end];
		arr[end] = arr[0];
		arr[0] = temp;

		end--;

		_siftDown(arr, 0, end);

#if DEBUG == 1
		assert(sorted(arr, end, size));	 // Maintenance: the last (size - end - 1) elements of the array are still sorted
#endif
	}

#if DEBUG == 1
	assert(sorted(arr, 0, size));  // Termination: the entire array is now sorted, since end is now 0 (if the last size - 1 elements are sorted, the
								   // one remaining element is necessarily sorted by pidgeonhole principle)
#endif
}

template <class T>
void Sorter<T>::_heapify(T* arr, int size) const {
	int start = floor((size - 2) / 2);	// the parent of the last element (aka the last node on the second-to-lowest layer)

	while (start >= 0) {
		_siftDown(arr, start, size - 1);
		start--;
	}
}

template <class T>
void Sorter<T>::_siftDown(T* arr, int start, int end) const {
	int root = start;

	while (root * 2 <= end) {
		int childIndex = root * 2, swapTarget = root;

		if (arr[swapTarget] < arr[childIndex]) {
			swapTarget = childIndex;
		}

		if (childIndex + 1 <= end && arr[swapTarget] < arr[childIndex + 1]) {
			swapTarget = childIndex + 1;
		}

		if (swapTarget == root)
			return;
		else {
			T temp = arr[swapTarget];
			arr[swapTarget] = arr[root];
			arr[root] = temp;
			root = swapTarget;
		}
	}
}