//
// Created by ManuelLoaiza on 10/13/18
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int N = 200;

vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
	97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
bool isSemiPrime[N + 1];
bool answer[N + 1];

void precalculate() {
	int l = primes.size();
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			int temp = primes[i] * primes[j];
			if (temp <= N) isSemiPrime[temp] = true;
			else break;
		}
	}
	for (int i = 4; i <= N; i++) {
		for (int j = i; j <= N - i; j++) {
			if (isSemiPrime[i] and isSemiPrime[j]) {
				answer[i + j] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	precalculate();
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (answer[n]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}