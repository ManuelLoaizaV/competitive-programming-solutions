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

bool found[N + 1];

int main() {
	fastio;
	vi ans;
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	bool ok = true;
	int count = 0;
	map<int, bool> used;
	std::map<int, bool>::iterator it;
	For(i,0,n) {
		if (a[i] > 0) {
			if (found[a[i]]) {
				ok = false;
				break;
			} else {
				it = used.find(a[i]);
				if (it != used.end()) {
					ok = false;
					break;
				} else {
					found[a[i]] = true;
					count++;
				}
			}
		} else {
			if (found[-a[i]]) {
				found[-a[i]] = false;
				used[-a[i]] = true;
				count--;
			} else {
				ok = false;
				break;
			}
		}
		if (count == 0) {
			ans.pb(i + 1);
			used.clear();
		}
	}
	if (count != 0) ok = false;
	if (not ok) {
		cout << "-1" << endl;
		return 0;
	}
	int sz = ans.size();
	cout << sz << endl;
	For(i,0,sz) {
		if (i == 0) cout << ans[i];
		else cout << " " << ans[i] - ans[i - 1];
	}
	cout << endl;
	return 0;
}
