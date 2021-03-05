//https://open.kattis.com/contests/uryqeu/problems/fantasydraft
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

void Solve(void) {
  int n, k;
  cin >> n >> k;
  vector<vector<string>> pref(n);
  for (int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      string  who;
      cin >> who;
      pref[i].push_back(who);
    }
  }
  int p;
  cin >> p;
  map<string, int> m;
  vector<string> players(p);
  for (int i = 0; i < p; i++) {
    cin >> players[i];
    m[players[i]] = i;
  }
  vector<vector<int>> pref_id(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < pref[i].size(); j++) {
      pref_id[i].push_back(m[pref[i][j]]);
    }
  }
  pref.clear();
  vector<int> ptr(n, 0);
  vector<vector<int>> ans(n);
  vector<bool> used(p, false);
  int cur = 0;
  for (int it = 0; it < k; it++) {
    for (int i = 0; i < n; i++) {
      while (ptr[i] < (int) pref_id[i].size() && used[pref_id[i][ptr[i]]]) ptr[i]++;
      if (ptr[i] == (int) pref_id[i].size()) {
        while (cur < p && used[cur]) cur++;
        ans[i].push_back(cur);
        used[cur] = true;
      } else {
        ans[i].push_back(pref_id[i][ptr[i]]);
        used[pref_id[i][ptr[i]]] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) ans[i].size(); j++) {
      if (j > 0) cout << " ";
      cout << players[ans[i][j]];
    }
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}