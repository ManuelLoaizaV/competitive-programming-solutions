// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 100005;
const int ALPH = 26;
const ll INF = 1e18;
const ld EPS = 10e-9;

int tree[N + 1][ALPH];
int query(int i, int c) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i][c];
		i -= (i & -i);
	}
	return sum;
}

int update(int i, int delta, int c) {
	while (i <= N) {
		tree[i][c] += delta;
		i += (i & -i);
	}
}

int main() {
	fastio;
	string s;
	cin >> s;
	int sz = s.size();
	For(i,0,sz) update(i + 1, 1, s[i] - 'a');
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			char p = s[pos - 1];
			update(pos, -1, p - 'a');
			update(pos, 1, c - 'a');
			s[pos - 1] = c;
		} else {
			int l, r;
			cin >> l >> r;
			int count = 0;
			For(i,0,ALPH) {
				int acc = query(r, i) - query(l - 1, i);
				if (acc > 0) count++;
			}
			cout << count << endl;
		}
	}
	return 0;
}
