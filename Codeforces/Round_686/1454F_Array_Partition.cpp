//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<int, int> Pair;

const int N = 2e5;
const int LG = 19;
const Long INF = 1e18;
const Double EPS = 1e-9;

struct SparseTable {
  Pair st[N][LG + 1];

  Pair f(const Pair& a, const Pair& b) {
    return {min(a.first, b.first), max(a.second, b.second)};
  }

  void Build(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) st[i][0] = {a[i], a[i]};
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int Min(int l, int r) {
    int t = r - l + 1;
    int lg = 31 - __builtin_clz(t);
    return f(st[l][lg], st[r - (1 << lg) + 1][lg]).first;
  }

  int Max(int l, int r) {
    int t = r - l + 1;
    int lg = 31 - __builtin_clz(t);
    return f(st[l][lg], st[r - (1 << lg) + 1][lg]).second;
  }
} st;

int LeftMin(int tl, int tr, int target) {
  int l = tl;
  int r = tr;
  if (st.Min(tl, r) > target) return -1;
  if (st.Min(tl, l) <= target) {
    if (st.Min(tl, l) == target) return l;
    return -1;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (st.Min(tl, m) <= target) {
      r = m;
    } else {
      l = m;
    }
  }
  if (st.Min(tl, r) == target) return r;
  return -1;
}

int RightMin(int tl, int tr, int target) {
  int l = tl;
  int r = tr;
  if (st.Min(tl, l) < target) return -1;
  if (st.Min(tl, r) >= target) {
    if (st.Min(tl, r) == target) return r;
    return -1;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (st.Min(tl, m) >= target) {
      l = m;
    } else {
      r = m;
    }
  }
  if (st.Min(tl, l) == target) return l;
  return -1;
}

int LeftMax(int tl, int tr, int target) {
  int l = tl;
  int r = tr;
  if (st.Max(r, tr) > target) return -1;
  if (st.Max(l, tr) <= target) {
    if (st.Max(l, tr) == target) return l;
    return -1;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (st.Max(m, tr) <= target) {
      r = m;
    } else {
      l = m;
    }
  }
  if (st.Max(r, tr) == target) return r;
  return -1;
}

int RightMax(int tl, int tr, int target) {
  int l = tl;
  int r = tr;
  if (st.Max(l, tr) < target) return -1;
  if (st.Max(r, tr) >= target) {
    if (st.Max(r, tr) == target) return r;
    return -1;
  }
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (st.Max(m, tr) >= target) {
      l = m;
    } else {
      r = m;
    }
  }
  if (st.Max(l, tr) == target) return l;
  return -1;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  st.Build(a, n);
  int mx = -1;
  for (int i = 0; i < n - 2; i++) {
    mx = max(mx, a[i]);
    Pair mid = {LeftMin(i + 1, n - 2, mx), RightMin(i + 1, n - 2, mx)};
    //debug(mid);
    if (mid.first == -1) continue;
    Pair end = {LeftMax(mid.first + 1, n - 1, mx), RightMax(mid.first + 1, n - 1, mx)};
    //debug(end);
    if (end.first == -1) continue;
    if (end.first <= mid.second) {
      int x = i + 1;
      int y = end.first - 1 - i;
      int z = n - x - y;
      cout << "YES" << '\n';
      cout << x << " " << y << " " << z << '\n';
      return;
    }
    if (end.first == (mid.second + 1)) {
      int x = i + 1;
      int y = mid.second - i;
      int z = n - x - y;
      cout << "YES" << '\n';
      cout << x << " " << y << " " << z << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
