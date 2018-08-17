//
// Created by ManuelLoaiza on 05/22/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
string worldMap[MAX_N];
vector <int> adj[MAX_N * MAX_N];
bool visited[MAX_N * MAX_N];
int answer, actualSize;
char land;

void initialize() {
	for (int i = 0; i < MAX_N * MAX_N; i++) adj[i].clear();
	memset(visited, false, sizeof(visited));
	answer = 0;
}

void read(int m) {
	for (int i = 0; i < m; i++) cin >> worldMap[i];		
}

int transformation(int x, int y, int n) {
	return n * x + y;
}

void determineEdges(int m, int n) {
	int t1, t2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			t1 = transformation(i, j, n);
			if (worldMap[i][j] == land) {
				int a[4], b[4];
				a[0] = i - 1;
				b[0] = j;
				a[1] = i + 1;
				b[1] = j;
				a[2] = i;
				b[2] = (j + 1 + n) % n;
				a[3] = i;
				b[3] = (j - 1 + n) % n;
				for (int z = 0; z < 4; z++) {
					if (a[z] >= 0 and b[z] >= 0 and 
						a[z] < m and b[z] < n and 
						worldMap[a[z]][b[z]] == land) {
						t2 = transformation(a[z], b[z], n);
						adj[t1].push_back(t2);
					}
				}
			}	
		}
	}
}

void DFS(int u) {
	actualSize++;
	visited[u] = true;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			DFS(v);
		}
	}
}

int main() {
	int m, n, x, y;
	while (cin >> m >> n) {
		initialize();
		read(m);
		cin >> x >> y;
		land = worldMap[x][y];
		determineEdges(m, n);
		DFS(transformation(x, y, n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int t = transformation(i, j, n);
				if (not visited[t] and worldMap[i][j] == land) {
					actualSize = 0;
					DFS(t);
					answer = max(answer, actualSize);	
				}
			}
		}
		cout << answer<< endl;
	}
	return 0;
}
