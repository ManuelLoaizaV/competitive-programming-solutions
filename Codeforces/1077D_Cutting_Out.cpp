//
// Created by ManuelLoaiza on 11/16/18
//
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e+5;
int s[MAX_N];
int t[MAX_N];
int ward[MAX_N + 1];
int freq[MAX_N + 1];

void copy(int n) {
	for (int i = 0; i <= MAX_N; i++) ward[i] = freq[i];
}

bool check(int times, int n, int k) {
	int l = 0;
	int i = 0;
	while (i < n) {
		if (l == k) return true;
		if (ward[s[i]] >= times) {
			ward[s[i]] -= times;
			t[l] = s[i];
			l++;
		} else {
			i++;
		}
	}
	if (l == k) return true;
	return false;
}

void binarySearch(int l, int r, int k) {
	int n = r;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		copy(n);
		if (check(mid, n, k)) l = mid;
		else r = mid;
	}
	copy(n);
	if (check(r, n, k)) return;
	copy(n);
	check(l, n, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		freq[s[i]]++;
	}
	binarySearch(1, n, k);
	for (int i = 0; i < k; i++) cout << t[i] << " ";	
	return 0;
}
