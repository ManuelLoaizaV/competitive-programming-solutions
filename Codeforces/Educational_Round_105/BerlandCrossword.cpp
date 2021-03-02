//https://codeforces.com/contest/1494/problem/B
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

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt[4];
    for (int i = 0; i < 4; i++) cin >> cnt[i];
    bool ok = false;
    for (int i = 0; i < 16; i++) {
      vector<int> freq(4, 0);
      for (int j = 0; j < 4; j++) {
        if (GetBit((Long) i, (Long) j) == 1) {
          freq[j]++;
          freq[(j - 1 + 4) % 4]++;
        }
      }
      bool good = true;
      for (int j = 0; j < 4; j++) {
        if (freq[j] > cnt[j]) {
          good = false;
          break;
        }
        int need = cnt[j] - freq[j];
        if (need > n - 2) {
          good = false;
          break;
        }
      }
      if (good) {
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