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
	int n, k;
	cin >> n >> k;
	ll ans = 0LL;
	string s;
	cin >> s;
	bool found[26];
	For(i,0,26) found[i] = false;
	For(i,0,k) {
		char c;
		cin >> c;
		found[c - 'a'] = true;
	}
	vector<ll> bloques;
	For(i,0,n) {
		if (found[s[i] - 'a']) {
			int j = i;
			while (j < n) {
				if (found[s[j] - 'a']) j++;
				else break;
			}
			bloques.pb((ll)(j - i));
			i = j;
		}
	}
	int sz = bloques.size();
	For(i,0,sz) {
		//debug(bloques[i]);
		ans += (bloques[i] * (bloques[i] + 1) / 2LL);
	}
	cout << ans << endl;
	return 0;
}
