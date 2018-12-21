//
// Created by ManuelLoaiza on 10/12/18
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 2e+5;

int T[MAX_N + 1];
int L[MAX_N + 1];
int R[MAX_N + 1];
int LC[MAX_N + 1];
int RC[MAX_N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	int auxL, auxR;
	auxL = auxR = 0;
	for (int t = 1; t <= q; t++) {
		char c;
		int id;
		cin >> c >> id;
		if (c == '?') {
			int r = RC[id] + auxR - R[T[id]];
			int l = LC[id] + auxL - L[T[id]];
			int answer = min(l, r);
			cout << answer << endl;
		} else {
			T[id] = t;
			if (c == 'L') {
				LC[id] = 0;
				RC[id] = auxR + auxL;
				auxL++;
			} else { // c == 'R'
				LC[id] = auxR + auxL;
				RC[id] = 0;
				auxR++;
			}
		}
		L[t] = auxL;
		R[t] = auxR;
	}
	return 0;
}

