//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << endl
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  int n;
  cin >> n;
  int ans = INT_MAX;
  vector<vector<int>> pos(n + 1, vector<int> ());
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x].push_back(i);
  }
  for (int x = 1; x <= n; x++) {
    if (pos[x].size() == 0) continue;
    int tmp = 2;
    int len = pos[x].size();
    if (pos[x][0] == 0) tmp--;
    if (pos[x][len - 1] == (n - 1)) tmp--;
    for (int i = 1; i < len; i++) if (pos[x][i] != (pos[x][i - 1] + 1)) tmp++;
    ans = min(ans, tmp);
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
