#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

int main(void) {
  FAST_IO;
  Long n;
  cin >> n;
  string in[n];
  for (int i = 0; i < n; i++) cin >> in[i];
  sort(in, in + n);
  vector<pair<string, Long>> dic;
  Long counter = 1LL;
  for (int i = 1; i < n; i++) {
    if (in[i] == in[i - 1]) {
      counter++;
    } else {
      dic.push_back({in[i - 1], counter});
      counter = 1LL;
    }
  }
  dic.push_back({in[n - 1], counter}); 
  map<string, Long> dp;
  Long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    string& cur = dic[i].first;
    Long cnt = dic[i].second;
    for (int j = 0; j < 14; j++) {
      if (cur[j] == '-') continue;
      char temp = cur[j];
      cur[j] = '*';
      if (dp.count(cur)) ans += (cnt * dp[cur]);
      dp[cur] += cnt;
      cur[j] = temp;
    }
  }
  cout << ans << '\n';
  return 0;
}
