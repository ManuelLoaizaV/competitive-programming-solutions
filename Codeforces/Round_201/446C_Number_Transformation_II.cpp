//https://codeforces.com/contest/346/problem/C
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e5;
const int DIF = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

// Sea DP: N -> N, donde DP(len) es la minima cantidad de pasos para llegar desde
// b + len hasta b. De esta manera, obtenemos DP(len) = min{DP(len - t) + 1}, donde
// t es todo aquel valor posible que puedo alcanzar.
// Las reglas de movimiento del problema hacen que t pueda valer
// 1 o (b + len) % x_i con 1 <= i <= n.
// 
// Lema: DP es no decreciente.
// 
// Prueba: Sea DP(len) = DP(len - T) + 1. donde T es el t que nos permite optimamente
// minimizar lo requerido.
//
// Cuando T = 1, tenemos
// DP(len - 1) + 1 = DP(len)
// DP(len - 1) <= DP(len).
//
// Cuando T > 1, tenemos
// DP(len - T) < DP(len - 1)
// DP(len - T) + 1 <= DP(len - 1)
// DP(len) <= DP(len - 1).
// Asimismo, existe x_i tal que
// (b + len) - (b + len) % x_i = b + len - T
// No tiene sentido escoger (b + len) = 0 (mod x_i) por lo que
// 0 < (b + len) % x_i < x_i.
// De esta manera, podemos reescribir lo anterior como
// (b + len) - (b + len - 1 + 1) % x_i = b + len - T
// (b + len - 1) - (b + len - 1) % x_i = b + len - T.
// Obtenemos DP(len - 1) = DP(len - T) + 1
// DP(len - 1) = DP(len).
//
// Finalmente, hemos probado que DP(len - 1) <= DP(len).

set<Long> x;
int a, b;

int DP(int len) {
  int from = b + len;
  if (from == b) return 0;
  int best = from - 1;
  vector<int> ban;
  for (int x_i : x) {
    int to = from - (from % x_i);
    if (to < b) {
      ban.push_back(x_i);
    } else {
      if (to < best) {
        best = to;
      }
    }
  }
  for (int x_i : ban) x.erase(x_i);
  return 1 + DP(best - b);
}

void Solve(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int aux;
    cin >> aux;
    x.insert(aux);
  }
  cin >> a >> b;
  cout << DP(a - b) << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
