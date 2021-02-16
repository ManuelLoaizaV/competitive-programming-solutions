//https://codeforces.com/contest/1490/problem/A
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e3;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N];
vector<int> a(N);
int d[N];
int n;

void Clear(void) {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    d[i] = 0;
  }
}

void DFS(int u, int h) {
  d[u] = h;
  for (int v : adj[u]) DFS(v, h + 1);
}

void Create(int l, int r) {
  if (l == r) return;
  int max_pos = l;
  for (int i = l; i <= r; i++) {
    if (a[i] > a[max_pos]) {
      max_pos = i;
    }
  }
  if (max_pos > l) {
    int max_left = l;
    for (int i = l; i < max_pos; i++) {
      if (a[i] > a[max_left]) {
        max_left = i;
      }
    }
    adj[a[max_pos]].push_back(a[max_left]);
    Create(l, max_pos - 1);
  }
  if (max_pos < r) {
    int max_right = max_pos + 1;
    for (int i = max_pos + 1; i <= r; i++) {
      if (a[i] > a[max_right]) {
        max_right = i;
      }
    }
    adj[a[max_pos]].push_back(a[max_right]);
    Create(max_pos + 1, r);
  }
}

void Solve(void) {
  cin >> n;
  Clear();
  for (int i = 0; i < n; i++) cin >> a[i];
  Create(0, n - 1);
  DFS(n, 0);
  for (int i = 0; i < n; i++) cout << d[a[i]] << " ";
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

