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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long n, m;
map<Long, pair<Long, Long>> ward;

Long f(Long cur) {
    Long temp = n - 1;
    std::map<Long, Pair>::iterator it;
    for (it = ward.begin(); it != ward.end(); it++) {
        Long maxi = (it->second).second;
        Long mini = (it->second).first;
        if (maxi > cur) temp += 2 * (maxi - cur);
        if (mini < cur) temp += 2 * (cur - mini);
    }
    return temp;
}

void solve() {
    cin >> n >> m;
    Long k;
    cin >> k;
    Pair p[k];
    For(i,0,k) cin >> p[i].second >> p[i].first;
    sort(p, p + k);
    Long ans = INF;
    For(i,0,k) {
        Long x = p[i].first;
        Long y = p[i].second;
        if (ward.count(y) > 0) {
            ward[y].first = min(ward[y].first, x);
            ward[y].second = max(ward[y].second, x);
        } else {
            ward[y] = {x, x};
        }
    }
    Long l = 0;
    Long r = m;
    while (r - l > 3) {
        Long m1 = l + (r - l) / 3;
        Long m2 = r - (r - l) / 3;
        Long f1 = f(m1);
        Long f2 = f(m2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
    For(i,l,r+1) ans = min(ans, f(i));
    cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	while (t--) solve();
	return 0;
}