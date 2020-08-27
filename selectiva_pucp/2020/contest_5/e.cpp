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

Long get_bit(Long mask, Long bit) {
	return (mask >> bit) & 1LL;
}

void turn_on(Long& mask, Long bit) {
	mask = mask | (1LL << bit);
}

void turn_off(Long& mask, Long bit) {
	mask = mask & (~(1 << bit));
}

void solve() {
	Long n;
	cin >> n;
	Long limit = 1LL << n;
	Long a[limit];
	For(i, 0 , limit) cin >> a[i];
	vector<Long> ward[limit];
	// Caso base: todos tienen a un solo elemento
	For(i, 0, limit) ward[i].push_back(a[i]);
	// Desde abajo hacia arriba, analizare a todos a los que llega
	For(bit, 0, n) {
		For(from, 0, limit) {
			//debug(bit, from);
			if (get_bit(from, bit) == 0) {
				Long mask = from;
				turn_on(mask, bit);
				vector<Long> aux;
				For(i, 0, ward[from].size()) aux.push_back(ward[from][i]);
				For(i, 0, ward[mask].size()) aux.push_back(ward[mask][i]);
				sort(all(aux));
				vector<Long> cur;
				cur.push_back(aux[aux.size() - 2]);
				cur.push_back(aux[aux.size() - 1]);
				ward[mask] = cur;
				//debug(mask, ward[from], ward[mask]);
			}
		}
	}
	Long sum = 0;
	For(k, 1, limit) {
		sum = max(sum, ward[k][0] + ward[k][1]);
		cout << sum << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}