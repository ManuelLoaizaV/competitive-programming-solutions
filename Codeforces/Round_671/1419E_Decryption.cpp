// Gracias, Rodolfo
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define For(i,a,b) for (Long i = a; i < b; i++)
#define roF(i,a,b) for (Long i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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

// Variables globales que utilizare para la respuesta y para evitar usar
vector<Long> answer;
deque<Pair> fact;
Long ban[2];

void Print(vector<Long>& a) {
  Long sz = a.size();
  For(i, 0, sz) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << '\n';
}

void Backtracking(Long pos, Long n, Long mul) {
  if (pos == n) {
    if (mul != ban[0] && mul != ban[1] && mul != 1) answer.pb(mul);
    return;
  } else {
    Long p = fact[pos].first;
    Long e = fact[pos].second;
    Long pot;
    if (pos == 0) {
      pot = p;
      e--;
    } else {
      pot = 1LL;
    }
    For(i, 0, e + 1) {
      Backtracking(pos + 1, n, mul * pot);
      pot *= p;
    }
  }
}

void Solve() {
  answer.clear();  // Limpio la respuesta siempre
  fact.clear();
  Long n;
  cin >> n;
  // Decompongo el n[umero
  Long copy = n;
  for (Long i = 2LL; i * i <= n; i++) {
    if (copy % i == 0) {
      Long e = 0;
      while (copy % i == 0) {
        copy /= i;
        e++;
      }
      fact.pb({i, e});
    }
  }
  if (copy > 1) fact.pb({copy, 1});
  // Caso 1: n = p^k
  if (fact.size() == 1) {
    Long p = fact[0].first;
    For(i, 0, fact[0].second) {
      answer.pb(fact[0].first);
      fact[0].first *= p;
    }
    Print(answer);
    cout << 0 << '\n';
    return;
  }
  // Caso 2 : n = p * q
  if (fact.size() == 2 && fact[0].second == 1 && fact[1].second == 1) {
    answer.pb(fact[0].first);
    answer.pb(fact[1].first);
    answer.pb(n);
    Print(answer);
    cout << 1 << '\n';
    return;
  }
  // Caso 3: n = p1^m1 * p2^m2
  if (fact.size() == 2) {
    ban[0] = ban[1] = fact[0].first * fact[1].first;
    Backtracking(0, 2, 1LL);
    fact.pop_front();
    Backtracking(0, 1, 1LL);
    answer.pb(ban[0]);
    Print(answer);
    cout << 0 << '\n';
    return;
  }
  // n = p1^m1 p2^m2 ... pk^mk
  int k = fact.size();
  ban[0] = fact[0].first * fact[k - 1].first;
  For(i, 0, k - 1) {
    ban[1] = fact[0].first * fact[1].first;
    Backtracking(0, fact.size(), 1LL);   
    answer.pb(ban[1]);
    fact.pop_front();
  }
  // A~nado el caso borde
  Backtracking(0, 1, 1LL);
  answer.pb(ban[0]);
  Print(answer);
  cout << 0 << '\n';
}

int main() {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
