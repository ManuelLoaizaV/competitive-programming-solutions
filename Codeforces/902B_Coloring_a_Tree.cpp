//
// Created by ManuelLoaiza on 12/19/17.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 1e+4;
vector <int> adj[N];
int color[N];
bool visitado[N];
int resultado;

void DFS(int u, int colorPadre) {

    visitado[u] = 1;
    int vecinos = adj[u].size();

    if (colorPadre != color[u]) resultado++;

    for (int i = 0; i < vecinos; i++) {
        int v = adj[u][i];
        if (not visitado[v]) {
            DFS(v, color[u]);
        }
    }

}

int main() {

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        color[i] = x;
    }

    DFS(0,0);

    cout << resultado << endl;

    return 0;

}
