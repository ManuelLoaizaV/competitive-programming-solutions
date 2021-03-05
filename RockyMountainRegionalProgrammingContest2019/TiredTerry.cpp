//https://open.kattis.com/contests/uryqeu/problems/tiredterry
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
  Long n, p, d;
  cin >> n >> p >> d;
  string s;
  cin >> s;
  s = s + s;
  vector<Long> acc(2 * n, 0);
  if (s[0] == 'Z') acc[0] = 1;
  for (int i = 1; i < 2 * n; i++) {
    acc[i] = acc[i - 1];
    if (s[i] == 'Z') acc[i]++;
  }
  Long ans = 0;
  for (int i = 0; i < n; i++) {
    int r = n + i;
    int l = r - p + 1;
    Long cnt = acc[r] - ((l == 0) ? 0LL : acc[l - 1]);
    if (cnt < d) ans++;
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

