//https://codeforces.com/contest/1494/problem/A
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

Long GetBit(Long mask, Long bit) {
  return (mask >> bit) & 1LL;
}

bool IsBalanced(const string& s) {
  int bal = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      bal++;
    } else {
      if (bal == 0) return false;
      bal--;
    }
  }
  return bal == 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string t = s;
    int n = s.size();
    bool ok = false;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < n; j++) {
        if (GetBit((Long) i, (Long) s[j] - 'A') == 1) {
          t[j] = '(';
        } else {
          t[j] = ')';
        }
      }
      if (IsBalanced(t)) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}