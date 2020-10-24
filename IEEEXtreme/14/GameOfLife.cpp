#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 25;
const Long INF = 1e18;
const Double EPS = 1e-9;

string board[N], temp[N];
string rules[2];

void Print(int n) {
  for (int i = 0; i < n; i++) {
    cout << board[i] << '\n';
  }
}

char Update(int x, int y, int n) {
  vector<pair<int, int>> pos;
  pos.push_back({(x - 1 + n) % n, y});
  pos.push_back({x, (y - 1 + n) % n});
  pos.push_back({(x + 1) % n, y});
  pos.push_back({x, (y + 1) % n});
  int cnt[2];
  for (int i = 0; i < 2; i++) cnt[i] = 0;
  for (int i = 0; i < 4; i++) {
    int _x = pos[i].first;
    int _y = pos[i].second;
    cnt[board[_x][_y] - '0']++;
  }

  if (board[x][y] == '0') {
    bool live = false;
    for (int i = 0; i < 5; i++) {
      if (rules[0][i] == '1' && cnt[1] == i) {
        live = true;
        break;
      }
    }
    if (live) {
      return '1';
    } else {
      return '0';
    }
  } else {
    bool live = false;
    for (int i = 0; i < 5; i++) {
      if (rules[1][i] == '1' && cnt[1] == i) {
        live = true;
        break;
      }
    }
    if (live) {
      return '1';
    } else {
      return '0';
    }
  }
}

int main(void) {
  FAST_IO;
  string line;
  cin >> line;
  rules[0] = line.substr(0, 5);
  rules[1] = line.substr(6, 5);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    temp[i] = board[i];
  }
  while (m--) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp[i][j] = Update(i, j, n);
      }
    }
    for (int i = 0; i < n; i++) board[i] = temp[i];
  }
  Print(n);
  return 0;
}
