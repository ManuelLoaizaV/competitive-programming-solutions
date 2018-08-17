//
// Created by ManuelLoaiza on 05/23/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N =1e+4;
vector <int> adj[MAX_N];
/*
0: unvisited
1: guard
2: no guard
*/
int guard[MAX_N];
int numberOfGuards, type1, type2;
bool noAnswer;

void initialize() {
	numberOfGuards = 0;
	noAnswer = false;
	for (int i = 0; i < MAX_N; i++) {
		adj[i].clear();
		guard[i] = 0;
	}
}

void BFS(int s) {
	deque <int> junctions;	
	guard[s] = 1;
	junctions.push_back(s);
	
	while (not junctions.empty()) {
		int u = junctions.front();
		int l = adj[u].size();
		
		if (guard[u] == 1) type1++;
		else type2++;
		
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			if (guard[v] == 0) {
				switch (guard[u]) {
					case 1 :
						guard[v] = 2;
						break;
					case 2 :
						guard[v] = 1;
						break;
				}
				junctions.push_back(v);
			} else {
				if (guard[u] == guard[v]) {
					noAnswer = true;
				}		
			}
		}
		
		junctions.pop_front();
	}
}

void solve() {
	initialize();
	int v, e;
	cin >> v >> e;
	int f, t;
	for (int i = 0; i < e; i++) {
		cin >> f >> t;
		adj[f].push_back(t);
		adj[t].push_back(f);
	}
	
	for (int i = 0; i < v; i++) {
		if (guard[i] == 0) {
			type1 = type2 = 0;
			BFS(i);	
			if (type2 == 0) numberOfGuards += type1;
			else numberOfGuards += min(type1, type2);
		}
	}
	if (noAnswer) cout << "-1" << endl;
	else cout << numberOfGuards << endl;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}
