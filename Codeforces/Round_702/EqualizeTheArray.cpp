//https://codeforces.com/contest/1490/problem/F
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

int Compress(vector<Long>& a) {
  int n = a.size();
  vector<Pair> pairs;
  for (int i = 0; i < n; i++) pairs.push_back({a[i], i});
  sort(pairs.begin(), pairs.end());
  Long nxt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && pairs[i].first != pairs[i - 1].first) nxt++;
    a[pairs[i].second] = nxt;
  }
  return nxt + 1;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sz = Compress(a);
  vector<Long> freq(sz, 0);
  for (int i = 0; i < n; i++) freq[a[i]]++;
  sort(freq.begin(), freq.end());
  vector<Long> acc(sz, 0);
  acc[0] = freq[0];
  for (int i = 1; i < sz; i++) acc[i] = acc[i - 1] + freq[i];
  Long mn = INF;
  for (Long i = 0; i <= n; i++) {
    Long pos = lower_bound(freq.begin(), freq.end(), i) - freq.begin();
    Long tmp = 0;
    if (pos > 0) tmp = acc[pos - 1];
    if (pos < n) {
      tmp += acc[sz - 1] - ((pos > 0) ? acc[pos - 1] : 0);
      tmp -= i * (sz - pos);
    }
    mn = min(mn, tmp);
  }
  cout << mn << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

