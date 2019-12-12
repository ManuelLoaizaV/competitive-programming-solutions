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
	string s;
	cin >> s;
	map<char,int> h;
	h['L'] = 0;
	h['R'] = 1;
	h['U'] = 2;
	h['D'] = 3;
	int sz = s.size();
	int freq[4];
	For(i,0,4) freq[i] = 0;
	For(i,0,sz) freq[h[s[i]]]++;
	freq[0] = freq[1] = min(freq[0], freq[1]);
	freq[2] = freq[3] = min(freq[2], freq[3]);
	bool pos = true;
	For(i,0,4) {
		if (freq[i] > 0) continue;
		pos = false;
		break;
	}
	if (pos) {
		int sum = 0;
		For(i,0,4) sum += freq[i];
		cout << sum << endl;
		For(i,0,freq[0]) cout << 'L';
		For(i,0,freq[2]) cout << 'U';
		For(i,0,freq[1]) cout << 'R';
		For(i,0,freq[3]) cout << 'D';
		cout << endl;
		return;
	}
	bool ceros = true;
	For(i,0,4) {
		if (freq[i] == 0) continue;
		ceros = false;
		break;
	}
	if (ceros) {
		cout << 0 << endl;
		return;
	}
	cout << "2" << endl;
	if (freq[0] > 0) cout << "LR" << endl;
	else cout << "UD" << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
