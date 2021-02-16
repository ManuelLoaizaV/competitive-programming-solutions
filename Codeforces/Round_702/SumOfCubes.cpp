//https://codeforces.com/contest/1490/problem/C
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e4;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long Cube(Long a) {
  return a * a * a;
}

Long Find(Long x) {
  Long l = 1;
  Long r = N;
  if (Cube(r) <= x) return r;
  while (r - l > 1) {
    Long m = (l + r) / 2;
    if (Cube(m) <= x) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void Solve(void) {
  Long x;
  cin >> x;
  for (Long a = 1; Cube(a) <= x; a++) {
    Long rem = x - Cube(a);
    if (rem == 0) continue;
    Long b = Find(rem);
    if (Cube(a) + Cube(b) == x) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

