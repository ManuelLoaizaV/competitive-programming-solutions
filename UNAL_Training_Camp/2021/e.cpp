//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  Long n, r;
  cin >> n >> r;
  vector<Long> chests(2 * n + 1, 0);
  Long score = 0;
  for (int i = 0; i < r - 1; i++) {
    Long x, y, cx, cy;
    cin >> x >> y >> cx >> cy;
    chests[x] = cx;
    chests[y] = cy;
    if (cx == cy) score = max(score, cx);
  }
  vector<Long> cnt(n + 1, 0);
  for (int i = 1; i <= 2 * n; i++) cnt[chests[i]]++;
  vector<Long> zero, one, both;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      zero.push_back(i);
    } else if (cnt[i] == 1) {
      one.push_back(i);
    } else {
      both.push_back(i);
    }
  }
  Double answer = score;
  Long rem = 2 * zero.size() + one.size();
  if (zero.size() > 0) {
    Long mx = zero.end()[-1];
    if (mx > score) {
      Long pairs = rem * (rem - 1) / 2;
      Long len = 0;
      Long sum = 0;
      for (int i = 0; i < zero.size(); i++) {
        if (zero[i] > score) {
          sum += zero[i];
          len++;
        }
      }
      Double current = (Double) sum / pairs + (Double) (pairs - len) / pairs * score;
      answer = max(answer, current);
    }
  }
  if (one.size() > 0) {
    Long mx = one.end()[-1];
    if (mx > score) {
      Double current = (Double) mx / rem + (Double) (rem - 1) * score / rem;
      answer = max(answer, current);
    }
  }
  if (both.size() > 0) {
    Long mx = both.end()[-1];
    if (mx > score) {
      answer = max(answer, (Double) mx);
    }
  }
  cout << fixed << setprecision(10) << answer << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

