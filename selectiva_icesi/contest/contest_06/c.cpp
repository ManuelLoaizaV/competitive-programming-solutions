// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int INF = INT_MAX;
const int N = 10;
const int M = 100;
int dp[N][M], grid[N][M];
bool done[N][M];
int n, m;

// DP(i, j): minima suma comenzando en grid[i][j]
int DP(int i, int j) {
  if (j == m) return 0;
  if (done[i][j]) return dp[i][j];
  dp[i][j] = INF;
  for (int delta = -1; delta <= 1; delta++) {
    int next = (i + delta + n) % n;
    dp[i][j] = min(dp[i][j], DP(next, j + 1));
  }
  dp[i][j] += grid[i][j];
  done[i][j] = true;
  return dp[i][j];
}

void Reconstruct(int i, int j) {
  if (j == m) return;
  if (j > 0) cout << " ";
  cout << i + 1 ;
  vector<int> moves;
  for (int delta = -1; delta <= 1; delta++) {
    int next = (i + delta + n) % n;
    moves.push_back(next);
  }
  sort(moves.begin(), moves.end());
  for (int move : moves) {
    if (grid[i][j] + DP(move, j + 1) == DP(i, j)) {
      Reconstruct(move, j + 1);
      return;
    }
  }
}

int main() {
  FAST_IO;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        done[i][j] = false;
      }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
      ans = min(ans, DP(i, 0));
    }
    for (int i = 0; i < n; i++) {
      if (DP(i, 0) == ans) {
        Reconstruct(i, 0);
        cout << '\n';
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
