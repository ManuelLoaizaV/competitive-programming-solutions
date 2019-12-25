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

string q;

int query() {
	cout << q << endl;
	int edist;
	cin >> edist;
	return edist;
}

int main() {
	fastio;
	q = string(300, 'a');
	int a = 300 - query();
	q = string(300, 'b');
	int b = 300 - query();
	int sz = a + b;
	string ans = "";
	For(i,0,sz) ans += 'a';
	if (b == 0) {
		cout << ans << endl;
		return 0;
	}
	if (a == 0) {
		ans = string(sz, 'b');
		cout << ans << endl;
		return 0;
	}
	q = ans;
	For(i,0,sz-1) {
		q[i] = 'b';
		if (query() == b - 1) ans[i] = 'b', b--;
		else q[i] = 'a';
	}
	if (b == 1) ans[sz - 1] = 'b';
	cout << ans << endl;
	return 0;
}
