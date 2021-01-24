//https://atcoder.jp/contests/abc189/tasks/abc189_f
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Double, Double> Pair;

const int N = 1e6;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Pair operator + (const Pair& a, const Pair& b) {
  return {a.first + b.first, a.second + b.second};
}

Pair operator - (const Pair& a, const Pair& b) {
  return {a.first - b.first, a.second - b.second};
}

Pair operator / (const Pair& a, Double k) {
  return {a.first / k, a.second / k};
}

void Solve(void) {
  Long n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    vector<Double> dp(n + m + 2, 0.0);
    vector<Double> suffix(n + m + 2, 0.0);
    for (int i = n - 1; i >= 0; i--) {
      Double sum = suffix[i + 1] - suffix[i + m + 1];
      dp[i] = sum / m + 1;
      suffix[i] = dp[i] + suffix[i + 1];
    }
    cout << dp[0] << '\n';
  } else {
    vector<bool> is_hole(n + m + 2, false);
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      is_hole[a] = true;
    }
    vector<int> prefix(n + m + 2, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1];
      if (is_hole[i]) prefix[i]++;
    }
    for (int i = 1; i < n - m + 1; i++) {
      if (prefix[i + m - 1] - prefix[i - 1] == m) {
        cout << -1 << '\n';
        return;
      }
    } 
    vector<Pair> dp(n + m + 2, {0.0, 0.0});
    vector<Pair> suffix(n + m + 2, {0.0, 0.0});
    Pair one = {0.0, 1.0};
    for (int i = n - 1; i >= 0; i--) {
      if (is_hole[i]) {
        dp[i] = {1.0, 0};
      } else {
        Pair sum = suffix[i + 1] - suffix[i + m + 1];
        dp[i] = sum / m + one;
      }
      suffix[i] = dp[i] + suffix[i + 1];
    }
    Double ans = dp[0].second / (1.0 - dp[0].first);
    cout << fixed << setprecision(10) << ans << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

