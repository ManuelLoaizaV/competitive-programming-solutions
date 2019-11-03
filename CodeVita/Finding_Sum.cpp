//
// Creado por ManuelLoaiza el 12/11/2017
//

#include <bits/stdc++.h>

using namespace std;

const int mod = 1009;

void limpiar(string &texto) {	
	int l = texto.size();
	for (int i = 0; i < l; i++) {
		if (texto[i] == ',') texto[i] = ' ';
	}
	
}

int main() {
	int n, p;
	string linea;
	cin >> linea;
	limpiar(linea);
	stringstream ss(linea);
	ss >> n >> p;	
	
	int numeros[n];
	cin >> linea;
	limpiar(linea);
	stringstream ss2(linea);
	
	for (int i = 0; i < n; i++) {
		ss2 >> numeros[i];
	}
	
	long long resultado = 0;
	
	if (n < 3) {
		cout << resultado;
		return 0;
	}
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int s = numeros[i] + numeros[j] + numeros[k];
				if (s % p == 0) resultado++;
			}
		}
	}
	
	resultado = resultado % mod;
	cout << resultado;
		
	return 0;
}
