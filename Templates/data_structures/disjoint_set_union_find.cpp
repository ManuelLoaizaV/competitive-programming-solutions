#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int parent[N + 1];

// Creates a new set consisting of the new element v
void make_set(int v) {
	parent[v] = v;
}

// Returns the representative of the set that contains the element v
int find_set(int u) {
	if (parent[u] == u) return u;
	parent[u] = find_set(parent[u]);
	return parent[u];
}

// Checks if two elements are part of the same set or not
bool same_set(int u, int v) {
	return find_set(u) == find_set(v);
}

// Merges the sets in which u and v are located
void union_sets(int u, int v) {
	int p_u = find_set(u);
	int p_v = find_set(v);
	if (p_u != p_v) parent[p_v] = p_u;
}

int main() {
	// Supongamos que quiero crear estas 4 componentes
	// (1, 2, 3) (4, 5) (6, 7, 8, 9) (10)
	for (int i = 1; i <= N; i++) make_set(i);
	union_sets(1, 2);
	union_sets(2, 3);
	union_sets(4, 5);
	union_sets(6, 7);
	union_sets(6, 8);
	union_sets(9, 8);
	// Chequeare a que componente pertenece cada elemento
	for (int i = 1; i <= N; i++)
		printf("El elemento %d pertenece a la componente representada por %d.\n", i, find_set(i));
	// Chequeare todos los pares
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			if (same_set(i, j)) printf("%d y %d se encuentran en el mismo set.\n", i, j);
			else printf("%d y %d no se encuentran en el mismo set.\n", i, j);
	return 0;
}
