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
  Long n, x;
  cin >> n >> x;
  if (n <= 2) {
    cout << 1 << '\n';
  } else {
    Long num = n - 2 + x;
    Long den = x;
    Long piso = (num + den - 1) / den;
    cout << piso << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
