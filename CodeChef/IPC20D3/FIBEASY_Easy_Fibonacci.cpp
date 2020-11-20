#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;

typedef long long Long;
vector<int> digit;

void Precalculate(void) {
  digit.push_back(0);
  digit.push_back(1);
  digit.push_back(1);
  while (true) {
    int len = digit.size();
    if (digit[len - 2] == 0 && digit[len - 1] == 1) break;
    int add = (digit[len - 2] + digit[len - 1]) % 10;
    digit.push_back(add);
  }
  digit.pop_back();
  digit.pop_back();
}

void Solve(void) {
  Long n;
  cin >> n;
  Long limit = 1LL;
  while (true) {
    if (2LL * limit <= n) {
      limit *= 2LL;
    } else {
      break;
    }
  }
  cout << digit[(limit - 1) % digit.size()] << '\n';
}

int main(void) {
  FAST_IO;
  Precalculate();
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
