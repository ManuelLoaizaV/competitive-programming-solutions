// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
const Long INF = 1e9;

int main() {
  FAST_IO;
  Long n;
  cin >> n;
  vector<vector<Long>> dp;
  dp.resize(n, vector<Long>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> dp[i][j];
  
  vector<Long> orden;
  for (int i = 0; i < n; i++) {
    Long x;
    cin >> x;
    orden.push_back(x - 1);
  }
  stack<Long> ans;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Long mid = orden[n - 1 - k];
        dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid][j]);
      }
    }
    Long sum = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        Long u = orden[n - 1 - i];
        Long v = orden[n - 1 - j];
        if (u != v) sum += dp[u][v];
      }
    }
    ans.push(sum);
  }
  while (ans.size()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << '\n';
  return 0;
}
