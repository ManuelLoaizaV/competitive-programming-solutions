#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
const int MAX_N = 3e+5;
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool possible = true;
int anc[MAX_N];
int hDfs[MAX_N];// la altura conseguida en el dfs
int hMin[MAX_N];// la altura minima a la cual un nodo puede regresar desde su altura dfs

struct Edge {
	int u, v;
	Edge(){}
	Edge(int _u, int _v) {
		u = _u;
		v = _v;
	} 
};
vector<Edge> answer;

void dfs(int u, int h) {
	visited[u] = true;
	hDfs[u] = hMin[u] = h;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		if (not possible) return;
		int v = adj[u][i];
		// para cada vecino distinto de su padre
		if (v != anc[u]) {
			// si recien lo descubro, me importa  saber hasta donde este vecino y sus futuros
			// vecinos me pueden hacer regresar
			// el objetivo es que desde una altura mas profunda yo pueda regresar, en el mejor de
			if (not visited[v]) {
				anc[v] = u;
				dfs(v, h + 1);
				// guardo hasta donde me hizo regresar como minimo el vecino
				hMin[u] = min(hMin[u], hMin[v]);
				// si este vecino a lo mas me hace regresar a una posicion que es mas profunda que la del nodo actual
				// significa que no puedo volver a un nodo superior y seria imposible
				if (hDfs[u] < hMin[v]) {
					possible = false;
					return;
				}
				// si me puede hacer regresar a un nodo anterior a u o a el mismo u, entonces guardo la arista hacia abajo
				answer.pb(Edge(u + 1, v + 1));
			} else {
				// si ya lo habia visitado, guardo la altura minima a la cual puedo regresar
				hMin[u] = min(hMin[u], hMin[v]);
				// si la altura dfs del vecino es menor, guardo la arista hacia arriba que cierra el ciclo
				if (hDfs[v] < hDfs[u]) answer.pb(Edge(u + 1, v + 1));
			}
		}
	}
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
	anc[0] = -1;
	dfs(0, 0);
	if (possible) {
		int l = answer.size();
		for (int i = 0; i < l; i++)
			cout << answer[i].u << " " << answer[i].v << endl; 
	} else {
		cout << "0" << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}