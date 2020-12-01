//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << endl
#define all(v) (v).begin(),(v).end()
using namespace std;

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
  Long n;
  cin >> n;
  vector<Pair> primes;
  Long aux = n;
  for (Long i = 2; i * i <= n; i++) {
    if (aux % i == 0) {
      Long cnt = 0;
      while (aux % i == 0) {
        aux /= i;
        cnt++;
      }
      primes.push_back({cnt, i});
    }
  }
  if (aux > 1) primes.push_back({1, aux});
  sort(all(primes));
  int len = primes.size();
  Long cnt = primes[len - 1].first;
  Long p = primes[len - 1].second;
  Long mul = 1LL;
  cout << cnt << '\n';
  if (cnt == 1) {
    cout << n << '\n';
    return;
  }
  for (int i = 0; i < cnt - 1; i++) {
    cout << p << " ";
    mul *= p;
  }
  cout << n / mul << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
