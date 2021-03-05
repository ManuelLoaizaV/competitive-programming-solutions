//https://open.kattis.com/contests/uryqeu/problems/lostlineup
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
  Long n;
  cin >> n;
  vector<Pair> p(n);
  p[0] = {-1, 1};
  for (int i = 1; i < n; i++) {
    cin >> p[i].first;
    p[i].second = i + 1;
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << p[i].second;
  }
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

