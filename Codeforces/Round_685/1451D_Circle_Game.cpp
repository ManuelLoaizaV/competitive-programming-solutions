//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;
#define all(v) (v).begin(),(v).end()

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

bool IsInside(Pair p, Long r) {
  Long dx = p.first;
  Long dy = p.second;
  return (dx * dx + dy * dy <= r * r);
}

bool IsValid(Pair p, Long r) {
  return (p.first >= 0 && p.second >= 0 && IsInside(p, r));
}

void Solve(void) {
  Long d, k;
  cin >> d >> k;
  Long x = 0;
  vector<Pair> out;
  while (x <= d) {
    Pair candidate = {x, 0};
    Long l = 0;
    Long r = d / k + 5;
    while (r - l > 1) {
      Long m = (l + r) / 2;
      candidate.second = m * k;
      if (IsInside(candidate, d)) {
        l = m;
      } else {
        r = m;
      }
    }
    candidate.second = r * k;
    Pair left_prev, below_prev;
    left_prev = below_prev = candidate;
    left_prev.first -= k;
    below_prev.second -= k;
    if (IsValid(left_prev, d) && IsValid(below_prev, d))
      out.push_back(candidate);
    x += k;
  }
  Pair origin = {0, 0};
  for (Pair p : out) {
    Long cnt = min(p.first, p.second) / k;
    p.first -= cnt * k;
    p.second -= cnt * k;
    if (p == origin) {
      cout << "Ashish" << '\n';
      return;
    }
  }
  cout << "Utkarsh" << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
