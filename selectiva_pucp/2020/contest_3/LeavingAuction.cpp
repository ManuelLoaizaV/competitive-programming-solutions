// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<pair<Long, Long>, null_type, less<pair<Long, Long>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 2e5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Vector bids[N + 5];
Long maxi[N + 5];

void solve() {
    Long n;
    cin >> n;
    For(i, 0, n) {
        Long who, cnt;
        cin >> who >> cnt;
        bids[who].push_back(cnt);
    }
    ordered_set Graphter;
    For(i, 0, n + 1) {
        maxi[i] = 0;
        Long sz = bids[i].size();
        if (sz > 0) {
            maxi[i] = bids[i][sz - 1];
            Graphter.insert({maxi[i], i});
        }
    }
    Long q;
    cin >> q;
    while (q--) {
        Long len;
        cin >> len;
        Long who[len];
        For(i, 0, len) {
            cin >> who[i];
            //cout << "who " << who[i] << endl;
            if (maxi[who[i]] > 0) Graphter.erase({maxi[who[i]], who[i]});
        }
        Long sz = Graphter.size();
        //cout << "sz " << sz << endl;
        if (sz == 0) {
            cout << 0 << " " << 0 << endl;
        }
        if (sz == 1) {
            Pair Hantroid = *Graphter.find_by_order(0);
            Long winner = Hantroid.second;
            Long cnt = bids[winner][0];
            cout << winner << " " << cnt << endl;
        }
        if (sz > 1) {
            Pair Hymsly = *Graphter.find_by_order(sz - 2);
            Long Mini = Hymsly.first;
            Pair Hantroid = *Graphter.find_by_order(sz - 1);
            Long winner = Hantroid.second;
            Long pos = upper_bound(all(bids[winner]), Mini) - bids[winner].begin();
            Long cnt = bids[winner][pos];
            cout << winner << " " << cnt << endl;
        }
        For(i, 0, len) if (maxi[who[i]] > 0) Graphter.insert({maxi[who[i]], who[i]});
    }
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}