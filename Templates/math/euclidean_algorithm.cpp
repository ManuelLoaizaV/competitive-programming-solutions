#include <bits/stdc++.h>
using namespace std;

// Recursive implementation
int gcd_1(int a, int b) {
	if (b == 0) return a;
	return gcd_1(b, a % b);
}

// Iterative implementation
int gcd_2(int a, int b) {
	while (b != 0) {
		a = a % b;
		swap(a, b);	
	}
	return a;
}

// a * b = lcm(a, b) * gcd(a, b)
int lcm(int a, int b) {
	return a / gcd_1(a, b) * b;
}

// Extended Euclidean Algorithm
// a * x + b * y = gcd(a, b)
// La identidad de Bezout garantiza que existe x, y enteros que cumplen dicha condicion
// Este algoritmo permite hallar el gcd(a, b) y al mismo tiempo dos enteros x, y
int extended_gcd(int a, int b, int *x, int *y) {
	if (b == 0) {
		(*x) = 1;
		(*y) = 0; 
		return a;
	}
	int x1, y1;
	int g = extended_gcd(b, a % b, &x1, &y1);
	(*x) = y1;
	(*y) = x1 - y1 * (a / b);
	return g;
}

int main() {
	// Tomando en cuenta que a >= b
	int a = 945;
	int b = 483;
	// Calculando el gcd de iterativa y recursivamente, asi como el lcm
	printf("gcd(%d,%d) = %d\n", a, b, gcd_1(a,b));
	printf("gcd(%d,%d) = %d\n", a, b, gcd_2(a,b));
	printf("lcm(%d,%d) = %d\n", a, b, lcm(a,b));
	// Hallo dos numeros enteros que verifiquen la identidad de Bezout
	int x, y;
	int g = extended_gcd(a, b, &x, &y);
	printf("%d * %d + %d * %d = %d\n", a, x, b, y, g);
	return 0;
}
