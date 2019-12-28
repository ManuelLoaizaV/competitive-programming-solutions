// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
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
const int INF = 1e9;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int x[n];
	For(i,0,n) cin >> x[i];
	sort(x, x + n);
	int maxi, mini;
	set<int> Maxi;
	int copy[n];
	For(i,0,n) copy[i] = x[i];
	copy[0]--;
	For(i,1,n) if (copy[i] > copy[i - 1] + 1) copy[i]--;
	copy[n - 1]++;
	roF(i,n-2,0) if (copy[i] + 1 < copy[i + 1]) copy[i]++;
	For(i,0,n) Maxi.insert(copy[i]);
	maxi = Maxi.size();
	set<int> Mini;
	For(i,0,n) Mini.insert(x[i]);
	vi uni;
	std::set<int>::iterator it;
	for (it = Mini.begin(); it != Mini.end(); it++) uni.pb(*it);
	int sz = uni.size();
	sort(all(uni));
	mini = sz;
	if (mini > 1) {	
		For(i,1,sz) {
			if (i < sz - 1 and uni[i - 1] + 2 == uni[i + 1]) {
				mini -= 2;
				i += 2;
			} else {
				if (uni[i] - uni[i - 1] <= 2) {
					mini--;
					i++;
				}
			}
		}
	}
	cout << mini << " " << maxi << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
