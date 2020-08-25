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

Long solve() {
	string country;
  cin >> country;
  vector<Long> pos[26];
  int size = country.size();
  For(i, 0, size) {
    pos[country[i] - 'a'].push_back(i);
  }
  bool ok = false;
  Long ans = INF;
  For(letter, 0, 26) {
    For(i, 1, pos[letter].size()) {
      ans = min(ans, pos[letter][i] - pos[letter][i - 1]);
      ok = true;
    }
  }
  if (ok) return ans;
  return -1;
}

int main() {
  fastio;
  int t = 1;
  cin >> t;
  For(i, 0, t) {
    cout << "Case #" << i + 1 << ": " << solve() << endl;
  }
  return 0;
}