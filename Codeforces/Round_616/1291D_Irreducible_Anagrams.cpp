// Gracias, Rodolfo
// Gracias, Roman
// Gracias, Maxi
// Gracias, MarcosK
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()
#define SZ(v) ((int)v.size())

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	string s;
	cin >> s;
	int sz = s.size();
	vector<int> pos[26];
	for (int i = 0; i < sz; i++) {
		int c = s[i] - 'a';
		pos[c].push_back(i + 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) cout << "Yes" << endl;
		else {
			int freq[26];
			for (int i = 0; i < 26; i++) freq[i] = 0;
			// hallo las frecuencias
			for (int i = 0; i < 26; i++) freq[i] = upper_bound(pos[i].begin(), pos[i].end(), r) - lower_bound(pos[i].begin(), pos[i].end(), l);
			int cnt = 0;
			for (int i = 0; i < 26; i++) if (freq[i] > 0) cnt++;
			if (cnt == 1) cout << "No" << endl;
			else {
				if (cnt == 2) {
					vector<int> who;
					for (int i = 0; i < 26; i++) if (freq[i] > 0) who.push_back(i);
					pair<int, int> ind[2];
					for (int i = 0; i < 2; i++) {
						int j = who[i];
						int fst = pos[j][lower_bound(pos[j].begin(), pos[j].end(), l) - pos[j].begin()];
						int snd = pos[j][upper_bound(pos[j].begin(), pos[j].end(), r) - pos[j].begin() - 1];
						ind[i] = {fst, snd};
					}
					bool ok = true;
					for (int i = 0; i < 2; i++) if (l < ind[i].first and ind[i].second < r) ok = false;
					if (ok) cout << "Yes" << endl;
					else cout << "No" << endl;
				} else {
					cout << "Yes" << endl;
				}
			}
		}
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}