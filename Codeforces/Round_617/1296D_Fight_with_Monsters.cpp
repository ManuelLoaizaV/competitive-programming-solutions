#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
	fastio;
	long long n, a, b, k;
	cin >> n >> a >> b >> k;
	long long h[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	long long secret[n];
	for (int i = 0; i < n; i++) {
		long long r = h[i] % (a + b);
		if (r == 0) r = a + b;
		secret[i] = (r + a - 1) / a - 1;
	}
	int ans = 0;
	sort(secret, secret + n);
	for (int i = 0; i < n; i++) {
		if (secret[i] <= k) {
			ans++;
			k -= secret[i];
		}
	}
	cout << ans << endl;
	return 0;
}
