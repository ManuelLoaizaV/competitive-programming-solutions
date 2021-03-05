//https://open.kattis.com/contests/uryqeu/problems/typo
#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long B[2] = {29LL, 31LL};
const Long MOD = 1e9 + 7;

typedef long long Long;

Long Add(Long a, Long b) {
  return (a + b) % MOD;
}

Long Sub(Long a, Long b) {
  return (a - b + MOD) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

Long P[N + 5][2];

struct Hash {
  vector<vector<Long>> h;
  void Build(const string& s) {
    int n = s.size();
    h = vector<vector<Long>>(n, vector<Long>(2));
    h[0][0] = h[0][1] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        h[i][j] = Add(Mul(h[i - 1][j], B[j]), s[i] - 'a' + 1);
      }
    }
  }
  Pair Query(int l, int r) {
    vector<Long> ans(2);
    for (int j = 0; j < 2; j++) {
      if (l == 0) {
        ans[j] = h[r][j];
      } else {
        ans[j] = Sub(h[r][j], Mul(h[l - 1][j], P[r - l + 1][j]));
      }
    }
    return {ans[0], ans[1]};
  }
} h;

void Precalculate(int n) {
  P[0][0] = P[0][1] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      P[i][j] = Mul(P[i - 1][j], B[j]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Precalculate(N + 2);
  int n;
  cin >> n;
  vector<Hash> h(n);
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) h[i].Build(s[i]);
  set<Pair> uni;
  for (int i = 0; i < n; i++) uni.insert(h[i].Query(0, (int) s[i].size() - 1));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int len = s[i].size();
    if (len == 1) continue;
    for (int j = 0; j < len ; j++) {
      if (j == 0) {
        Pair current = h[i].Query(1, len - 1);
        if (uni.count(current) > 0) {
          cout << s[i] << '\n';
          cnt++;
          break;
        }
      } else if (j == len - 1) {
        Pair current = h[i].Query(0, len - 2);
        if (uni.count(current) > 0) {
          cout << s[i] << '\n';
          cnt++;
          break;
        }
      } else {
        Pair left = h[i].Query(0, j - 1);
        Pair right = h[i].Query(j + 1, len - 1);
        left.first = Add(Mul(left.first, P[len - 1 - j][0]), right.first);
        left.second = Add(Mul(left.second, P[len - 1 - j][1]), right.second);
        if (uni.count(left) > 0) {
          cout << s[i] << '\n';
          cnt++;
          break;
        }
      }
    }
  }
  if (cnt == 0) {
    cout << "NO TYPOS" << '\n';
  }
  return 0;
}