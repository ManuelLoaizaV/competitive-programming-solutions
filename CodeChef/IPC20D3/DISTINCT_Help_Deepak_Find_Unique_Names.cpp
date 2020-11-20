#include <iostream>
#include <map>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

void Solve(void) {
  int n;
  cin >> n;
  map<string, bool> exists;
  while (n--) {
    string s;
    cin >> s;
    if (exists.count(s) == 0) exists[s] = true;
  }
  cout << exists.size() << '\n';
  for (auto it : exists) cout << it.first << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
