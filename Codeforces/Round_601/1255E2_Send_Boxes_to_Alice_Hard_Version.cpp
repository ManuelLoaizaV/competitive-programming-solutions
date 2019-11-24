#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 1000005;
const ll INF = 1e18;
const ld EPS = 10e-9;

ll sum[N];
vi divisors;

void factorize(ll n) {
	For(i,2,N + 1)
		if (n % i == 0) {
			divisors.pb((ll)i);
			while (n % i == 0) n /= i;
		}
	if (n > 1) divisors.pb(n);
}

int main() {
	fastio;
	int n;
	cin >> n;
	ll a[n];
	For(i,0,n) cin >> a[i];
	sum[0] = a[0];
	For(i,1,n) sum[i] = sum[i - 1] + a[i];
	For(i,n,N) sum[i] = sum[i - 1];
	if (sum[n - 1] ==  1) {
		cout << "-1" << endl;
		return 0;
	}

	factorize(sum[n - 1]);
	// Para cada divisor primo de la suma total
	ll ans = INF;
	int sz = divisors.size();
	For(p,0,sz) {
		ll k = divisors[p];
		ll temp = 0LL;
		For(i,0,n-1) if (sum[i] % k != 0) temp += min(sum[i] % k, k - sum[i] % k);
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
