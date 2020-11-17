// Gracias, Rodolfo
// Gracias, Graphter
// Gracias, Osman
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
#define x first
#define y second
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

vector<vector<Pair>> ans;

void Change(Pair pos, vector<string>& s) {
  if (s[pos.x][pos.y] == '0') {
    s[pos.x][pos.y] = '1';
  } else {
    s[pos.x][pos.y] = '0';
  }
}

void Print(vector<Pair> pos) {
  for (Pair p : pos) {
    cout << p.x + 1 << " " << p.y + 1 << " ";
  }
  cout << '\n';
}

void Analyze(vector<Pair> pos, vector<string>& s) {
  vector<Pair> print;
  int cnt = 0;
  for (Pair p : pos) cnt += (s[p.x][p.y] - '0');
  if (cnt == 0) return;
  if (cnt == 1) {
    if (s[pos[2].x][pos[2].y] == '1' || s[pos[3].x][pos[3].y] == '1') return;
    if (s[pos[0].x][pos[0].y] == '1') {
      print.push_back(pos[0]);
      Change(pos[0], s);
    } else {
      print.push_back(pos[1]);
      Change(pos[1], s);
    }
    print.push_back(pos[2]);
    Change(pos[2], s);
    print.push_back(pos[3]);
    Change(pos[3], s);

    ans.push_back(print);
    return;
  }
  if (cnt == 2) {
    if (s[pos[2].x][pos[2].y] == '1' && s[pos[3].x][pos[3].y] == '1') {
      return;
    }
    if (s[pos[0].x][pos[0].y] == '1' && s[pos[2].x][pos[2].y] == '1') {
      Change(pos[0], s);
      Change(pos[2], s);
      Change(pos[3], s);
      print.push_back(pos[0]);
      print.push_back(pos[2]);
      print.push_back(pos[3]);
      ans.push_back(print);
      return;
    }  
    if (s[pos[1].x][pos[1].y] == '1' && s[pos[3].x][pos[3].y] == '1') {
      Change(pos[1], s);
      Change(pos[2], s);
      Change(pos[3], s);
      print.push_back(pos[1]);
      print.push_back(pos[2]);
      print.push_back(pos[3]);
      ans.push_back(print);
      return;
    }
    if (s[pos[0].x][pos[0].y] == '1' && s[pos[3].x][pos[3].y] == '1') {
      Change(pos[0], s);
      Change(pos[2], s);
      Change(pos[3], s);
      print.push_back(pos[0]);
      print.push_back(pos[2]);
      print.push_back(pos[3]);
      ans.push_back(print);
      return;
    }
    if (s[pos[0].x][pos[0].y] == '1' && s[pos[1].x][pos[1].y] == '1') {
      Change(pos[0], s);
      Change(pos[1], s);
      Change(pos[3], s);
      print.push_back(pos[0]);
      print.push_back(pos[1]);
      print.push_back(pos[3]);
      ans.push_back(print);
      return;
    }
    if (s[pos[1].x][pos[1].y] == '1' && s[pos[2].x][pos[2].y] == '1') {
      Change(pos[1], s);
      Change(pos[2], s);
      Change(pos[3], s);
      print.push_back(pos[1]);
      print.push_back(pos[2]);
      print.push_back(pos[3]);
      ans.push_back(print);
      return;
    }
  }
  if (cnt == 3) {
    for (Pair p : pos) {
      if (s[p.x][p.y] == '1') {
        Change(p, s);
        print.push_back(p);
      }
    }
    ans.push_back(print);
    return;
  }
  // cnt == 4
  for (int i = 0; i < 3; i++) {
    print.push_back(pos[i]);
    Change(pos[i], s);
  }
  ans.push_back(print);
}

void Solve(void) {
  ans.clear();
  Long n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  if (n == 2 && m == 2) {
    int cnt = 0;
    vector<Pair> pos;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (s[i][j] == '1') {
          pos.push_back({i, j});
          cnt++;
        }
      }
    }
    if (cnt == 3) {
      cout << 1 << '\n';
      Print(pos);
      return;
    }
    if (cnt == 4) {
      vector<vector<Pair>> ans;
      vector<Pair> add;
      add.push_back(pos[0]);
      add.push_back(pos[1]);
      add.push_back(pos[2]);
      ans.push_back(add);

      add.clear();
      add.push_back(pos[0]);
      add.push_back(pos[2]);
      add.push_back(pos[3]);
      ans.push_back(add);

      add.clear();
      add.push_back(pos[0]);
      add.push_back(pos[1]);
      add.push_back(pos[3]);
      ans.push_back(add);

      add.clear();
      add.push_back(pos[1]);
      add.push_back(pos[2]);
      add.push_back(pos[3]);
      ans.push_back(add);

      cout << ans.size() << '\n';
      for (int i = 0; i < ans.size(); i++) Print(ans[i]);
      return;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (i == n - 2 && j == m - 2) continue;
      // a0 a1
      // a2 a3
      vector<Pair> pos;
      pos.push_back({i, j});
      pos.push_back({i, j + 1});
      pos.push_back({i + 1, j});
      pos.push_back({i + 1, j + 1});
      Analyze(pos, s);
    }
  }

  for (int i = 0; i < m - 1; i++) {
    vector<Pair> pos;
    pos.push_back({n - 1, i});
    pos.push_back({n - 2, i});
    pos.push_back({n - 1, i + 1});
    pos.push_back({n - 2, i + 1});
    Analyze(pos, s);
  }

  int cnt = 0;
  for (int i = 0; i < 2; i++) if (s[n - 1 - i][m - 1] == '1') cnt++;
  if (cnt > 0) {
    if (cnt == 2) {
      vector<Pair> pos;
      pos.push_back({n - 1, m - 1});
      pos.push_back({n - 1, m - 2});
      pos.push_back({n - 2, m - 2});
      ans.push_back(pos);

      pos.clear();
      pos.push_back({n - 2, m - 2});
      pos.push_back({n - 2, m - 1});
      pos.push_back({n - 1, m - 2});
      ans.push_back(pos);
    } else {
      vector<Pair> pos; 
      pos.push_back({n - 2, m - 2});
      pos.push_back({n - 1, m - 2});
      if (s[n - 1][m - 1] == '1') {
        pos.push_back({n - 1, m - 1});
      } else {
        pos.push_back({n - 2, m - 1});
      }
      ans.push_back(pos);
      
      pos.clear();
      pos.push_back({n - 2, m - 2});
      pos.push_back({n - 2, m - 1});
      pos.push_back({n - 1, m - 1});
      ans.push_back(pos);

      pos.clear();
      pos.push_back({n - 2, m - 1});
      pos.push_back({n - 1, m - 2});
      pos.push_back({n - 1, m - 1});
      ans.push_back(pos);
    }
  }

  int len = ans.size();
  cout << len << '\n';
  for (int i = 0; i < len; i++) Print(ans[i]);
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
