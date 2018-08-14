//
// Created by ManuelLoaiza on 10/29/17
//
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e+5;
const int ALPH = 10;
int trie[N + 1][ALPH]; // lista de adyacencia trie[prefijo][letraActual]
int nodos;
bool consistente;
bool nodoTerminal[N + 1]; //indica si mi nodo es terminal
 
void inicializar(int cantidad) {
 
	nodos = 1;
	consistente = 1;
	
	for (int i = 0; i <= N; i++) {
		nodoTerminal[i] = 0;
		for (int j = 0; j < ALPH; j++) trie[i][j] = 0;
	}
 
}
 
void aniadirPalabra(string &palabra) {
 
	int tamanio = palabra.size();
	int prefijo = 0; //empezamos en la raiz
	
	for (int i = 0; i < tamanio; i++) {
		if (nodoTerminal[prefijo]) consistente = 0;
		int letraActual = palabra[i] - '0';
		if (trie[prefijo][letraActual] == 0) trie[prefijo][letraActual] = nodos++;
		prefijo = trie[prefijo][letraActual];
	}
 
	nodoTerminal[prefijo] = 1;
 
}
 
bool esPrefijo(string &palabra) {
 
	int tamanio = palabra.size();
	int prefijo = 0;
	
	for (int i = 0; i < tamanio; i++) {
		int letra = palabra[i] - '0';
		if (trie[prefijo][letra] == 0) return 0;
		prefijo = trie[prefijo][letra];
	}
 
	return 1;
 
}
 
bool esPalabra(string &palabra) {
 
	int tamanio = palabra.size();
	int prefijo = 0;
	
	for (int i = 0; i < tamanio; i++) {
		int letra = palabra[i] - '0';
		if (trie[prefijo][letra] == 0) return 0;
		prefijo = trie[prefijo][letra];
	}
 
	return nodoTerminal[prefijo];
 
}
 
void solve() {
	
	int n;
	cin >> n;
	
	inicializar(n);
	
	string numeros[n];
	
	for (int i = 0; i < n; i++) cin >> numeros[i];
	
	sort(numeros, numeros + n);
	
	for (int i = 0; i < n; i++) {
		if (esPalabra(numeros[i])) consistente = 0;
		aniadirPalabra(numeros[i]);
	}
	
	if (consistente) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}
 
int main() {
 
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
 
} 
