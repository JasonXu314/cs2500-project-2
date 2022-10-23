template <class T>
void Sorter<T>::insertionSort(T* arr, int size) {
	for (int j = 1; j < size; j++) {
		T elem = arr[j];
		int i = j - 1;

		for (; i >= 0 && arr[i] > elem; i--) {
			arr[i + 1] = arr[i];
		}

		arr[i + 1] = elem;
	}
}

template <class T>
void Sorter<T>::mergeSort(T* arr, int size) {
	if (size <= 1) {
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

	delete[] a;
	delete[] b;
}

template <class T>
void Sorter<T>::mergeInsertionSort(T* arr, int size) {
	if (size <= 1) {
		return;
	}

	if (size <= 10) {
		insertionSort(arr, size);
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

	delete[] a;
	delete[] b;
}

template <class T>
void Sorter<T>::_merge(T* a, T* b, int aLen, int bLen, T* dest) {
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
void Sorter<T>::quickSort(T* arr, int size) {
	_quickSort(arr, 0, size - 1);
}

template <class T>
void Sorter<T>::_quickSort(T* arr, int low, int high) {
	if (low >= 0 && high >= 0 && low < high) {
		int pivot = _partition(arr, low, high);

		_quickSort(arr, low, pivot);
		_quickSort(arr, pivot + 1, high);
	}
}

template <class T>
int Sorter<T>::_partition(T* arr, int low, int high) {
	T pivot = arr[static_cast<int>(floor((high + low) / 2))];
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
void Sorter<T>::heapSort(T* arr, int size) {
	_heapify(arr, size);

	int end = size - 1;

	while (end > 0) {
		T temp = arr[end];
		arr[end] = arr[0];
		arr[0] = temp;

		end--;

		_siftDown(arr, 0, end);
	}
}

template <class T>
void Sorter<T>::_heapify(T* arr, int size) {
	int start = floor((size - 2) / 2);	// the parent of the last element (aka the last node on the second-to-lowest layer)

	while (start >= 0) {
		_siftDown(arr, start, size - 1);
		start--;
	}
}

template <class T>
void Sorter<T>::_siftDown(T* arr, int start, int end) {
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