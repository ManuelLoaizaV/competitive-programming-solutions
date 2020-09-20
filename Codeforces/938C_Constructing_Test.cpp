#include <iostream>
#include <cmath>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
typedef long long Long;
typedef pair<Long, Long> Pair;

Long f(Long n, Long m) {
  Long res = n / m;
  return (n * n - res * res);
}

Long Search(Long n, Long x) {
  Long l = 2LL;
  Long r = n;
  if (f(n, r) <= x) return r;
  if (f(n, l) > x) return -1;
  while (r - l > 1) {
    Long m = (l + r) / 2;
    if (f(n, m) <= x) l = m;
    else r = m;
  }
  if (f(n, r) <= x) return r;
  return l;
}

void Solve() {
  Long x;
  cin >> x;
  if (x == 0) {
    cout << "1 1" << '\n';
    return;
  }
  if (x == 1) {
    cout << -1 << '\n';
    return;
  }
  Long lim = sqrt(4.0  * x / 3);
  Pair ans = {-1, -1};
  for (Long n = 2; n <= lim; n++) {
    Long m = Search(n, x);
    if ((m != -1) && f(n, m) == x) {
      ans.first = n;
      ans.second = m;
      break;
    }
  }
  if (ans.first != -1) {
    cout << ans.first << " " << ans.second << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main() {
  FAST_IO;
  Long t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
