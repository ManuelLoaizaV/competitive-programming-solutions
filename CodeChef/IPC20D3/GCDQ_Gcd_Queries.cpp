#include <algorithm>
#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

void Solve(void) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> l(n);
  vector<int> r(n);
  l[0] = a[0];
  for (int i = 1; i < n; i++) l[i] = __gcd(a[i], l[i - 1]);
  r[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) r[i] = __gcd(a[i], r[i + 1]);

  while (q--) {
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    if (L == 0) {
      cout << r[R + 1] << '\n';
    } else {
      if (R == n - 1) {
        cout << l[L - 1] << '\n';
      } else {
        int ans = __gcd(l[L - 1], r[R + 1]);
        cout << ans << '\n';
      }
    }
  }
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
