//
// Created by ManuelLoaiza on 05/26/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
vector <int> adj[MAX_N];
bool visited[MAX_N];
bool dependency[MAX_N][MAX_N];
queue <int> orderedTasks;

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		visited[i] = false;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dependency[i][j] = false;
		}
	}
	
	while (not orderedTasks.empty()) {
		orderedTasks.pop();
	}
}

void createGraph(int n) {
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			x--;
			adj[i].push_back(x);
		}
	}
}

void DFS(int u) {
	visited[u] = true;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			DFS(v);
		}
	}
	orderedTasks.push(u);
}

void topologicalSort(int n) {
	for (int i = 0; i < n; i++) {
		if (not visited[i]) {
			DFS(i);
		}
	}
}

void fillDependencies(int n) {
	while (not orderedTasks.empty()) {
		int u = orderedTasks.front();
		orderedTasks.pop();
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			dependency[u][v] = true;
			for (int w = 0; w < n; w++) {
				if (dependency[v][w]) {
					dependency[u][w] = true;
				}
			}
		}
	}
}

int findAnswer(int n) {
	int answer = -1;
	int maxDependencies = -1;
	for (int i = 0; i < n; i++) {
		int dependencies = 0;
		for (int j = 0; j < n; j++) {
			if (dependency[i][j]) dependencies++;
		}
		if (dependencies > maxDependencies) {
			answer = i;
			maxDependencies = dependencies;
		}
	}
	return answer;
}

void solve(int n) {
	initialize(n);
	createGraph(n);
	topologicalSort(n);
	fillDependencies(n);
	int answer = findAnswer(n) + 1;
	cout << answer << endl;
}

int main() {
	int n;
	while (cin >> n) {
		if  (n == 0) break;
		solve(n);
	}
	return 0;
}
