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

void solve() {
    Long n, k;
    cin >> n >> k;
    bool a[n + 1];
    For(i,0,n+1) a[i] = true;
    Long ans = 0;
    Long sum = 0;
    For(i,0,k) {
        Long x;
        cin >> x;
        Long y = x;
        while (y <= n) {
            if (a[y]) sum++;
            else sum--;
            a[y] = not a[y];
            y += x;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	while (t--) solve();
	return 0;
}