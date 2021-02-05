//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define x first
#define y second
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e2 + 5;
const Long INF = 1e18;
const Double EPS = 1e-9;

bool is_used[N][N];
Long dp[N][N];

Long Mex(const vector<Long>& v) {
  Long n = v.size();
  vector<bool> marked(n, false);
  for (Long x : v) if (x < n) marked[x] = true;
  for (Long x = 0; x < n; x++) if (!marked[x]) return x;
  return n;
}

Long Grundy(Pair pos) {
  // Posicion terminal
  if (pos.x == 1 && pos.y == 2 || pos.x == 2 && pos.x == 1) return 0;
  if (is_used[pos.x][pos.y]) return dp[pos.x][pos.y];
  is_used[pos.x][pos.y] = true;
  vector<Pair> moves;
  for (Long u = 1; u <= pos.x; u++) {
    Pair next_pos = {pos.x - u, pos.y};
    if (next_pos.x == 0 || next_pos.x == next_pos.y) continue;
    moves.push_back(next_pos);
  }
  for (Long u = 1; u <= pos.y; u++) {
    Pair next_pos = {pos.x, pos.y - u};
    if (next_pos.y == 0 || next_pos.x == next_pos.y) continue;
    moves.push_back(next_pos);
  }
  for (Long u = 1; u <= min(pos.x, pos.y); u++) {
    Pair next_pos = {pos.x - u, pos.y - u};
    if (next_pos.x == 0 || next_pos.y == 0 || next_pos.x == next_pos.y) continue;
    moves.push_back(next_pos);
  }
  vector<Long> g;
  for (auto next_pos : moves) g.push_back(Grundy(next_pos));
  return dp[pos.x][pos.y] = Mex(g);
}


void Solve(void) {
  Long n;
  cin >> n;
  Long ans = 0;
  for (Long i = 0; i < n; i++) {
    Long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "Y\n";
      return;
    }
    ans ^= Grundy({l, r});
  }
  if (ans == 0) {
    cout << "N\n";
  } else {
    cout << "Y\n";
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


