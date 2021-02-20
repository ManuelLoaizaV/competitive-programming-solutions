//https://codeforces.com/contest/1486/problem/D
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

bool Check(vector<int> a, int median, int k) {
  int n = a.size();
  for (int i = 0; i < n; i++) a[i] = (a[i] >= median) ? 1 : -1;
  vector<int> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
  vector<int> mn(n);
  mn[0] = sum[0];
  for (int i = 1; i < n; i++) mn[i] = min(mn[i - 1], sum[i]);
  int mx = sum[k - 1];
  for (int i = k; i < n; i++) {
    int tmp = max(sum[i], sum[i] - mn[i - k]);
    mx = max(mx, tmp);
  }
  return mx > 0;
}

void Solve(void) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1;
  int r = n;
  if (Check(a, r, k)) {
    cout << r << '\n';
    return;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (Check(a, m, k)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

