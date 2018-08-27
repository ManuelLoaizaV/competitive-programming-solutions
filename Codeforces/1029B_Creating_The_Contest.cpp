//
// Created by ManuelLoaiza on 08/26/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 2e+5;
int a[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int answer, l, r;
	answer = l = r = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 or a[r + 1] > 2 * a[r]) {
			answer = max(answer, r - l + 1);
			l = r + 1;
		}
		r++;
	}
	cout << answer << endl;
}
