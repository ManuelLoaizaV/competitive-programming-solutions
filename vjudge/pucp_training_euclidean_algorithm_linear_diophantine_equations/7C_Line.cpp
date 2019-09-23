#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;

const ll L = 5e18;

// a*x1 + b*y1 = g
ll gcd(ll a, ll b, ll *x, ll *y) {
	if (b == 0LL) {
		(*x) = 1LL;
		(*y) = 0LL;
		return a;
	}
	ll x1, y1;
	ll g = gcd(b, a % b, &x1, &y1);
	(*x) = y1;
	(*y) = x1 - (a / b) * y1;
	return g;
}

int main() {
	// Ax+By+C=0
	ll A, B, C;
	cin >> A >> B >> C;
	if (A == 0LL and B == 0LL) {
		if (C == 0LL) cout << "1 1" << endl;
		else cout << "-1" << endl;
	} else {
		ll a = max(abs(A), abs(B));
		ll b = min(abs(A), abs(B));
		ll x, y;
		ll g = gcd(a, b, &x, &y);
		ll c = abs(C);
		if (c % g != 0LL) cout << "-1"<< endl;
		else {
			ll fact = (-1LL * C) / g;
			x *= fact;
			y *= fact;
			if (a == abs(A)) {
				// En este caso ya esta resuelto y no se tiene que modificar
				if (A < 0) x *= -1LL;
				if (B < 0) y *= -1LL;
			} else {
				if (A < 0) y *= -1LL;
				if (B < 0) x *= -1LL;
				swap(x, y);
			}
			if (abs(x) <= L and abs(y) <= L) cout << x << " " << y << endl;
			else cout << "-1" << endl;
		}
	}
	return 0;
}
