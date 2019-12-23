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

void read(ii &p) { cin >> p.ff >> p.ss; }

int main() {
	fastio;
	int n;
	ii s;
	cin >> n;
	read(s);
	ii p[n];
	For(i,0,n) read(p[i]);
	int cnt = -1;
	int count[4];
	For(i,0,4) count[i] = 0;
	ii ans;
	For(i,0,n) {
		if (p[i].ff > s.ff) count[0]++;
		if (p[i].ss > s.ss) count[1]++;
		if (p[i].ff < s.ff) count[2]++;
		if (p[i].ss < s.ss) count[3]++;
	}
	if (count[0] > cnt) {
		cnt = count[0];
		ans = {s.ff + 1, s.ss};
	}
	if (count[1] > cnt) {
		cnt = count[1];
		ans = {s.ff, s.ss + 1};
	}
	if (count[2] > cnt) {
		cnt = count[2];
		ans = {s.ff - 1, s.ss};
	}
	if (count[3] > cnt) {
		cnt = count[3];
		ans = {s.ff, s.ss - 1};
	}
	cout << cnt << endl;
	cout << ans.ff << " " << ans.ss << endl;
	return 0;
}
