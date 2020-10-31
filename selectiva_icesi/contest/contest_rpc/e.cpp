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
  int n, m;
  cin >> n >> m;
  int a[n][2][2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        cin >> a[i][j][k];
  if (m & 1) {
    cout << "NO" << '\n';
  } else {
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i][0][1] == a[i][1][0]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
