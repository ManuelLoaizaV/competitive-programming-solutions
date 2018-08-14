//
// Created by ManuelLoaiza on 09/19/17
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int N = 1e+5;
vector <int> adj[N];
int estado[N];
int treeEdges, backEdges, cantComp, edgesAdicionales;
 
 
void DFS(int u) {
	estado[u] = 1;
	int sz = adj[u].size();	
	for (int i = 0; i < sz; i++) {
		int v = adj[u][i];
		if (estado[v] == 0) treeEdges++;
		if (estado[v] == 1) backEdges++;
		if (estado[v] == 2) edgesAdicionales++;
		if (estado[v] == 0) DFS(v);
	}
	estado[u] = 2;
}
 
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);	
	}
	
	for (int i = 0; i < n; i ++) {
		if (estado[i] == 0) {
			cantComp++;
			DFS(i);
		}
	}
	
	if (cantComp == 1 and backEdges == 0 and edgesAdicionales == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
