#ifndef INCOMPARABLE_H
#define INCOMPARABLE_H

struct Incomparable {
	int n;

	Incomparable& operator=(int _n) {
		n = _n;
		return *this;
	}
};

// bool operator>(const Incomparable& a, const Incomparable& b) { return a.n > b.n; }

// bool operator<(const Incomparable& a, const Incomparable& b) { return a.n < b.n; }

// bool operator==(const Incomparable& a, const Incomparable& b) { return a.n == b.n; }

#endif