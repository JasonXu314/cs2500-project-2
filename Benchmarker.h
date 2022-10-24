#ifndef BENCHMARKER_H
#define BENCHMARKER_H

#include <chrono>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>

#include "utils.h"

enum DataArrangement { RANDOM, REVERSE, ALMOST_SORTED };

template <typename T>
class Benchmarker {
public:
	Benchmarker(std::function<void(T*, int)> generateData);

	double benchmark(std::function<void(T*, int)> fn, int size, DataArrangement dataType);

	~Benchmarker();

private:
	T* _data;
	std::function<void(T*, int)> _generateData;
	std::default_random_engine _rand;

	void _setupData(int size, DataArrangement dataType);
};

#include "Benchmarker.hpp"

#endif