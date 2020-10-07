#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
  FAST_IO;
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int comp = 0;
  vector<int> seen(n);
  for (int i = 0; i < n; i++) {
    if (seen[i]) continue;
    int u = i;
    while (!seen[u]) {
      seen[u] = true;
      u = p[u];
    }
    comp++;
  }
  cout << "Minimo que necesito es " << n - comp << '\n';
  return 0;
}
