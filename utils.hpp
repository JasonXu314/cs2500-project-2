template <typename T>
bool sorted(T* arr, unsigned int n) {
	return sorted(arr, 0, n);
}

template <typename T>
bool sorted(T* arr, unsigned int a, unsigned int b) {
	for (unsigned int i = a; i < b - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}

	return true;
}

double averageTimes(double* times, unsigned int n) {
	double sum = 0;

	for (unsigned int i = 0; i < n; i++) {
		sum += times[i];
	}

	return sum / n;
}