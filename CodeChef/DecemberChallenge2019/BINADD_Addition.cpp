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

int find_l(ii block, vi pos) {
	int sz = pos.size();
	if (sz == 0) return -1;
	int l = 0;
	int r = sz - 1;
	if (pos[r] < block.ff) return -1;
	if (pos[l] >= block.ff) {
		if (pos[l] <= block.ss) return l;
		return -1;
	}
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (pos[m] >= block.ff) r = m;
		else l = m;
	}
	if (pos[l] >= block.ff) {
		if (pos[l] <= block.ss) return l;
		return -1;
	}
	if (pos[r] <= block.ss) return r;
	return -1;
}

int find_r(ii block, vi pos) {
	int sz = pos.size();
	if (sz == 0) return -1;
	int l = 0;
	int r = sz - 1;
	if (pos[l] > block.ss) return -1;
	if (pos[r] <= block.ss) {
		if (pos[r] >= block.ff) return r;
		return -1;
	}
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (pos[m] <= block.ss) l = m;
		else r = m;
	}
	if (pos[r] <= block.ss) {
		if (pos[r] >= block.ff) return r;
		return -1;
	}
	if (pos[l] >= block.ff) return l;
	return -1;
}

void solve() {
	string a, b;
	cin >> a >> b;
	int sz_a = a.size();
	int sz_b = b.size();
	int maxi = max(sz_a, sz_b);
	string ceros = "";
	For(i,0,maxi) ceros += '0';
	bool nulo = true;
	For(i,0,sz_b)
		if (b[i] == '1') {
			nulo = false;
			break;
		}
	if (nulo) {
		cout << "0" << endl;
		return;
	}
	string A, B;
	A = B = ceros;
	For(i,0,sz_a) A[maxi - 1 - i] = a[sz_a - 1 - i];
	For(i,0,sz_b) B[maxi - 1 - i] = b[sz_b - 1 - i];
	//debug(A);
	//debug(B);
	For(i,0,maxi) {
		if (A[i] == '0' and B[i] == '1') {
			A[i] = '1';
			B[i] = '0';
		}
	}
	//debug(A);
	//debug(B);
	vi pos;
	For(i,0,maxi) if (B[i] == '1') pos.pb(i);
	vii bloques;
	For(i,0,maxi) {
		//debug(i);
		if (A[i] == '1') {
			int j = i;
			while (j < maxi) {
				if (A[j] == '1') j++;
				else break;
			}
			bloques.pb(mp(i, j - 1));
			i = j;
		}
	}
	int sz = bloques.size();
	//debug(sz);
	ll ans = 0;
	For(i,0,sz) {
		int l = find_l(bloques[i], pos);
		int r = find_r(bloques[i], pos);
		//debug(l);
		//debug(r);
		if (l == -1 or r == -1) continue;
		ll temp = 0;
		For(j,l,r+1) {
			if (j == l) {
				ll steps = pos[j] - bloques[i].ff + 2LL;
				temp = max(temp, steps);
			} else {
				ll steps = pos[j] - pos[j - 1] + 1LL;
				temp = max(temp, steps);
			}
		}
		ans = max(ans, temp);
	}
	if (ans == 0) ans++;
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
