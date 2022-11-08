template <typename T>
bool sorted(T* arr, int n) {
	return sorted(arr, 0, n);
}

template <typename T>
bool sorted(T* arr, int a, int b) {
	for (int i = a; i < b - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}

	return true;
}

double averageTimes(double* times, int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += times[i];
	}

	return sum / n;
}