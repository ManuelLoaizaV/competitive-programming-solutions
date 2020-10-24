#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

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

vector<Long> KMP(vector<Long>& p, vector<Long>& t) {
  Long n = p.size();
  Long m = t.size();
  vector<Long> pi(n + 1 + m);
  vector<Long> s;
  vector<Long> ans;
  for (int i = 0; i < n; i++) s.push_back(p[i]);
  s.push_back(-2);
  for (int i = 0; i < m; i++) s.push_back(t[i]);
  int len = s.size();
  for (int i = 1; i < len; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
    if (pi[i] == n) {
      Long pos = i - (n + 1) - (n - 1);
      if (pos > 1) ans.push_back(pos);
    }
  }
  return ans;
}

int main(void) {
  FAST_IO;
  Long n, t;
  cin >> n >> t;
  vector<Long> a;
  for (int i = 0; i < n; i++) {
    Long x;
    cin >> x;
    a.push_back(x);
  }
  
  // Contruyo el patron con bordes
  vector<Long> sin_borde, patron;
  patron.push_back(a[0]);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      patron.push_back(-1);
    } else {
      patron.push_back(a[i] - a[i - 1] - 1);
      patron.push_back(-1);
    }
  }
  patron.push_back(t - a[n - 1] - 1);
  
  // Contruyo el sin borde para ser analizado como patron en kmp
  for (int i = 1; i < patron.size() - 1; i++) {
    sin_borde.push_back(patron[i]);
  }
  vector<Long> texto;
  for (int i = 0; i < patron.size() - 1; i++) {
    texto.push_back(patron[i]);
  }
  texto.push_back(patron[patron.size() - 1] + patron[0]);
  for (int i = 1; i < patron.size(); i++) {
    texto.push_back(patron[i]);
  }

  // Si en cada posicion de match encuentro una que contenga
  // tanto como yo quiero, entonces ese es el primer periodo
  //debug(sin_borde);
  //debug(patron);
  //debug(texto);
  vector<Long> ans = KMP(sin_borde, texto);
  //debug(ans);
  Long period;
  Long len = sin_borde.size();
  for (int i = 0; i < ans.size(); i++) {
    int pos = ans[i];
    if (texto[pos - 1] >= patron[0] && texto[pos + len] >= patron[len + 1]) {
      period = 0LL;
      for (int j = 0; j < pos - 1; j++) {
        if (texto[j] != -1) {
          period += texto[j];
        } else {
          period++;
        }
      }
      period += (texto[pos - 1] - patron[0] - 1);
      break;
    }
  }
  cout << period << '\n';
  return 0;
}
