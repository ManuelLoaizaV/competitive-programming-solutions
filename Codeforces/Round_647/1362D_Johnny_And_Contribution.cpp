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

const int N = 5e5 + 5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<Long> adj[N];

Long mex(set<Long> &Set) {
    Long Mex = 1;
    while (Set.find(Mex) != Set.end()) Mex++;
    return Mex;
}

void solve() {
    Long n, m;
    cin >> n >> m;
    Pair edge[m];
    For(i,0,m) cin >> edge[i].first >> edge[i].second;
    Pair topic[n];
    Long original[n + 1];
    For(i,0,n) {
        cin >> topic[i].first;
        topic[i].second = i + 1;
        original[i + 1] = topic[i].first;
    }
    For(i,0,m) {
        Long u = edge[i].first;
        Long v = edge[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(topic, topic + n);
    For(i,1,n+1) {
        set<Long> Set;
        for (int v : adj[i]) Set.insert(original[v]);
        Long cur = original[i];
        if (Set.count(cur) > 0) {
            cout << "-1" << endl;
            return;
        }
        Long Mex = mex(Set);
        if (Mex < cur) {
            cout << "-1" << endl;
            return;
        }
    }
    For(i,0,n) cout << topic[i].second << " ";
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}