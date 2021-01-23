//https://atcoder.jp/contests/abc189/tasks/abc189_e
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

typedef vector<vector<Long>> Matrix;
const Long MOD = 1e9 + 7;

Long Add(Long a, Long b) {
  return (a + b);
}
Long Sub(Long a, Long b) {
  return (a - b);
}
Long Mul(Long a, Long b) {
  return (a * b);
}
Matrix GetMatrix(int n, int m, bool is_identity) {
  Matrix matrix = Matrix(n, vector<Long> (m, 0));
  if (is_identity) {
    assert(n == m);
    for (int i = 0; i < n; i++) matrix[i][i] = 1LL;
  }
  return matrix;
}
Matrix operator + (const Matrix& a, const Matrix& b) {
  Long n = a.size();
  Long m = a[0].size();
  assert(a.size() == b.size());
  assert(a[0].size() == b[0].size());
  Matrix c = GetMatrix(n, m, false);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      c[i][j] = Add(a[i][j], b[i][j]);
  return c;
}
Matrix operator * (const Matrix& a, const Matrix& b) {
  assert(a[0].size() == b.size());
  int n = a.size();
  int m = a[0].size();
  int p = b[0].size();
  Matrix c = GetMatrix(n, p, false);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < p; j++)
      for (int k = 0; k < m; k++)
        c[i][j] = Add(c[i][j], Mul(a[i][k], b[k][j]));
  return c;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<Matrix> v(n);
  for (int i= 0; i < n; i++) {
    v[i] = GetMatrix(3, 1, false);
    cin >> v[i][0][0] >> v[i][1][0];
    v[i][2][0] = 1;
  }
  int m;
  cin >> m;
  vector<Matrix> composition, lt;
  for (int i = 0; i < 5; i++) lt.push_back(GetMatrix(3, 3, false));
  // Precalculo cada transformacion lineal
  lt[0] = GetMatrix(3, 3, true);

  lt[1][0][1] = 1;
  lt[1][1][0] = -1;
  lt[1][2][2] = 1;

  lt[2][0][1] = -1;
  lt[2][1][0] = 1;
  lt[2][2][2] = 1;

  lt[3][0][0] = -1;
  lt[3][1][1] = 1;
  lt[3][2][2] = 1;

  lt[4][0][0] = 1;
  lt[4][1][1] = -1;
  lt[4][2][2] = 1;
  // Caso base
  composition.push_back(lt[0]);

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 3) {
      Long p;
      cin >> p;
      lt[3][0][2] = 2 * p;
    }
    if (t == 4) {
      Long p;
      cin >> p;
      lt[4][1][2] = 2 * p;
    }
    debug(i, lt[t], composition[i]);
    Matrix multiplication = lt[t] * composition[i];
    debug(multiplication);
    composition.push_back(multiplication);
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    Matrix result = composition[a] * v[b - 1];
    cout << result[0][0] << " " << result[1][0] << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

