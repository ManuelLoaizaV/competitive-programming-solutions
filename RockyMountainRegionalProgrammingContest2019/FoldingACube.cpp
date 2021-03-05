//https://open.kattis.com/contests/uryqeu/problems/foldingacube
#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

vector<vector<string>> p;

vector<string> Rotate(const vector<string>& s) {
  int n = s.size();
  int m = s[0].size();
  vector<string> ans(m);
  for (int i = 0; i < m; i++) {
    string nxt = "";
    for (int j = 0; j < n; j++) {
      nxt += '*';
    }
    ans[i] = nxt;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[m - 1 - j][i] = s[i][j];
    }
  }
  return ans;
}

void AddRotations(vector<string> s) {
  p.push_back(s);
  for (int i = 0; i < 3; i++) {
    s = Rotate(s);
    p.push_back(s);
  }
}

void Solve(void) {
  vector<string> s;
  // Diametro 4
  s = vector<string> (3, "####");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        s[0][k] = s[2][k] = '*';
      }
      s[0][i] = '#';
      s[2][j] = '#';
      AddRotations(s);
    }
  }
  // Diametro 3
  s[0] = "##**";
  s[1] = "*###";
  s[2] = "*#**";
  AddRotations(s);
  s[0] = "*#**";
  s[1] = "*###";
  s[2] = "##**";
  AddRotations(s);
  s[0] = "**#*";
  s[1] = "*###";
  s[2] = "##**";
  AddRotations(s);
  s[0] = "***#";
  s[1] = "*###";
  s[2] = "##**";
  AddRotations(s);
  s[0] = "#***";
  s[1] = "###*";
  s[2] = "**##";
  AddRotations(s);
  s[0] = "*#**";
  s[1] = "###*";
  s[2] = "**##";
  AddRotations(s);
  // Diametro 2
  s[0] = "**##";
  s[1] = "*##*";
  s[2] = "##**";
  AddRotations(s);
  s[0] = "##**";
  s[1] = "*##*";
  s[2] = "**##";
  AddRotations(s);
  s = vector<string> (2, "*****");
  s[0] = "**###";
  s[1] = "###**";
  AddRotations(s);
  s[0] = "###**";
  s[1] = "**###";
  AddRotations(s);
  // Leo la vaina
  vector<string> t(6);
  for (int i = 0; i < 6; i++) cin >> t[i];
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (t[i][j] == '.') t[i][j] = '*';
    }
  }
  for (int i = 0; i < (int) p.size(); i++) {
    int n = p[i].size();
    int m = p[i][0].size();
    for (int j = 0; j < 6 - n + 1; j++) {
      for (int k = 0; k < 6 - m + 1; k++) {
        bool ok = true;
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < m; y++) {
            if (p[i][x][y] == t[j + x][k + y]) continue;
            ok = false;
            break;
          }
          if (!ok) break;
        }
        if (ok) {
          cout << "can fold" << '\n';
          return;
        }
      }
    }
  }

  cout << "cannot fold" << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

