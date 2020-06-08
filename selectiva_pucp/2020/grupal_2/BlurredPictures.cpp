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

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e5 + 5;
const int LG = 17;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SparseTable {
	Pair st[N][LG + 1];
    Pair combine(Pair a, Pair b) {
        Pair ans;
        ans.first = max(a.first, b.first);
        ans.second = min(a.second, b.second);
        return ans;
    }
	void build(vector<Pair> &a, int n) {
		for (int i = 0; i < n; i++) st[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	Pair query(int l, int r) {
		int t = r - l + 1;
		int lg = 32 - (__builtin_clz(t) + 1);
		return combine(st[l][lg], st[r - (1 << lg) + 1][lg]);
	}
} st;

bool check(Long l, Long r) {
    Pair temp = st.query(l, r);
    if (temp.first > temp.second) return false;
    Long ancho = temp.second - temp.first + 1;
    Long alto = r - l + 1;
    return ancho >= alto;
}

Long calc(Long l, Long r) {
    Pair temp = st.query(l, r);
    Long ancho = temp.second - temp.first + 1;
    Long alto = r - l + 1;
    return min(ancho, alto);
}

Long search(Long cur) {
    Long l = 0;
    Long r = cur;
    if (check(l, cur)) return cur + 1;
    while (r - l > 1) {
        Long m = (l + r) / 2;
        if (check(m, cur)) r = m;
        else l = m;
    }
    if (check(l, cur)) return calc(l, cur);
    return calc(r, cur);
}

void solve() {
    Long n;
    cin >> n;
    vector<Pair> p(n, {0, 0});
    For(i,0,n) cin >> p[i].first >> p[i].second;
    st.build(p, n);
    Long ans = 0;
    For(i,0,n) ans = max(ans, search(i));
    cout << ans << endl; 
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}