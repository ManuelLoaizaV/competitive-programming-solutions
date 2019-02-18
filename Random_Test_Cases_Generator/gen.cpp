#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// ./gen semilla
	// mandar numero como argumento al ejecutar gen para cambiar la semilla
	srand(atoi(argv[1]));
	// Si el constraint es de a <= n <= b
	// n = rand(a, b)
	int n = rand(2, 5e4);
	cout << n << endl;
	set<int> used;
	for (int i = 0; i < n; i++) {
		int x;
		//do {
			// Si el constraint es a <= x <= b
			// x = rand(a, b)
			x = rand(1, 100);
		//} while (used.count(x));
		cout << x << " ";
		used.insert(x);
	}
	// Guardar el test case en un archivo
	// ./gen semilla > testCase
	return 0;
}