#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, x, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x >= r) cout << "Good boi" << endl;
		else cout << "Bad boi" << endl;
	}
	return 0;
}
