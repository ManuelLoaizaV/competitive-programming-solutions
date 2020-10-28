#include <iostream>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;

int main(void) {
  FAST_IO;
  Long t;
  cin >> t;
  while (t--) {
    Long d;
    cin >> d;
    for (int i = 0; i < 3; i++) {
      Long current = (3LL + i) * d;
      cout << current << " ";
    }
    cout << '\n';
  }
  return 0;
}
