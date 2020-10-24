#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

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

const int N = 1e3;
const int M = 5e3;
const Long INF = 1e15;
const Double EPS = 1e-9;

map<string, Long> trans;
vector<Pair> cost[9];
Long dp[M][N + 1][9];
bool done[M][N + 1][9];

/*
 * DP(i, j, k) : Minimo costo de objetos que puedo obtener desde la posicion
 * [i ... M] con mayor o igual que j unidades del heroe k
 * 
 */

Long DP(Long pos, Long sobran, Long heroe) {
  if (sobran <= 0) return 0;
  int len = cost[heroe].size();
  if (pos == len) {
    if (sobran > 0) return INF;
    return 0LL;
  }
  if (done[pos][sobran][heroe]) return dp[pos][sobran][heroe];
  done[pos][sobran][heroe] = true;
  Long cnt = cost[heroe][pos].first;
  Long price = cost[heroe][pos].second;
  dp[pos][sobran][heroe] = min(DP(pos + 1, sobran, heroe), price + DP(pos + 1, sobran - cnt, heroe));
  return dp[pos][sobran][heroe];
}

int main(void) {
  FAST_IO;
  trans["Zulian"] = 0;
  trans["Razzashi"] = 1;
  trans["Hakkari"] = 2;
  trans["Sandfury"] = 3;
  trans["Skullsplitter"] = 4;
  trans["Bloodscalp"] = 5;
  trans["Gurubashi"] = 6;
  trans["Vilebranch"] = 7;
  trans["Witherbark"] = 8;
  Long n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string name;
    Long cnt, price;
    cin >> name >> cnt >> price;
    cost[trans[name]].push_back({cnt, price});
  }

  Long ans = INF;
  // Fusionamos los resultados parciales
  for (Long i = 0; i <= n; i++) {
    for (Long j = 0; j + i <= n; j++) {
      Long k = n - i - j;
      vector<Long> mn;
      mn.push_back(DP(0, i, 0));
      mn.push_back(DP(0, i, 1));
      mn.push_back(DP(0, i, 2));
      
      mn.push_back(DP(0, j, 3));
      mn.push_back(DP(0, j, 4));
      mn.push_back(DP(0, j, 5));

      mn.push_back(DP(0, k, 6));
      mn.push_back(DP(0, k, 7));
      mn.push_back(DP(0, k, 8));
      //debug(mn);

      bool possible = true;
      for (Long x : mn) {
        if (x >= INF) {
          possible = false;
          break;
        }
      }
      if (possible) {
        Long sum = 0LL;
        for (Long x : mn) sum += x;
        ans = min(ans, sum);
      }
    }
  }
  if (ans >= INF) {
    cout << "impossible" << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}
