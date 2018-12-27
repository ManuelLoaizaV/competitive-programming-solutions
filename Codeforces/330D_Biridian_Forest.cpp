#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;

const int MAX_N = 1000;
string g[MAX_N];
vector<int> adj[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];
int isBreeder[MAX_N * MAX_N];
int h[MAX_N * MAX_N];

int f(int x, int y, int m) {
	return m * x + y;
}

bool possible(int x, int y, int n, int m) {
	if (0 <= x and x < n and 0 <= y and y < m) return true;
	return false;
}

void createGraph(int row, int col, int &exit, int &start) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (g[i][j] != 'T') {
				int u = f(i, j, col);
				if (g[i][j] == 'E') 
					exit = u;
				else {
					if (g[i][j] == 'S') 
						start = u;
					else {
						isBreeder[u] = g[i][j] - '0';
					}
				}
				for (int d = -1; d <= 1; d += 2) {
					int x = i + d;
					int y = j + d;
					if (possible(x, j, row, col)) {
						int v = f(x, j, col);
						if (g[x][j] != 'T') {
							adj[u].pb(v);
							adj[v].pb(u);
						}
					}
					if (possible(i, y, row, col)) {
						int v = f(i, y, col);
						if (g[i][y] != 'T') {
							adj[u].pb(v);
							adj[v].pb(u);
						}
					}
				}
			}
		}
	}
}

void bfs(int s) {
	h[s] = 0;
	visited[s] = true;
	deque<int> p;
	p.pb(s);
	while (not p.empty()) {
		int u = p.front();
		p.pop_front();
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			if (not visited[v]) {
				visited[v] = true;
				h[v] = h[u] + 1;
				p.pb(v);
			}
		}
	}
}

void solve() {
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; i++) 
		cin >> g[i];
	int exit, start;
	createGraph(row, col, exit, start);
	int n = row * col;
	for (int i = 0; i < n; i++) h[i] = -1;
	bfs(exit);
	int answer = 0;
	//debug(exit);
	//debug(start);
	for (int i = 0; i < n; i++) {
		if (i != start and isBreeder[i] > 0 and h[i] <= h[start] and h[i] != -1) {
			//debug(i);
			//debug(h[i]);
			answer += isBreeder[i];
			//debug(answer);
		}
	}
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
}