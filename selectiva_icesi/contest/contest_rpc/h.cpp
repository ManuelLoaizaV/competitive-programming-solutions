// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

string KMP(string& p) {
  string t = p;
  reverse(t.begin(), t.end());
  int n = p.size();
  int m = t.size();
  vector<int> pi(n + 1 + m);
  string s = p + '#' + t;
  int len = s.size();
  for (int i = 1; i < len; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
    if (pi[i] == n) {
      int pos = i - (n + 1) - (n - 1) + 1;
    }
  }
  pair<int, int> res = {-INF, 0};  // {pos, len}
  for (int i = n + 1; i < len; i++) {
    if (pi[i] > res.second) {
      res.second = pi[i];
      res.first = i;
    }
  }
  string ans = "";
  int from = res.first;
  int to = res.first - res.second + 1;
  for (int i = from; i >= to; i--) ans += s[i];
  return ans;
}

void Solve(void) {
  string s;
  cin >> s;
  string ans = KMP(s);
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
