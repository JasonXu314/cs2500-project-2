using namespace std;

template <typename T>
Benchmarker<T>::Benchmarker(function<void(T*, int)> generateData) : _data(nullptr), _generateData(generateData) {
	_rand = default_random_engine(time(nullptr));
}

template <typename T>
double Benchmarker<T>::benchmark(std::function<void(T*, int)> fn, int size, DataArrangement dataType) {
	int times[5] = {0};

	for (int i = 0; i < 5; i++) {
		_data = new T[size];
		_setupData(size, dataType);

		double start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

		fn(_data, size);

		double end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();

		double elapsed = end - start;
		times[i] = elapsed;

		delete[] _data;
	}

	return averageTimes(times, 5);
}

template <typename T>
void Benchmarker<T>::_setupData(int size, DataArrangement dataType) {
	_generateData(_data, size);

	switch (dataType) {
		case DataArrangement::RANDOM:
			shuffle(_data, _data + size, _rand);
			break;
		case DataArrangement::REVERSE:
			for (int i = 0; i < size / 2; i++) {
				T temp = _data[i];
				_data[i] = _data[size - i - 1];
				_data[size - i - 1] = temp;
			}
			break;
		case DataArrangement::ALMOST_SORTED:
			// Perform random swaps for 10% of the array
			for (int j = 0; j < size / 10; j++) {
				int a = _rand() % size, b = _rand() % size;

				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
			break;
		default:
			cerr << "Invalid data arrangement type" << endl;
			break;
	}
}

template <typename T>
Benchmarker<T>::~Benchmarker() {
	delete[] _data;
}