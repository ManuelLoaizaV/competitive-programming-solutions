//https://open.kattis.com/contests/uryqeu/problems/integerdivision
#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

void Solve(void) {
  Long n, d;
  cin >> n >> d;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<Long, Long> cnt;
  for (int i = 0; i < n; i++) cnt[a[i] / d]++;
  Long ans = 0;
  for (auto p : cnt) {
    Long m = p.second;
    ans += m * (m - 1) / 2;
  }
  cout << ans << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}