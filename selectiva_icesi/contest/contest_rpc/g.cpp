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

vector<int> KMP(string& p, string& t) {
  int n = p.size();
  int m = t.size();
  vector<int> pi(n + 1 + m);
  vector<int> ans;
  string s = p + '#' + t;
  int len = s.size();
  for (int i = 1; i < len; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
    if (pi[i] == n) {
      int pos = i - (n + 1) - (n - 1) + 1;
      ans.push_back(pos);
    }
  }
  return ans;
}

void Solve(void) {
  string a, b;
  cin >> a >> b;
  vector<int> ans = KMP(b, a);
  int len = ans.size();
  if (len == 0) {
    cout << "Not Found" << '\n';
  } else {
    cout << len << '\n';
    for (int pos : ans) cout << pos << " ";
    cout << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (i > 0) cout << '\n';
    Solve();
  }
  return 0;
}
