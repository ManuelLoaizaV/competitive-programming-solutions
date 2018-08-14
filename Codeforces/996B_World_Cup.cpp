//
// Created by ManuelLoaiza on 06/24/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;
const int INF = 1e+9;

ll a[MAX_N];
ll times[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		a[i] -= i;
		if (a[i] <= 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] <= 0) {
			times[i] = 1;
		} else {
			times[i] = ceil(1.0 * a[i] / n);
		}
	}
	
	ll minimumTimes = INF;
	ll answer = INF;
	
	for (int i = 0; i < n; i++) {
		if (times[i] < minimumTimes) {
			minimumTimes = times[i];
			answer = i + 1;
		}
	}
	
	cout << answer << endl;
	return 0;
}

