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

const int N = 100;
const ll INF = 1e18;
const ld EPS = 10e-9;

void solve() {
	int n;
	cin >> n;
	bool a[N + 5];
	memset(a, 0, sizeof(a));
	int ans = 1;
	For(i,0,n) {
		int aux;
		cin >> aux;
		a[aux] = true;
		if (a[aux - 1] or a[aux + 1]) ans = 2;
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}
