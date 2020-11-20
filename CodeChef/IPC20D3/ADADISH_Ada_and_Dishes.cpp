#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

void Solve(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  stack<int> cur;
  for (int i = 0; i < n; i++) cur.push(a[i]);
  int ans = 0;
  while (!cur.empty()) {
    if (cur.size() == 1) {
      ans += cur.top();
      cur.pop();
    } else {
      int x = cur.top();
      cur.pop();
      int y = cur.top();
      cur.pop();
      if (x == y) {
        ans += x;
      } else {
        ans += min(x, y);
        cur.push(max(x, y) - min(x, y));
      }
    }
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
