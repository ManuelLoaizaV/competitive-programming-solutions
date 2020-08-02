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

const int N = 1e2;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N];
bool visited[N];
Long d[N];

Double dist(Pair A, Pair B) {
    Double dx = ((Double) A.first) - ((Double) B.first);
    Double dy = ((Double) A.second) - ((Double) B.second);
    return sqrt(dx * dx + dy * dy);
}

bool check(Pair A, Pair B, Pair X) {
    Double ab = dist(A, B);
    Double ax = dist(A, X);
    Double xb = dist(X, B);
    if (fabs(ax + xb - ab) < EPS) return false;
    return true;
}

void BFS(int s) {
    d[s] = 0;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (not visited[v]) {
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    Long n;
    cin >> n;
    Pair team1[n], team2[n];
    For(i, 0, n) cin >> team1[i].first >> team1[i].second;
    For(i, 0, n) cin >> team2[i].first >> team2[i].second;
    For(i, 0, n - 1) {
        For(j, i + 1, n) {
            bool ok = true;
            For(k, 0, n) {
                if (check(team1[i], team1[j], team2[k])) continue;
                ok = false;
                break;
            }
            For(k, 0, n) {
                if (k == i or k == j) continue;
                if (check(team1[i], team1[j], team1[k])) continue;
                ok = false;
                break;
            }
            if (ok) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                //debug(i, j);
            }
        }
    }
    For(i, 0, n) d[i] = INF;
    For(i, 0, n) visited[i] = false;
    BFS(0);
    if (visited[n - 1]) cout << d[n - 1] << endl;
    else cout << -1 << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}