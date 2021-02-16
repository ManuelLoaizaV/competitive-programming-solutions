//https://codeforces.com/contest/1490/problem/A
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

bool Check(Long a, Long b) {
  return b <= 2 * a;
}

void Solve(void) {
  Long n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  Long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      while (!Check(a[i + 1], a[i])) {
        a[i] = max(a[i + 1], a[i] / 2 + (a[i] & 1));
        ans++;
      }
    } else if (a[i] < a[i + 1]) {
      while (!Check(a[i], a[i + 1])) {
        a[i] = min(a[i + 1], 2 * a[i]);
        ans++;
      }
    }
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

