//
// Created by ManuelLoaiza on 03/25/18
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, aux, answer;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &aux);
	answer = (n - 1) * n / 2;
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
