#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int k = min(n, m) + 1;
	cout << k << endl;
	int x = 0;
	int y = m;
	for (int i = 0; i < k; i++) {
		cout << x + i << " " << y - i << endl;
	}
	return 0;
}