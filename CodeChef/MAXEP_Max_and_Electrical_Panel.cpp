#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int response;

void check(int &l, int &r, int n, int d) {
	while (r <= n) {
		cout << "1 " << r << endl;
		fflush(stdout);
		cin >> response;
		if (response == 1) {
			cout << "2" << endl;
			fflush(stdout);
			break;
		}
		l = r;
		r += d;
	}
	r = min(r, n);
}

int main() {
	fastio;
	int n, c, l, r, R;
	cin >> n >> c;
	l = 1;
	R = 400;
	check(l, R, n, 400);
	if (l == 1) r = 20;
	else r = l + 20;
	check(l, r, R, 20);
	for (int i = l; i <= r; i++) {
		cout << "1 " << i << endl;
		fflush(stdout);
		cin >> response;
		if (response == 0) continue;
		cout << "3 " << i << endl;
		fflush(stdout);
		return 0;
	}
	cout << r << endl;
	fflush(stdout);
	return 0;
}
