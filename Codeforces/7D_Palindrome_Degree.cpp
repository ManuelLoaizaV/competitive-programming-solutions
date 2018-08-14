//
// Created by ManuelLoaiza on 05/30/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N =  5e+6;
const long long base = 29;
const long long prime = 1000000007;

long long power[MAX_N];
long long prefixHash[MAX_N];
long long sufixHash[MAX_N];
long long degree[MAX_N];

void precalculate() {
	power[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		power[i] = (power[i - 1] * base) % prime;
	}
}

bool isPalindrome(int i, int n) {
	int l = n - i - 1;
	int r = n - 1;
	if (l == 0) return prefixHash[i] == sufixHash[r];
	return prefixHash[i] == (((sufixHash[r] - sufixHash[l - 1] * power[r - l + 1]) % prime + prime) % prime);
}

int main() {
	std::ios::sync_with_stdio(false);
	string s, r;
	cin >> s;
	r = s;
	reverse(r.begin(), r.end());
	
	precalculate();
	int l = s.size();
	
	// prefix hashing
	prefixHash[0] = s[0] - '0' + 1;
	for (int i = 1; i < l; i++) {
		prefixHash[i] = ((prefixHash[i - 1] * base) % prime + (s[i] - '0' + 1)) % prime;
	}

	// sufix hashing
	sufixHash[0] = r[0] - '0' + 1;
	for (int i = 1; i < l; i++) {
		sufixHash[i] = ((sufixHash[i - 1] * base) % prime + (r[i] - '0' + 1)) % prime;
	}
	
	long long answer = 0;
	for (int i = 0; i < l; i++) {
		if (i == 0) degree[i] = 1;
		else {
			if (isPalindrome(i, l)) {
				int l = i + 1;
				if (l % 2 == 0) degree[i] = 1 + degree[l / 2 - 1];
				else degree[i] = 1 + degree[i / 2 - 1];
			}	
		}
		answer += degree[i];
	}
	printf("%lld", answer);
	return 0;
}
