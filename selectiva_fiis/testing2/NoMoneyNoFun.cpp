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
const Long N = 15;
const Long M = 2e2;
const Long INF = 1e18;
const Double EPS = 10e-9;
const Long MOD = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Participante {
	string nombre;
	set<Long> temas;
};
vector<Participante> participantes;
vector<Long> problemas;
Long numero_participantes, numero_problemas;
Long limite;

Long add(Long a, Long b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

Long get_bit(Long mask, Long bit) {
	return (mask >> bit) & 1LL;
}

void turn_on(Long& mask, Long bit) {
	mask = mask | (1LL << bit);
}

Long dp[M][1 << N];
bool done[M][1 << N];

// DP(i, j) : numero de maneras de terminar los problemas [i ... n - 1]
// habiendo utilizado a los jugadores de las mascara j
Long DP(Long pos, Long mask) {
	if (mask == (limite - 1)) return 0LL;
	if (pos == numero_problemas) return 1LL;
	if (done[pos][mask]) return dp[pos][mask];
	dp[pos][mask] = 0LL;
	for (Long bit = 0; bit < numero_participantes; bit++) {
		if (get_bit(mask, bit) == 0) {
			if (participantes[bit].temas.count(problemas[pos]) > 0) {
				dp[pos][mask] = add(dp[pos][mask], DP(pos + 1, mask));
			} else {
				Long copy = mask;
				turn_on(copy, bit);
				dp[pos][mask] = add(dp[pos][mask], DP(pos + 1, copy));
			}
		}
	}
	done[pos][mask] = true;
	return dp[pos][mask];
}

void solve() {
	cin >> numero_participantes >> numero_problemas;
	map<string, Long> Hash;
	For(i, 0, numero_participantes) {
		Participante aux;
		cin >> aux.nombre;
		Long k;
		cin >> k;
		while (k--) {
			string tema;
			cin >> tema;
			Long value;
			if (Hash.count(tema) > 0) {
				value = Hash[tema];
			} else {
				value = Hash.size();
				Hash[tema] = value;
			}
			aux.temas.insert(value);
		}
		participantes.push_back(aux);
	}
	For(i, 0 ,numero_problemas) {
		string problema;
		cin >> problema;
		Long value;
		if (Hash.count(problema) > 0) {
				value = Hash[problema];
			} else {
				value = Hash.size();
				Hash[problema] = value;
			}
		problemas.push_back(value);
	}
	limite = 1LL << numero_participantes;
	Long ans = DP(0, 0);
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}