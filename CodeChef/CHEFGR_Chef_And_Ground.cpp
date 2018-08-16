//
// Created by ManuelLoaiza on 05/27/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
int a[MAX_N];

void solve() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i == 0) x = a[i];
		else x = max(x, a[i]); 		
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum += (x - a[i]);
	
	if (m < sum) {
		printf("No\n");
		return;
	}
	if (m == sum) {
		printf("Yes\n");
		return;
	}
	if ((m - sum) % n == 0) {
		printf("Yes\n");
		return;
	}
	printf("No\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
