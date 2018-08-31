//
// Created by ManuelLoaiza on 08/29/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e+5;
const ll INF = 1e+18;

int ancestor[MAX_N];
ll minDist[MAX_N];
vector< pair<ll, int> > graph[MAX_N];
priority_queue<pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pathWeight;

void initialize(int n) { 
	for (int i = 0; i < n; i++) {
		ancestor[i] = -1;
		minDist[i] = INF;
	}
}

void createGraph(int m) {
	for (int i = 0; i < m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--;
		v--;		
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}
}

void Dijkstra(int origin) {
	pathWeight.push(make_pair(0, origin));
	minDist[origin] = 0;
	while (not pathWeight.empty()) {
		pair<ll, int> actual = pathWeight.top();
		pathWeight.pop();
		ll dist = actual.first;
		int u = actual.second;
		if (dist <= minDist[u]) {
			int l = graph[u].size();
			for (int i = 0; i < l; i++) {
				ll temp = dist + graph[u][i].first;
				int v = graph[u][i].second;
				if (temp < minDist[v]) {
					ancestor[v] = u;
					minDist[v] = temp;
					pathWeight.push(make_pair(temp, v));
				}
			}
		}			
	}
}

void solve(int v) {
	bool noPath = true;
	vector<int> answer;
	answer.push_back(v);
	while (ancestor[v] != -1) {
		int u = ancestor[v];
		answer.push_back(u);
		if (u == 0) noPath = false;
		v = u;
	}	
	
	if (noPath) {
		cout << "-1" << endl;	
	}
	else {
		for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i] + 1 << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	initialize(n);
	createGraph(m);
	Dijkstra(0);
	solve(n - 1);
	return 0;
}
