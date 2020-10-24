#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 62;

vector<char> chr;
char ans[N][N];

void Initialize(void) {
  for (int i = 0; i < 10; i++) chr.push_back(char('0' + i));
  for (int i = 0; i < 26; i++) chr.push_back(char('a' + i));
  for (int i = 0; i < 26; i++) chr.push_back(char('A' + i));
}

void Print(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}

void Solve(void) {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << "impossible" << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = '$';
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) ans[i][n - 1] = chr[cnt];
  cnt++;
  int cohr = n / 2 - 1;
  for (int i = 0; i < cohr; i++) {
    int last = n - 2 - i;
    for (int j = 0; j <= last; j++) ans[i][j] = chr[cnt];
    for (int j = last; j < n - 1; j++) ans[i + 1][j] = chr[cnt];
    cnt++;
  }
  if (n & 1) cohr++;
  for (int i = 0; i < cohr; i++) {
    int last = n - 2 - i;
    for (int j = 0; j <= last; j++) ans[n - 1 - i][j] = chr[cnt];
    for (int j = last; j < n - 1; j++) ans[n - 2 - i][j] = chr[cnt];
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == '$') ans[i][j] = chr[cnt];
    }
  }
  Print(n);
}

int main(void) {
  FAST_IO;
  Initialize();
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
