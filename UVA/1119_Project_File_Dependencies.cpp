//
// Created by ManuelLoaiza on 05/28/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
vector <int> adj[MAX_N];
int inDegree[MAX_N];

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		inDegree[i] = 0;
	}
}

void createGraph(int m) {
	while (m--) {
		int t0, k, ti;
		cin >> t0 >> k;
		t0--;
		inDegree[t0] += k;
		for (int i = 0; i < k; i++) {
			cin >> ti;
			ti--;
			adj[ti].push_back(t0);
		}
	}
}

void topologicalSort(int n) {
	priority_queue <int, vector<int>, greater<int> > tasks;
	vector <int> answer;
	for (int i = 0; i < n; i++) if (inDegree[i] == 0) tasks.push(i);
	while (not tasks.empty()) {
		int u = tasks.top();
		tasks.pop();
		answer.push_back(u);
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0) tasks.push(v);
		}
	}
	
	for (int i = 0; i < answer.size(); i++) {
		if (i == 0) cout << answer[i] + 1;
		else cout << " " << answer[i] + 1;
	}
	cout << endl;
}

void solve() {
	int n, m;
	cin >> n >> m;
	initialize(n);
	createGraph(m);
	topologicalSort(n);
}

int main() {
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		solve();
		if (i < testCases - 1) cout << endl;
	}
	return 0;
}
