//
// Created by ManuelLoaiza on 05/24/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 182;
string bitMap[MAX_N];
vector <int> adj[MAX_N * MAX_N];
int distances[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];
bool isWhite[MAX_N * MAX_N];

void initialize(int n, int m) {
	for (int i = 0; i < n * m; i++) {
		adj[i].clear();
		distances[i] = 0;
		visited[i] = false;
		isWhite[i] = false;
	}
}

void readBitMap(int n) {
	for (int i = 0; i < n; i++) cin >> bitMap[i];
} 

int transformation(int x, int y, int m) {
	return m * x + y;
}

void createGraph(int n, int m) {
	int a[4], b[4];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
				int t1 = transformation(i, j, m);
				if (bitMap[i][j] == '1') isWhite[t1] = true;
				a[0] = i - 1;
				b[0] = j;	
				a[1] = i + 1;
				b[1] = j;
				a[2] = i;
				b[2] = j - 1;
				a[3] = i;
				b[3] = j + 1;
				for (int k = 0; k < 4; k++) {
					if (a[k] >= 0 and b[k] >= 0 and a[k] < n and b[k] < m) {
						int t2 = transformation(a[k], b[k], m);
						adj[t1].push_back(t2);
					}
				}
		}
	}
}

void BFS(int n, int m) {
	deque <int> pixels;
	for (int i = 0; i < n * m; i++) {
		if (isWhite[i]) {
			visited[i] = true;			
			distances[i] = 0;
			pixels.push_back(i);
		}
	}
	
	while (not pixels.empty()) {
		int u = pixels.front();
		pixels.pop_front();
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			if (not visited[v]) {
				visited[v] = true;
				distances[v] = 1 + distances[u];
				pixels.push_back(v);
			} else {
				distances[v] = min(distances[v], 1 + distances[u]);
			}
		}
	}
}

void writeDistances(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t = transformation(i, j, m);
			cout << distances[t] << " ";
		}
		cout << endl;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	initialize(n, m);
	readBitMap(n);
	createGraph(n, m);
	BFS(n, m);
	writeDistances(n, m);
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}
