// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 6e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

int nxt[N][26];
int anc[N];  // Quien es su padre
pair<int, int> mx[N]; // {pos, cnt}
int cnt[N];  // Cuantas veces
int nodes = 1;

void add(string& s, int cur_pos) {
  int from = 0;
  for (char c : s) {
    int to = c - 'a';
    if (nxt[from][to] == 0) {
      nxt[from][to] = nodes++;
    }
    anc[nxt[from][to]] = from;
    from = nxt[from][to];
  }
  cnt[from]++;
  int p = from;
  int cur_cnt = cnt[from];
  while (p != 0) {
    if (cur_cnt > mx[p].second) {
      mx[p].second = cur_cnt;
      mx[p].first = cur_pos;
    }
    p = anc[p];
  }
}

bool find(string& s) {
  int from = 0;
  for (char c : s) {
    int to = c - 'a';
    if (nxt[from][to] == 0) return false;
    from = nxt[from][to];
  }
  return true;
}

pair<int, int> query(string& s) {
  int from = 0;
  for (char c : s) {
    int to = c - 'a';
    from = nxt[from][to];
  }
  return mx[from];
}

void Solve(void) {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n);
  for (int i = 0; i < n; i++) add(s[i], i);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    if (!find(t)) {
      cout << -1 << '\n';
    } else {
      pair<int, int> ans = query(t);
      cout << s[ans.first] << " " << ans.second << '\n';
    }
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
