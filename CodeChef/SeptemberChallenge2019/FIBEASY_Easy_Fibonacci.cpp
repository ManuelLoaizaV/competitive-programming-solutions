#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 100;
int fib[N + 1];

// Desde el termino 60 se repiten los ultimos digitos de fibonacci
void precalculate() {
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= N; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= 10) fib[i] -= 10;
	}
}

void solve() {
	ull n;
	cin >> n;
	ull max_pow = 1ULL;
	while (max_pow + max_pow <= n) max_pow += max_pow;
	ll aux = (ll) max_pow;
	ll pos = ((aux % 60LL) - 1LL + 60LL) % 60LL;
	cout << fib[pos] << endl;
}

int main() {
	fastio;
	precalculate();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
