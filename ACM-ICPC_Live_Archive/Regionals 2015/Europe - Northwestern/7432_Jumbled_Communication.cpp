//
// Created by ManuelLoaiza on 08/31/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;
const int MAX = 1 << 9;

int b[MAX_N];

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < MAX; j++) {
				if (j xor ((j << 1) % MAX) == b[i]) {
					cout << j << " ";
					break;	
				}
			}
		}
		cout << endl;
	}
	return 0;
}
