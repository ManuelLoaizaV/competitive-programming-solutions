#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+6;
const int ALPH = 26;
const ll INF = 9223372036854775807;
string alph = "abcdefghijklmnopqrstuvwxyz";
vector<int> adj[MAX_N];
bool visited[MAX_N];
int a[MAX_N], dist[MAX_N];
bool possible = true;

void bfs(int n) {
	if (a[0] != 0) {
		possible = false;
		return;
	}
	for (int i = 0; i < n; i++) {
		dist[i] = adj[i].size();
		if (i > 0) dist[i]--;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			sum = dist[0];
			for (int j = 1; j <= sum; j++) {
				if (binary_search(adj[0].begin(), adj[0].end(), a[j])) continue;
				possible = false;
				return;
			}
		} else {
			int l = sum + 1;
			sum += dist[a[i]];
			int r = sum;
			while (l <= r) {
				if (binary_search(adj[a[i]].begin(), adj[a[i]].end(), a[l])) {
					l++;
				} else {
					possible = false;
					return;
				}
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	bfs(n);
	if (possible) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}