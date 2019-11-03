//
// Created by ManuelLoaiza on 03/26/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
const int MAX_LG = (int) log2(MAX_N) + 1;
int ancestor[MAX_N][MAX_LG];
int L[MAX_N], T[MAX_N];
long long cost[MAX_N];

struct Tunnel {
    int A;
    long long L;
    Tunnel() {}
    Tunnel (int _A, long long _L) {
        A = _A;
        L = _L;
    }
};

vector <Tunnel> adj[MAX_N];

void DFS(int u, int level, long long actualCost) {
    L[u] = level;
    cost[u] = actualCost;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].A;
        if (L[v] == -1) {
            T[v] = u;
            DFS(v, level + 1, actualCost + adj[u][i].L);
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

int main() {
    int N, Q, A, S, _T;
    long long _L, answer;
    
    while (true) {
        scanf("%d", &N);
        if (N == 0) break;

        for (int i = 0; i < N; i++) adj[i].clear();
        
        for (int i = 1; i < N; i++) {
            scanf("%d %lld", &A, &_L);
			adj[i].push_back(Tunnel(A, _L));
            adj[A].push_back(Tunnel(i, _L));
        }

        memset(L, -1, sizeof(L));
        T[0] = -1;
        DFS(0, 0, 0);
        precalculate(N);

        scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
            scanf("%d %d", &S, &_T);
			answer = cost[S] + cost[_T] - 2 * cost[LCA(S, _T)];
            printf("%lld", answer);
			if (i < Q - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
