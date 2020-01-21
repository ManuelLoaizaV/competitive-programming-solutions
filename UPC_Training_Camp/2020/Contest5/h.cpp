#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

long long fast_pow(long long a, long long b, long long m) {
	long long ans = 1LL;
	while (b > 0) {
		if (b & 1) ans = (ans * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return ans;
}

// Hallar el menor x tal que a ^ x = b (mod m) o -1 si no existe
long long discrete_log(long long a, long long b, long long m) {
	a %= m;
	b %= m;
	if (b == 1) return 0;
	int cnt = 0;
	int temp = 1;
	for (int g = __gcd (a, m); g != 1; g = __gcd(a, m)) {
		if (b % g) return -1;
		m /= g;
		b /= g;
		temp = temp * a / g % m;
		cnt++;
		if (b == temp) return cnt;
	}
	map<long long, int> val;
	int s = ceil(sqrt(m));
	long long base = b;
	for (int i = 0; i < s; i++) {
		val[base] = i;
		base = base * a % m;
	}
	base = fast_pow(a, s, m);
	long long key = temp;
	for (int i = 1; i < s + 2; i++) {
		key = base * key % m;
		if (val.count(key)) return i * s - val[key]+ cnt;
	}
	return -1;
}

long long modular_inverse(long long a, long long m) { return fast_pow(a, m - 2, m); }

void solve() {
	long long n, x, A, B, a, b, p, k;
	cin >> n >> x >> A >> B >> a >> b >> p;
	int cnt = 0;
	int total = B - A + 1;
	for (long long r = A; r <= B; r++) {
		if (a == 1) {
			k = (((x - r + p) % p) * modular_inverse(b, p)) % p;
		} else {
			long long num = (x * (a - 1) + b) % p;
			long long den = (r * (a - 1) + b) % p;
			if (den == 0) k = (((p - b) * modular_inverse(a - 1, p)) % p == x ? 0 : n);
			else k = discrete_log(a, (num * modular_inverse(den, p)) % p, p);
		}	
		if (k == -1) continue;
		if (k < n) cnt++;
	}
	int g = __gcd(cnt, total);
	cnt /= g;
	total /= g;
	cout << cnt << "/" << total << endl;
}

int main() {
	freopen("hawawshi.in", "r", stdin);
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
