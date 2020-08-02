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

const int N = 200;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<Long> caracteres;
bool possible = false;
deque<Long> sol;
Long sz;
Long freq[N];

void brute_force(Long pos) {
    if (pos == sz) {
        Long not_found = 0;
        for (auto it = sol.begin(); it != sol.end(); it++) {
            Long cur = *it;
            if (freq[cur] <= 0) not_found++;
            freq[cur]--;
        }
        if (not_found <= 1) possible = true;
        else {
            for (auto it = sol.begin(); it != sol.end(); it++) {
                Long cur = *it;
                freq[cur]++;
            }
        }
    } else {
        // no se puede
        if (caracteres[pos] == 0) return;
        // si se puede
        sol.push_back(caracteres[pos]);
        brute_force(pos + 1);
        if (possible) return;
        sol.pop_back();
        // si se pueden dos caracteres
        if (pos < sz - 1) {
            sol.push_back(10 * caracteres[pos] + caracteres[pos + 1]);
            brute_force(pos + 2);
            if (possible) return;
            sol.pop_back();
        }
    }
}

void solve() {
    Long target;
    cin >> target;
    Long copy = target;
    while (copy > 0) {
        Long digit = copy % 10;
        caracteres.push_back(digit);
        copy /= 10;
    }
    reverse(all(caracteres));
    sz = caracteres.size();

    Long n;
    cin >> n;
    Long a[n];
    For(i, 0, n) cin >> a[i];
    For(i, 0, n) freq[a[i]]++;
    // Resuelvo el problema
    brute_force(0);
    if (possible) cout << 1 << endl;
    else cout << 0 << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}