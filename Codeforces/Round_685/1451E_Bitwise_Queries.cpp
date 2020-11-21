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

void Print(const vector<int>& ans, int n) {
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<int> ans(n + 1, 0);
  vector<vector<int>> who(n);
  who[0].push_back(1);
  for (int i = 2; i <= n; i++) {
    cout << "XOR " << 1 << " " << i << endl;
    int val;
    cin >> val;
    who[val].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    if (who[i].size() > 1) {
      cout << "AND " << who[i][0] << " " << who[i][1] << endl;
      int and_val;
      cin >> and_val;
      ans[1] = i ^ and_val;
      for (int xor_val = 0; xor_val < n; xor_val++) {
        for (int pos : who[xor_val]) {
          if (pos != 1) ans[pos] = xor_val ^ ans[1];
        }
      }
      Print(ans, n);
      return;
    }
  }

  cout << "AND 1 " << who[1][0] << endl;
  int prefix;
  cin >> prefix;

  cout << "AND " << who[1][0] << " " << who[3][0] << endl;
  int aux;
  cin >> aux;
  ans[1] = prefix;
  if (!(aux & 1)) ans[1] |= 1;
  for (int xor_val = 1; xor_val < n; xor_val++) {
    ans[who[xor_val][0]] = xor_val ^ ans[1];
  }
  Print(ans, n);
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
