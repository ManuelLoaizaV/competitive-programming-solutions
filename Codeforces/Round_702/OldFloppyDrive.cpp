//https://codeforces.com/contest/1490/problem/G
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 2e5;
const Long INF = 1e18;
const Double EPS = 1e-9;
const int LG = 32 - __builtin_clz(N);

struct SparseTable {
  Long st[N][LG];
  Long f(Long x) { return x; }
  Long f(Long x, Long y) { return min(x, y); }
  void Build(const vector<Pair>& a, int n) {
    for (int i = 0; i < n; i++) st[i][0] = f(a[i].second);
    for (int j = 1; j < LG; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
  // O(1). Solo funciona con operadores idempotentes.
  Long Query(int l, int r) {
    int range = r - l + 1;
    int lg = 31 - __builtin_clz(range);
    return f(st[l][lg], st[r - (1 << lg) + 1][lg]);
  }
} st;


void Solve(void) {
  int n, m;
  cin >> n >> m;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<Long> acc(n);
  acc[0] = a[0];
  for (int i = 1; i < n; i++) acc[i] = acc[i - 1] + a[i];
  Long mx = -INF;
  Long mn = INF;
  for (int i = 0; i < n; i++) {
    mx = max(mx, acc[i]);
    mn = min(mn, acc[i]);
  }
  map<Long, Long> first_time;
  for (int i = 0; i < n; i++) {
    if (first_time.count(acc[i]) == 0) first_time[acc[i]] = i;
  }
  vector<Pair> sorted_times;
  for (auto it : first_time) sorted_times.push_back({it.first, it.second});
  sort(sorted_times.begin(), sorted_times.end());
  st.Build(sorted_times, sorted_times.size());
  while (m--) {
    Long x;
    cin >> x;
    if (mx < x && acc[n - 1] <= 0) {
      cout << -1 << " ";
      continue;
    }
    Long blocks = 0;
    if (x > mx) {
      blocks = (x - mx + acc[n - 1] - 1) / acc[n - 1];
    }
    Long ans = blocks * n;
    Long current = blocks * acc[n - 1];
    Long needed = x - current;
    Pair nxt = {needed, -INF};
    int pos = lower_bound(sorted_times.begin(), sorted_times.end(), nxt) - sorted_times.begin();
    Long mn = st.Query(pos, sorted_times.size() - 1);
    ans += mn;
    cout << ans << " ";
  }
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

