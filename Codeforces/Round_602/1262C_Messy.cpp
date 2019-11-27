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

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vii ans;
	For(i,0,n) {
		if (i < 2 * (k - 1)) {
			if (i % 2 == 0) {
				if (s[i] == '(') continue;
				For(j,i,n) {
					if (s[j] == '(') {
						ans.pb(mp(i + 1, j + 1));
						int l = j - i + 1;
						For(p,0,l/2) swap(s[i + p], s[j - p]);
						break;
					}
				}
			} else {
				if (s[i] == ')') continue;
				For(j,i,n) {
					if (s[j] == ')') {
						ans.pb(mp(i + 1, j + 1));
						int l = j - i + 1;
						For(p,0,l/2) swap(s[i + p], s[j - p]);
						break;
					}
				}
			}
		} else {
			int mitad = (n - 2 * (k - 1)) / 2;
			For(l,0,mitad) {
				if (s[i + l] == '(') continue;
				For(j,i+l,n) {
					if (s[j] == '(') {
						//debug(i);
						//debug(j);
						//debug(l);
						ans.pb(mp(i + l + 1, j + 1));
						int len = j - (i + l) + 1;
						For(p,0,len/2) swap(s[i + l + p], s[j - p]);
						break;
					}
				}
			}
			break;
		}
	}
	int sz = ans.size();
	cout << sz << endl;
	For(i,0,sz) cout << ans[i].ff << " " << ans[i].ss << endl;
	//debug(s);
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
