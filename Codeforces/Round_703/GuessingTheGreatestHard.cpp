//https://codeforces.com/contest/1486/problem/C2
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

Long Query(Long l, Long r) {
  cout << "? " << l << " " << r << endl;
  Long response;
  cin >> response;
  return response;
}

bool Check(Long center, Long len, Long n) {
  Long l = max(1LL, center - len);
  Long r = min(n, center + len);
  return Query(l, r) == center;
}

void Finish(Long center, Long len, Long n) {
  Long l = max(1LL, center - len);
  Long r = min(n, center + len);
  Long answer;
  if (l == center) {
    answer = r;
  } else if (r == center) {
    answer = l;
  } else {
    if (Query(l, center) == center) {
      answer = l;
    } else {
      answer = r;
    }
  }
  cout << "! " << answer << endl;
  return;
}

void Solve(void) {
  Long n;
  cin >> n;
  Long second_maximum = Query(1, n);
  Long l = 1;
  Long r = max(n - second_maximum, second_maximum - 1);
  if (Check(second_maximum, l, n)) {
    Finish(second_maximum, l, n);
    return;
  }
  while (r - l > 1) {
    Long m = (l + r) / 2;
    if (Check(second_maximum, m, n)) {
      r = m;
    } else {
      l = m;
    }
  }
  Finish(second_maximum, r, n);
}

int main(void) {
  //FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

