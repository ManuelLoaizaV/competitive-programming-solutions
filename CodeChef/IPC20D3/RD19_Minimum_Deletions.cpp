#include <algorithm>
#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

void Solve(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int gcd = a[0];
  for (int i = 1; i < n; i++) gcd = __gcd(gcd, a[i]);
  if (gcd == 1) {
    cout << 0 << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
