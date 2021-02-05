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

vector<Long> asteriks, pacmen;

bool IsValid(Long len) {
  Long n = pacmen.size();
  Long m = asteriks.size();
  Long current = 0;  // asterisco actual
  for (Long i = 0; i < n; i++) {
    if (asteriks[current] > pacmen[i]) {
      Long next_pos = pacmen[i] + len;
      while (current < m && asteriks[current] <= next_pos) current++;
    } else {
      Long delta = pacmen[i] - asteriks[current];
      if (delta > len) return false;
      Long next_left = asteriks[current] + len - delta;
      Long next_right = pacmen[i] + (len - delta) / 2;
      Long next_pos = max(next_left, next_right);
      while (current < m && asteriks[current] <= next_pos) current++;
    }
    if (current == m) return true;
  }
  return false;
}

void Solve(void) {
  Long n;
  string s;
  cin >> n >> s;
  // Guardo la posicion de los asteriscos y de los pacmans
  for (Long i = 0; i < n; i++) {
    if (s[i] == '*') asteriks.push_back(i);
    if (s[i] == 'P') pacmen.push_back(i);
  }
  Long l = 0;
  Long r = 2 * n;
  while (r - l > 1) {
    Long  m = (l + r) / 2;
    if (IsValid(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

