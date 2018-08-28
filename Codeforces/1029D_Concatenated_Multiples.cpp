//
// Created by ManuelLoaiza on 08/28/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e+5;
const int MAX_LENGTH = 10;

ll a[MAX_N];
int digits[MAX_N];
vector <ll> mod[MAX_LENGTH + 1];

int length(ll n) {
	if (n < 10) return 1;
	return 1 + length(n / 10);
}

int main() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		digits[i] = length(a[i]);
		mod[digits[i]].push_back(a[i] % k);
	}
	for (int i = 0; i <= MAX_LENGTH; i++) sort(mod[i].begin(), mod[i].end());
	
	ll answer = 0;
	for (int i = 0; i < n; i++) {
		ll r = a[i] % k;
		for (int j = 1; j <= MAX_LENGTH; j++) {
			r = (r * (10 % k)) % k;
			ll c = (k - r) % k;
			answer += upper_bound(mod[j].begin(), mod[j].end(), c) 
					- lower_bound(mod[j].begin(), mod[j].end(), c);
			if (digits[i] == j and a[i] % k == c) answer--;
		}
	}
	cout << answer << endl;
	return 0;
}
