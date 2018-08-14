//
// Created by ManuelLoaiza on 05/06/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

long long a[MAX_N];

int factor2(long long x) {
	int answer = 0;
	while (x > 0 and x % 2 == 0) {
		answer++;
		x /= 2;	
	}
	return answer;
}

int factor3(long long x) {
	int answer = 0;
	while (x > 0 and x % 3 == 0) {
		answer++;
		x /= 3;
	}
	return answer;
}

bool condicion (const long long &x, const long long &y) {
	return factor3(x) >= factor3(y)	and factor2(x) <= factor2(y);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, condicion);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}

