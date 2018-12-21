//
// Created by ManuelLoaiza on 06/02/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX= 50;

long long f[MAX + 1];

void precalculate(){
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		f[i] = f[i - 2] + f[i - 1];
	}
}

int main() {
	precalculate();
	long long n;
	cin >> n;
	for (int i = 0; i <= MAX; i++) {
		for (int j = 0; j <= MAX; j++) {
			for (int k = 0; k <= MAX; k++) {
				if (f[i] + f[j] + f[k] == n) {
					printf("%lld %lld %lld\n", f[i], f[j], f[k]);
					return 0;
				}
			}
		}
	}
	printf("I'm too stupid to solve this problem\n");
	return 0;
}
