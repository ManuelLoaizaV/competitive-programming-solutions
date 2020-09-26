// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;

const Long INF = 1e9;
const Long N = 26;

int main() {
  FAST_IO;
  string s, t;
  cin >> s >> t;
  Long m;
  cin >> m;
  Long dp[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dp[i][j] = INF;
  for (int i = 0; i < N; i++) dp[i][i] = 0LL;

  while (m--) {
    char u, v;
    Long w;
    cin >> u >> v >> w;
    dp[u - 'a'][v - 'a'] = min(dp[u - 'a'][v -'a'], w);
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  if (s.size() != t.size()) {
    cout << -1 << '\n';
    return 0;
  }
  string ans = "";
  Long cost = 0;
  int sz = s.size();
  for (int i = 0; i < sz; i++) {
    Long mn = INF;
    char who;
    for (int k = 0; k < N; k++) {
      Long temp = dp[s[i] - 'a'][k] + dp[t[i] - 'a'][k];
      if (temp < mn) {
        mn = temp;
        who = 'a' + k;
      }
    }
    if (mn == INF) {
      cout << -1 << '\n';
      return 0;
    }
    ans += who;
    cost += mn;
  }
  cout << cost << '\n';
  cout << ans << '\n';
  return 0;
}
