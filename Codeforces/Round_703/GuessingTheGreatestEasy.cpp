//https://codeforces.com/contest/1486/problem/C1
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
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

Long GetBit(Long mask, Long bit) { return (mask >> bit) & 1LL; }
void TurnOn(Long& mask, Long bit) { mask = mask | (1LL << bit); }
void TurnOff(Long& mask, Long bit) { mask = mask & (~(1 << bit)); }

Long Query(Long l, Long r) {
  cout << "? " << l << " " << r << endl;
  Long ans;
  cin >> ans;
  return ans;
}

Long Finish(Long p) {
  cout << "! " << p << endl;
  return p;
}

Long Find(Long l, Long r, Long second_maximum) {
  Long m = (l + r) / 2;
  if (r - l <= 2) {
    if (r - l == 1) {
      return (second_maximum == r) ? l : r;
    } else {
      Long m = (l + r) / 2;
      if (second_maximum <= m) {
        Long nxt = Query(l, m);
        if (nxt == second_maximum) {
          if (second_maximum == l) return m;
          return l;
        } else {
          return r;
        }
      } else {
        Long nxt = Query(m, r);
        if (nxt == second_maximum) {
          if (second_maximum == r) return m;
          return r;
        } else {
          return l;
        }
      }
    }
  }
  if (second_maximum <= m) {
    Long new_second_maximum = Query(l, m);
    if (new_second_maximum == second_maximum) return Find(l, m, second_maximum);
    new_second_maximum = Query(m + 1, r);
    return Find(m + 1, r, new_second_maximum);
  } else {
    Long new_second_maximum = Query(m + 1, r);
    if (new_second_maximum == second_maximum) return Find(m + 1, r, second_maximum);
    new_second_maximum = Query(l, m);
    return Find(l, m, new_second_maximum);
  }
}

void Solve(void) {
  Long n;
  cin >> n;
  if (n == 1) {
    Finish(n);
    return;
  }
  if (n == 2) {
    Finish(3 - Query(1, 2));
    return;
  }
  Long second_maximum = Query(1, n);
  Long maximum = Find(1, n, second_maximum);
  Finish(maximum);
}

int main(void) {
  //FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

