//
// Created by ManuelLoaiza on 06/01/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
int a[MAX_N];
bool f[MAX_N + 1];
int ind[MAX_N + 1];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]] = true;
		ind[a[i]] = i + 1;
	}
	int cont = 0;
	for (int i = 1; i <= MAX_N; i++) {
		if (f[i]) cont++;
	}
	if (cont >= k) {
		cout << "YES" << endl;
		for (int i = 1; i <= MAX_N; i++) {
			if (k == 0) break;
			if (f[i]) {
				cout << ind[i] << " ";
				k--;
			}
		}	
	}
	else cout << "NO" << endl;
	return 0;
}

