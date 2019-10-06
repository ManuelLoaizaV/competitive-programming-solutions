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

const int N = 2e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

map<int, int> h;
map<int, int> inv;
std::map<int, int>::iterator it;
bool found[N + 5];

int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	int id[n];
	For(i,0,n) {
		cin >> id[i];
		it = h.find(id[i]);
		if (it != h.end()) continue;
		int sz = h.size();
		h[id[i]] = sz + 1;
		inv[sz + 1] = id[i];
	}
	deque<int> ans;
	For(i,0,n) {
		int cur = h[id[i]];
		if (found[cur]) continue;
		int sz = ans.size();
		found[cur] = true;
		if (sz < k) ans.push_front(id[i]);
		else {
			int del = ans.back();
			found[h[del]] = false;
			ans.pop_back();
			ans.push_front(id[i]);
		}
	}
	int m = ans.size();
	cout << m << endl;
	For(i,0,m) cout << ans[i] << " ";
	return 0;
}
