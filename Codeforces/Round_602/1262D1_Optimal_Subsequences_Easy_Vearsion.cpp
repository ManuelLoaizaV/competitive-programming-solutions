// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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
	cin >> n;
	int a[n];
	int ordenado[n];
	For(i,0,n) cin >> a[i];
	For(i,0,n) ordenado[i] = a[i];
	sort(ordenado, ordenado + n);
	cin >> m;
	while (m--) {
		int k, pos;
		cin >> k >> pos;
		map<int, int> freq;
		For(i,0,k) freq[ordenado[n - 1 - i]]++;
		std::map<int, int>::iterator it;
		vii unicos;
		for (it = freq.begin(); it != freq.end(); it++) unicos.pb(mp(it->ff, it->ss));
		sort(all(unicos));
		int sz = unicos.size();
		if (sz == 1) cout << ordenado[n - 1] << endl;
		else {
			bool used[n];
			For(i,0,n) used[i] = false;
			roF(i,sz-1,1) For(j,0,n) if (a[j] == unicos[i].ff) used[j] = true;
			int count = 0;
			For(i,0,n) {
				if (count == unicos[0].ss) break;
				if (a[i] == unicos[0].ff) {
					used[i] = true;
					count++;
				}
			}
			vi ans;
			For(i,0,n) if (used[i]) ans.pb(a[i]);
			cout << ans[pos - 1] << endl;
		}
	}
	return 0;
}
