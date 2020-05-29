// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (Long i = a; i < b; i++)
#define roF(i,a,b) for (Long i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

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

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long a[N];
Long n, k;

bool check(Double average) {
    Double b[n];
    For(i,0,n) b[i] = a[i] - average;
    Double prefix_sum[n];
    For(i,0,n) {
        if (i == 0) prefix_sum[i] = b[i];
        else prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }
    Double mini[n];
    For(i,0,n) {
        if (i == 0) mini[i] = prefix_sum[i];
        else mini[i] = min(mini[i - 1], prefix_sum[i]);
    }
    Double sum = 0.0;
    For(i,0,k) sum += b[i];
    if (sum >= 0) return true;
    For(i,k,n) {
        sum += b[i];
        Double prefix = mini[i - k];
        if (prefix > 0.0) prefix = 0.0;
        Double maxi = sum - prefix;
        if (maxi >= 0) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    For(i,0,n) cin >> a[i];
    Double l = 1.0;
    Double r = 1e6;
    if (check(r)) {
        cout << fixed << setprecision(10) << r << endl;
        return;
    }
    while (r - l > EPS) {
        Double m = (l + r) / (Double) 2;
        if (check(m)) l = m;
        else r = m;
    }
    if (check(r)) cout << fixed << setprecision(10) << r << endl;
    else cout << fixed << setprecision(10) << l << endl;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}