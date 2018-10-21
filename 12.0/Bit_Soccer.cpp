#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 1e+5;
ll p[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	int q;
	cin >> q;
	while (q--) {
		ll g;
		cin >> g;
		bool possible = false;
		long long ward = 0;
		for (int i = 0; i < n; i++) {
			if ((p[i] | g) == g) {
				ward = ward | p[i];
			} 
			if (ward == g) {
				possible = true;
				break;
			}
		}
		if (possible) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}