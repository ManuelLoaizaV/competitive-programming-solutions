//
// Created by ManuelLoaiza on 03/29/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
const int MAX_LG = (int) log2(MAX_N) + 1;

int ancestor[MAX_N][MAX_LG];
int L[MAX_N], T[MAX_N], times[MAX_N];
vector <int> adj[MAX_N];

void DFS(int u, int level) {
    L[u] = level;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (L[v] == -1) {
            T[v] = u;
            DFS(v, level + 1);
        }
    }
}

void precalculate(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; (1 << j) < n; j++) {
            ancestor[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) ancestor[i][0] = T[i];
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (ancestor[i][j - 1] != -1) {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA(int u, int v) {
    if (L[u] < L[v]) swap(u, v);

    int lg = 31 - __builtin_clz(L[u]);

    for (int i = lg; i >= 0; i--) {
        if (L[u] - (1 << i) >= L[v]) {
            u = ancestor[u][i];
        }
    }

    if (u == v) return u;

    for (int i = lg; i >= 0; i--) {
        if (ancestor[u][i] != -1 && ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return T[u];
}

void clean(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] < '0' or s[i] > '9') s[i] = ' ';
	}
}

int main() {
	int numberOfVertices, root, vertex, numberOfSuccessors, child, numberOfPairs, u, v;
	string input;
	while (cin >> numberOfVertices) {
		getline(cin, input);
		for (int i = 0; i < numberOfVertices; i++) {
			adj[i].clear();
			times[i] = 0;
		}
		
		for (int i = 0; i < numberOfVertices; i++) {
			getline(cin, input);
			clean(input);		
			stringstream ss(input);
			ss >> vertex >> numberOfSuccessors;
			vertex--;
			if (i == 0) root = vertex;
			for (int j = 0; j < numberOfSuccessors; j++) {
				ss >> child;
				child--;
				adj[vertex].push_back(child);
				adj[child].push_back(vertex);
			}			
		}
		
		memset(L, -1, sizeof(L));
		T[0] = -1;
		DFS(root, 0);
		precalculate(numberOfVertices);
		
		cin >> numberOfPairs;
		getline(cin, input);
		int count = 0;
		while (true) {
			if (count == numberOfPairs) break;
			getline(cin, input);
			clean(input);		
			stringstream ss(input);
			while (ss >> u >> v) {
				u--;
				v--;
				count++;
				times[LCA(u, v)]++;
			}
		}
		
		for (int i = 1; i <= numberOfVertices; i++) {
			if (times[i - 1] > 0) {
				printf("%d:%d\n", i, times[i - 1]);
			}
		}
	}
	return 0;
}
