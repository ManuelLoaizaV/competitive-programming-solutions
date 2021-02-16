//https://codeforces.com/contest/1490/problem/E
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

bool Check(const vector<Pair>& a, int id, int n) {
  Long sum = a[id].first;
  for (int i = n - 1; i > 0; i--) {
    if (i == id) continue;
    if (sum >= a[i].first) {
      sum += a[i].first;
    } else {
      return false;
    }
  }
  if (sum >= a[0].first) return true;
  return false;
}

void Solve(void) {
  Long n;
  cin >> n;
  vector<Pair> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  if (n == 1) {
    cout << 1 << '\n';
    cout << 1 << '\n';
    return;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int l = 0;
  int r = n - 1;
  if (Check(a, r, n)) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (Check(a, m, n)) {
      l = m;
    } else {
      r = m;
    }
  }
  vector<int> pos;
  for (int i = 0; i <= l; i++) {
    pos.push_back(a[i].second + 1);
  }
  sort(pos.begin(), pos.end());
  cout << pos.size() << '\n';
  for (int x : pos) cout << x << " ";
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

