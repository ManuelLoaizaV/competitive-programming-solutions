//
// Created by ManuelLoaiza on 04/05/18
//
#include <bits/stdc++.h>

using namespace std;

const double ABS = 1e-8;

int p, q, r, s, t, u;

double f(double x) {
	return p * exp(- x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double binarySearch(double left, double right) {
	double middle, middleValue, leftValue, rightValue;
	while (right - left >= ABS) {
		middle = (left + right) / 2;
		leftValue = f(left);
		rightValue = f(right);
		middleValue = f(middle);		
		if (abs(middleValue) <= ABS) return middle;
		else {
			if (leftValue < 0 and rightValue < 0 or
				leftValue > 0 and rightValue > 0) {
					return -1;
			}
			if (middleValue < 0) {
				if (leftValue < 0) left = middle;
				else right = middle;
			} else { // middleValue > 0 
				if (leftValue > 0) left = middle;
				else right = middle;
			}
		}
	}
	return middle;
}

int main() {
	double answer;
	while (cin >> p >> q >> r >> s >> t >> u) {
		answer = binarySearch(0.0, 1.0);
		if (answer == -1) cout << "No solution" << endl;
		else cout << fixed << setprecision(4) << answer << endl;
	}
	return 0;
}

