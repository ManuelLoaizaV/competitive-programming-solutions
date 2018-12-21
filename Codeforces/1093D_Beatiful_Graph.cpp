#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 3e+5;
const ll INF = 	9223372036854775807;
const ll mod = 998244353;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int state[MAX_N];
bool possible;
ll ward1, ward2;

void clean(int n) {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		state[i] = 0;
		visited[i] = 0;
	}
}

void dfs(int u, int s) {
	visited[u] = true;
	if (s == 0) {
		state[u] = 1;
		ward1 = 2;//comienza impar
		ward2 = 1;//comienza par
	} else {
		state[u] = s;
		if (s == 1) {
			ward1 = (ward1 * 2) % mod;
		} else { // s == 2
			ward2 = (ward2 * 2) % mod;
		}
	}
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		if (not possible) return;
		int v = adj[u][i];
		if (not visited[v]) {
			if (state[u] == 1) dfs(v, 2);
			else dfs(v, 1);
		} else {
			if (state[v] == state[u]) {
				possible = false;
				return;
			}
		}
	}
}

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	clean(n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll answer = 0;
	bool firstTime = true;
	possible = true;
	for (int i = 0; i < n; i++) {
		if (not visited[i]) {
			ward1 = ward2 = 0;
			dfs(i, 0);
			ll temp = (ward1 + ward2) % mod;
			if (firstTime) {
				firstTime = false;
				answer = temp;
			} else {
				answer = (answer * temp) % mod;
			}
		}
	}
	if (not possible) answer = 0;
	cout << answer % mod << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}