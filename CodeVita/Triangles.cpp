//
// Creado por ManuelLoaiza el 12/11/2017
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
int angulos[MAX];

void limpiar(string &texto) {
	int l = texto.size();
	for (int i = 0; i < l; i++) {
		if (texto[i] == ',') texto[i] = ' ';
	}
}

bool esPosible(int x, int y, int z) {
	return angulos[x] != angulos[y] and angulos[x] != angulos[z] and angulos[y] != angulos[z];
}

int main() {
	int n;
	cin >> n;
	
	string numeros;
	cin >> numeros;
	limpiar(numeros);
	stringstream numerosLimpio(numeros);
		
	for (int i = 0; i < n; i++) {
		numerosLimpio >> angulos[i];
	}
	
	int resultado = 0;
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (esPosible(i, j, k)) resultado++;
			}
		}
	}
	
	cout << resultado;
	return 0;	
}
