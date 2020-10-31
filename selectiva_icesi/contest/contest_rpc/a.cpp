// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

void Solve(void) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ans = s;
  k--;
  while (k--) {
    int mx = 0;
    for (int pos = 1; pos < n; pos++) {
      bool ok = true;
      for (int i = 0; i < pos; i++) {
        if (s[i] == ans[ans.size() - pos + i]) continue;
        ok = false;
        break;
      }
      if (ok) mx = pos;
    }
    for (int pos = mx; pos < n; pos++) {
      ans += s[pos];
    }
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
