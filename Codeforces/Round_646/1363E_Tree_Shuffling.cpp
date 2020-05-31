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

const int N = 2e5 + 5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N];
Long zero_one, one_zero, ans;

struct Node {
    Long val, from, to;
} nodes[N];

void DFS(Long u, Long p = -1) {
    if (nodes[u].from == 0 and nodes[u].to == 1) zero_one++;
    if (nodes[u].from == 1 and nodes[u].to == 0) one_zero++;
    if (u != 1) nodes[u].val = min(nodes[u].val, nodes[p].val);
    for (int v : adj[u]) if (v != p) DFS(v, u);
}

Pair DFS2(Long u, Long p = -1) {
    Pair cur = {0, 0};
    if (nodes[u].from == 0 and nodes[u].to == 1) cur.first++;
    if (nodes[u].from == 1 and nodes[u].to == 0) cur.second++;
    for (int v : adj[u]) {
        if (v != p) {
            Pair temp = DFS2(v, u);
            cur.first += temp.first;
            cur.second += temp.second;
        }
    }
    Long eq = min(cur.first, cur.second);
    ans += 2 * eq * nodes[u].val;
    cur.first -= eq;
    cur.second -= eq;
    return cur;
}

void solve() {
    Long n;
    cin >> n;
    For(i,1,n+1) cin >> nodes[i].val >> nodes[i].from >> nodes[i].to;
    For(i,0,n-1) {
        Long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    if (zero_one != one_zero) {
        cout << "-1" << endl;
        return;
    }
    DFS2(1);
    cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}