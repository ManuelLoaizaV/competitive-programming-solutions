//https://codeforces.com/contest/1486/problem/A
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

void Solve(void) {
  Long n;
  cin >> n;
  vector<Long> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  Long current = h[0];
  h[0] = 0;
  for (int i = 1; i < n; i++) {
    h[i] += current;
    if (h[i] <= h[i - 1]) {
      cout << "NO" << '\n';
      return;
    } else {
      Long nxt = h[i - 1] + 1;
      current = h[i] - nxt;
      h[i] = nxt;
    }
  }
  cout << "YES\n";
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

