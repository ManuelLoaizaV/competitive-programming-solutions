//https://codeforces.com/contest/1487/problem/B
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

void Solve(void) {
  Long n, k;
  cin >> n >> k;
  Long ans = 0;
  if (n & 1) {
    Long mid = (n + 1) / 2;
    k--;
    Long block = mid - 1;
    Long times = k / block;
    Long pos = 1 + (1 + block) * times;
    if (k % block > 0) pos += k % block;
    ans = pos % n;
    if (ans == 0) ans = n;
  } else {
    k--;
    ans = (1 + k) % n;
    if (ans == 0) ans = n;
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

