//https://codeforces.com/contest/1490/problem/B
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

void Solve(void) {
  int n;
  cin >> n;
  vector<int> m(3, 0);
  for (int i = 0; i < n; i++) {
    Long x;
    cin >> x;
    m[x % 3]++;
  }
  int ans = 0;
  int target = n / 3;
  if (m[0] > target) {
    ans += m[0] - target;
    m[1] += m[0] - target;
    m[0] = target;
  }
  if (m[0] < target) {
    int need = target - m[0];
    if (m[2] > target) {
      int cnt = min(need, m[2] - target);
      m[0] += cnt;
      need -= cnt;
      m[2] -= cnt;
      ans += cnt;
    }
    if (m[1] > target) {
      int cnt = min(need, m[1] - target);
      m[0] += cnt;
      need -= cnt;
      m[1] -= cnt;
      ans += 2 * cnt;
    }
    m[0] = target;
  }
  if (m[1] > target) {
    ans += m[1] - target;
    m[1] = target;
  }
  if (m[1] < target) {
    ans += 2 * (target - m[1]);
    m[1] = target;
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

