#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
using namespace std;
const int MAX_N = 100;
vector<int> adj[MAX_N];
bool isCycle;
int compSize;
int state[MAX_N];

void dfs(int u, int p) {
	compSize++;
	state[u] = 1;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (state[v] == 0) {
			dfs(v, u);
		} else { 
			// state[v] == 1
			// Si v esta siendo visitado y no es su padre
			// entonces esta componente es un ciclo
			if (v != p) isCycle = true;
		}
	}
	state[u] = 2;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// Como cada alumno tiene a lo mas 2 enemigos
	// puedo obtener cadenas o ciclos
	// Cadenas pares: ignoro
	// Cadenas impares: acumulo 1 para que forme equipo con otro de una cadena impar
	// Ciclos pares: ignoro
	// Ciclos impares: elimino 1
	int answer = 0;
	int acc = 0;
	for (int i = 0; i < n; i++) {
		if (state[i] == 0) {
			compSize = 0;
			isCycle = false;
			dfs(i, -1);
			if (isCycle) {
				answer += (compSize % 2);
			} else { // si es cadena
				acc += (compSize % 2);
			}
		}
	}
	answer += (acc % 2);
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
}