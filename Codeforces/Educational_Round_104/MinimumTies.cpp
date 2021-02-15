//https://codeforces.com/contest/1487/problem/C
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

Long GetBit(Long mask, Long bit) { return (mask >> bit) & 1LL; }
void TurnOn(Long& mask, Long bit) { mask = mask | (1LL << bit); }
void TurnOff(Long& mask, Long bit) { mask = mask & (~(1 << bit)); }

void Solve(void) {
  Long n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; i++) {
      int cur = 1;
      for (int j = i + 1; j < n; j++) {
        if (cur & 1) {
          cout << 1 << " ";
        } else {
          cout << -1 << " ";
        }
        cur++;
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        int cur = 0;
        for (int j = i + 1; j < n; j++) {
          if (cur & 1) {
            cout << 1 << " ";
          } else {
            cout << -1 << " ";
          }
          cur++;
        }
      } else {
        int cur = 1;
        for (int j = i + 1; j < n; j++) {
          if (j == i + 1) {
            cout << 0 << " ";
          } else {
            if (cur & 1) {
              cout << 1 << " ";
            } else {
              cout << -1 << " ";
            }
            cur++;
          }
        }
      }
    }
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

