//https://codeforces.com/contest/1486/problem/B
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

Long f(const vector<Long>& x, const vector<Long>& sum, Long target) {
  Long pos = lower_bound(x.begin(), x.end(), target) - x.begin();
  Long n = x.size();
  Long ans = 0;
  if (pos == n) {
    ans = n * target - sum[n - 1];
  } else {
    if (pos == 0) {
      ans = sum[n - 1] - n * target;
    } else {
      ans = pos * target - sum[pos - 1] + sum[n - 1] - sum[pos - 1] - (n - pos) * target;
    }
  }
  return ans;
}

Long LeftSearch(Long l, Long r, Long val, const vector<Long>& x, const vector<Long>& sum) {
  if (f(x, sum, l) <= val) return l;
  while (r - l > 1) {
    Long m = (l + r) / 2;
    if (f(x, sum, m) <= val) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

Long RightSearch(Long l, Long r, Long val, const vector<Long>& x, const vector<Long>& sum) {
  if (f(x, sum, r) <= val) return r;
  while (r - l > 1) {
    Long  m = (l + r) / 2;
    if (f(x, sum, m) <= val) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

Pair Solve(const vector<Long>& x, int n) {
  Long l = x[0];
  Long r = x[n - 1];
  vector<Long> sum(n);
  sum[0] = x[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + x[i];
  while (r - l > 2) {
    Long m1 = l + (r - l) / 3;
    Long m2 = r - (r - l) / 3;
    Long f1 = f(x, sum, m1);
    Long f2 = f(x, sum, m2); 
    if (f1 > f2) {
      l = m1;
    } else {
      r = m2;
    }
  }
  Long mn, f_min;
  mn = l;
  f_min = f(x, sum, l);
  for (Long i = l; i <= r; i++) {
    Long cur = f(x, sum, i);
    if (cur < f_min) {
      mn = i;
      f_min = cur;
    }
  }
  Pair ans = {LeftSearch(x[0], mn, f_min, x, sum), RightSearch(mn, x[n - 1], f_min, x, sum)};
  return ans;
}

void Solve(void) {
  Long n;
  cin >> n;
  vector<Long> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  Pair x_range = Solve(x, n);
  Pair y_range = Solve(y, n);
  //debug(x, y);
  //debug(x_range, y_range);
  Long ans = (x_range.second - x_range.first + 1) * (y_range.second - y_range.first + 1);
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

