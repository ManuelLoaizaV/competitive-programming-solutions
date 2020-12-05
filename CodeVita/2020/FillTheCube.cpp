#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

typedef long long Long;
typedef long double Double;

const int N = 1e2;

bool IsOk(const vector<vector<int>>& dp, int len) {
  int n = dp.size();
  for (int i = 0; i < n - len + 1; i++) {
    for (int j = 0; j < n - len + 1; j++) {
      int u = i + len - 1;
      int v = j + len - 1;
      int cur = dp[u][v];
      if (i > 0) cur -= dp[i - 1][v];
      if (j > 0) cur -= dp[u][j - 1];
      if (i > 0 && j > 0) cur += dp[i - 1][j - 1];
      if (cur == len * len) return true;
    }
  }
  return false;
}

Long Analyze(const vector<vector<char>>& a) {
  int n = a.size();
  vector<int> cnt(n, 0);
  for (int col = 0; col < n; col++) {
    for (int row = 0; row < n; row++) if (a[row][col] == 'C') cnt[col]++;
  }

  vector<vector<bool>> aux(n, vector<bool> (n, false));
  for (int col = 0; col < n; col++) {
    for (int row = 0; row < cnt[col]; row++) {
      aux[n - 1 - row][col] = true;
    }
  }

  vector<vector<int>> dp(n, vector<int> (n, 0));
  if (!aux[0][0]) dp[0][0] = 1;
  for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + (!aux[i][0]);
  for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + (!aux[0][j]);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (!aux[i][j]);
    }
  }

  int l = 1;
  int r = n;
  if (!IsOk(dp, l)) return 0;
  if (IsOk(dp, r)) return r;

  while (r - l > 1) {
    int m = (l + r) / 2;
    if (IsOk(dp, m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void Rotate(vector<vector<char>>& a) {
  int n = a.size();
  int r_len = n / 2;
  int c_len = n / 2;
  if (n & 1) r_len++;
  for (int i = 0; i < r_len; i++) {
    for (int j = 0; j < c_len; j++) {
      char aux = a[i][j];
      a[i][j] = a[n - 1 - j][i];
      a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
      a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
      a[j][n - 1 - i] = aux;
    }
  }
}

int main(void) {
  FAST_IO;
  Long n;
  cin >> n;
  vector<vector<char>> wall(n, vector<char> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> wall[i][j];
    }
  }
  Long ans = 0;
  for (int t = 0; t < 4; t++) {
    Rotate(wall);
    Long cnt = Analyze(wall);
    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}
