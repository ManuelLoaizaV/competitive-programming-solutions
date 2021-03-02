//https://codeforces.com/contest/1494/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    Long n, m;
    cin >> n >> m;
    vector<Long> a(n);
    vector<Long> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int ans = 0;
    for (int it = 0; it < 2; it++) {
      int inia = -1;
      for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] > 0) {
          inia = i;
          break;
        }
      }
      int inib = -1;
      for (int i = 0; i < (int) b.size(); i++) {
        if (b[i] > 0) {
          inib = i;
          break;
        }
      }
      if (inia != -1 && inib != -1) {
        set<int> boxes;
        for (int x : b) boxes.insert(x);
        int len = (int) a.size();
        vector<int> dp(len + 1, 0);
        for (int i = len - 1; i >= 0; i--) {
          dp[i] = dp[i + 1];
          if (boxes.count(a[i]) > 0) dp[i]++;
        }
        // Caso base, no muevo a nadie
        int mx = dp[inia];
        // Puedo apilar 1, 2, .., max_len cajas hacia la derecha
        int max_len = (int) a.size() - inia;
        for (int sz = 1; sz <= max_len; sz++) {
          Long left = a[inia + sz - 1];
          Long right = (sz == max_len) ? (Long) 2e9 : a[inia + sz] - 1;
          int tmp = 0;
          int lb = lower_bound(b.begin(), b.end(), left) - b.begin();
          if (lb < (int) b.size()) {
            int rb = lb;
            while (rb < (int) b.size() && b[rb] <= right) rb++;
            rb--;
            for (int i = lb; i <= rb; i++) {
              int l = max(0, i - sz + 1);
              int r = i;
              if (b[l] >= b[i] - sz + 1) {
                tmp = max(tmp, i - l + 1);
              } else {
                while (r - l > 1) {
                  int m = (l + r) / 2;
                  if (b[m] >= b[i] - sz + 1) {
                    r = m;
                  } else {
                    l = m;
                  }
                }
                tmp = max(tmp, i - r + 1);
              }
            }
          }
          tmp += (sz == max_len) ? 0 : dp[inia + sz];
          mx = max(mx, tmp);
        }
        ans += mx;
      }
      // Modifico el arreglo para no repetir codigo
      if (it == 0) {
        while (a.size() > 0 && a.end()[-1] > 0) a.pop_back();
        while (b.size() > 0 && b.end()[-1] > 0) b.pop_back();
        for (Long& x : a) x *= -1;
        for (Long& x : b) x *= -1;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
      }
    }
    cout << ans << '\n';
  }
  return 0;
}