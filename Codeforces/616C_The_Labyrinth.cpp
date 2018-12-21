#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1000;
const int ALPH = 26;
const ll INF = 9223372036854775807;
string alph = "abcdefghijklmnopqrstuvwxyz";
string g[MAX_N];
vector<int> adj[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];
int comp[MAX_N * MAX_N + 5];
int sizeComp[MAX_N * MAX_N + 5];
bool isEmpty[MAX_N * MAX_N];
int components = 0;
int quantity = 0;

int Hash(int a, int b, int m) {
	return a * m + b;
}

bool possible(int x, int y, int n, int m) {
	if (0 <= x and x < n and 0 <= y and y <= m) return true;
	return false;
}

void createGraph(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int u = Hash(i, j, col);
			if (g[i][j] == '.') isEmpty[u] = true;
			int x[2], y[2];
			x[0] = i;
			y[0] = j + 1;
			x[1] = i + 1;
			y[1] = j;
			for (int k = 0; k < 2; k++) {
				if (possible(x[k], y[k], row, col)) {
					int v = Hash(x[k], y[k], col);
					if (g[i][j] == '.' and g[x[k]][y[k]] == '.') {
						adj[u].pb(v);
						adj[v].pb(u);
					}
				}
			}
		}
	}
}

void dfs(int u) {
	visited[u] = true;
	comp[u] = components;
	quantity++;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) dfs(v);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> g[i];
	createGraph(n, m);
	int l = n * m;
	for (int i = 0; i < l; i++) {
		if (isEmpty[i] and not visited[i]) {
			quantity = 0;
			components++;
			dfs(i);
			sizeComp[components] = quantity;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int u = Hash(i, j, m);
			if (isEmpty[u]) cout << ".";
			else {
				int x[4], y[4];
				x[0] = i;
				y[0] = j + 1;
				x[1] = i;
				y[1] = j - 1;
				x[2] = i + 1;
				y[2] = j;
				x[3] = i - 1;
				y[3] = j;
				set<int> ward;
				std::set<int>::iterator it;
				for (int k = 0; k < 4; k++) {
					if (possible(x[k], y[k], n, m) and g[x[k]][y[k]] == '.') {
						int v = Hash(x[k], y[k], m);
						ward.insert(comp[v]);
					}
				}
				int sum = 1;
				for (it = ward.begin(); it != ward.end(); it++) {
					sum += sizeComp[*it];
				}
				cout << sum % 10 ;
			}
		}
		cout << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}