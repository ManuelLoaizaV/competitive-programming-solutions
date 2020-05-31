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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }
Long M;

Long query(Long l, Long r) {
    cout << "? " << r - l + 1;
    For(i,l,r+1) cout << " " << i;
    cout << endl; 
    Long x;
    cin >> x;
    return x;
}

Long search(Long l, Long r) {
    M = query(l, r);
    if (l == r) return l;
    while (l != r) {
        Long m = (l + r) / 2;
        Long cur = query(l, m);
        if (cur == M) r = m;
        else l = m + 1;
    }
    return l;
}

void solve() {
    Long n, k;
    cin >> n >> k;
    vector<Long> s[k];
    For(i,0,k) {
        Long sz;
        cin >> sz;
        For(j,0,sz) {
            Long x;
            cin >> x;
            s[i].push_back(x);
        }
    }
    Long pos = search(1, n);
    Long found = -1;
    For(i,0,k) {
        int sz = s[i].size();
        For(j,0,sz) {
            if (s[i][j] == pos) {
                found = i;
                break;
            }
        }
        if (found != -1) break;
    }
    if (found == -1) {
        cout << "!";
        For(i,0,k) cout << " " << M;
        cout << endl;
        string F;
        cin >> F;
        return;
    }
    Long p[k];
    For(i,0,k) p[i] = M;
    set<Long> mens;
    For(i,1,n+1) mens.insert(i);
    int sz = s[found].size();
    For(i,0,sz) mens.erase(s[found][i]);
    sz = mens.size();
    cout << "? " << sz;
    std::set<Long>::iterator it;
    for (it = mens.begin(); it != mens.end(); it++) cout << " " << *it;
    cout << endl;
    cin >> p[found];
    cout << "!";
    For(i,0,k) cout << " " << p[i];
    cout << endl;
    string F;
    cin >> F;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}