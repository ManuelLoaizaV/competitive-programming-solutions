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

long double dist(pair<long long, long long> a, pair<long long, long long> b) {
    long double dx = a.first - b.first;
    long double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void solve() {
    pair<long long, long long> post, c1, c2;
    cin >> post.first >> post.second;
    cin >> c1.first >> c1.second;
    cin >> c2.first >> c2.second;
    pair<long long, long long>  ld, ru;
    ld.first = min(c1.first, c2.first);
    ld.second = min(c1.second, c2.second);
    ru.first = max(c1.first, c2.first);
    ru.second = max(c1.second, c2.second);
    long double ans;
    int x, y;
    if (post.first <= ld.first) x = 1;
    if (ld.first <= post.first and post.first <= ru.first) x = 2;
    if (ru.first <= post.first) x = 3;
    if (post.second <= ld.second) y = 1;
    if (ld.second <= post.second and post.second <= ru.second) y = 2;
    if (ru.second <= post.second) y = 3;
    if (x == 1 and y == 1) ans = dist(post, ld);
    if (x == 1 and y == 2) ans = abs(post.first - ld.first);
    if (x == 1 and y == 3) ans = dist(post, {ld.first, ru.second});
    if (x == 2 and y == 1) ans = abs(post.second - ld.second);
    if (x == 2 and y == 2) ans = 0.0;
    if (x == 2 and y == 3) ans = abs(post.second - ru.second);
    if (x == 3 and y == 1) ans = dist(post, {ru.first, ld.second});
    if (x == 3 and y == 2) ans = abs(post.first - ru.first);
    if (x == 3 and y == 3) ans = dist(post, ru);
    cout << fixed << setprecision(3) << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
