#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300;
const ll INF = 1e9;
ll w[N][N];
ll d[N][N];

void floyd_warshall(int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			w[i][j] = d[i][j] = INF;
	for (int i = 0; i < N; i++) w[i][i] = d[i][i] = 0LL;
	int n = 4;
	w[0][1] = 3;
	w[1][0] = 8;
	w[0][3] = 7;
	w[3][0] = 2;
	w[2][3] = 1;
	w[2][0] = 5;
	w[1][2] = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = w[i][j];
	floyd_warshall(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << "Distancia minima desde " << i << " hasta " << j << " : " << d[i][j] << endl;
	return 0;
}
