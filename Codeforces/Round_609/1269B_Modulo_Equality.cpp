// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	ll a[n], b[n];
	For(i,0,n) cin >> a[i];
	For(i,0,n) cin >> b[i];
	sort(b, b + n);
	For(j,0,n) {
		ll c[n];
		For(i,0,n) c[i] = a[i];
		ll add = (b[j] - a[0] + m) % m;
		For(i,0,n) c[i] = (a[i] + add) % m;
		sort(c, c + n);
		bool ok = true;
		For(i,0,n) {
			if (c[i] == b[i]) continue;
			ok = false;
			break;
		}
		if (ok) {
			cout << add << endl;
			break;
		}
	}
	return 0;
}
