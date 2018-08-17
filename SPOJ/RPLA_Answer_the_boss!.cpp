//
// Created by ManuelLoaiza on 06/04/18
//
#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+3;

vector <int> adj[MAX_N];
int inDegree[MAX_N];
int dist[MAX_N];

struct Employee {
	int rank;
	int id;
	Employee(){}
	Employee(int _rank, int _id) {
		rank = _rank;
		id = _id;
	}
	bool operator < (Employee aux) const {
		if (rank == aux.rank) return id < aux.id;
		return rank < aux.rank;
	}
};

void initialize(int n) {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		inDegree[i] = 0;
		dist[i] = 0;
	}
}

void createGraph(int r) {
	for (int i = 0; i < r; i++) {
		int x, y;
		cin >> x >> y;
		inDegree[x]++;
		adj[y].push_back(x);
	}
}

void topologicalSort(int n) {
	priority_queue <int, vector<int>, greater<int> > Q;
	vector <Employee> answer;
	
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			dist[i] = 1;
			Q.push(i);
		}	
	}
	
	while (not Q.empty()) {
		int u = Q.top();
		Q.pop();
		answer.push_back(Employee(dist[u], u));	
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}		
	}
	
	sort(answer.begin(), answer.end());
	for (int i = 0; i < n; i++) cout << answer[i].rank << " " << answer[i].id << endl;
}

void solve() {
	int n, r;
	cin >> n >> r;
	initialize(n);
	createGraph(r);
	topologicalSort(n);
}

int main() {	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Scenario #" << i << ":" << endl;
		solve();
		cout << endl;
	}
	return 0;
}
