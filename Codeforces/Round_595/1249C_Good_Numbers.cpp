//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

string s;
int sz;

ll bin_pow(ll a, int b) {
	if (b == 0) return 1LL;
	ll aux = bin_pow(a, b / 2);
	if (b & 1) return aux * aux* a;
	return aux * aux;
}

void to_base_3(ll n) {
	s = "";
	while (n > 0) {
		s = char('0' + n % 3) + s;
		n /= 3;
	}
	sz = s.size();
}

int find_2() {
	int ans = -1;
	roF(i,sz-1,0) if (s[i] == '2') ans = i;
	return ans;
}

int find_0(int pos) {
	roF(i,pos,0) if (s[i] == '0') return i;
	return -1;
}

ll to_base_10() {
	ll ans = 0LL;
	roF(i,sz-1,0) if (s[i] == '1') ans += (bin_pow(3LL, sz - 1 - i));
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	to_base_3(n);
	//debug(s);
	int pos_2 = find_2();
	//debug(pos_2);
	if (pos_2 == -1) {
		cout << n << endl;
		return;
	}
	For(i,pos_2,sz) s[i] = '0';
	int pos_0 = find_0(pos_2 - 1);
	//debug(pos_0);
	if (pos_0 == -1) {
		cout << bin_pow(3LL, sz) << endl;
		return;
	}
	For(i,pos_0,pos_2+1) s[i] = '0';
	s[pos_0] = '1';
	cout << to_base_10() << endl;
}

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}
