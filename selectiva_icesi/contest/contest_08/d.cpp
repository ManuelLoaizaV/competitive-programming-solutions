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
  Long n;
  cin >> n;
  Pair p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  Long max_izq[n + 2], max_der[n + 2];
  Long min_izq[n + 2], min_der[n + 2];
  // Extremos izquierdos
  max_izq[0] = -INF;
  for (int i = 1; i <= n; i++) {
    max_izq[i] = max(max_izq[i - 1], p[i - 1].first);
  }
  max_izq[n + 1] = max_izq[n];
  max_der[n + 1] = -INF;
  for (int i = n; i >= 1; i--) {
    max_der[i] = max(max_der[i + 1], p[i - 1].first);
  }
  max_der[0] = max_der[1];
  // Extremos derechos
  min_izq[0] = INF;
  for (int i = 1; i <= n; i++) {
    min_izq[i] = min(min_izq[i - 1], p[i - 1].second);
  }
  min_izq[n + 1] = min_izq[n];
  min_der[n + 1] = INF;
  for (int i = n; i >= 1; i--) {
    min_der[i] = min(min_der[i + 1], p[i - 1].second);
  }
  // Si elimino el i-esimo
  Long ans = 0;
  for (int i = 1; i <= n; i++) {
    Long l = max(max_izq[i - 1], max_der[i + 1]);
    Long r = min(min_izq[i - 1], min_der[i + 1]);
    Long temp;
    if (l > r) {
      temp = 0;
    } else {
      temp = r - l;
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
