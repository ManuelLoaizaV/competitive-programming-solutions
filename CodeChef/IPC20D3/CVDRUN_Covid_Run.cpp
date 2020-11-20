#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

void Solve(void) {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  vector<bool> is_done(n, false);
  int cur = x;
  while (!is_done[cur]) {
    is_done[cur] = true;
    cur = (cur + k) % n;
  }
  if (is_done[y]) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
