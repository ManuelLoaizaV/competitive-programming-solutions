//https://codeforces.com/contest/1487/problem/D
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

Long GetBit(Long mask, Long bit) { return (mask >> bit) & 1LL; }
void TurnOn(Long& mask, Long bit) { mask = mask | (1LL << bit); }
void TurnOff(Long& mask, Long bit) { mask = mask & (~(1 << bit)); }

// a^2 + b^2 = c^2
// c = a^2 -b
// Entonces b(b + 1) = c(c - 1)
// Asimismo a^2 <= c + b <= 2n
// Luego a <= sqrt(2n)

Long GetOdd(Long n) {
  return (n + 1) / 2;
}

void Solve(void) {
  Long n;
  cin >> n;
  Long l = 3;
  Long r = sqrt(2 * n - 1);
  Long ans = 0;
  if (l <= r) ans = GetOdd(r) - GetOdd(l - 1);
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

