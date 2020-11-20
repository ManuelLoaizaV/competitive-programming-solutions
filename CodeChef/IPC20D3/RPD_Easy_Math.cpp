#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

int Sum(int n) {
  if (n < 10) return n;
  return (n % 10 + Sum(n / 10));
}

void Solve(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      ans = max(ans, Sum(a[i] * a[j]));
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
