#include <iostream>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int N = 2e5;
int cnt[N + 1][10];

void Update(int number, int current) {
  if (current < 10) {
    cnt[number][current]++;
  } else {
    int digit = current % 10;
    cnt[number][digit]++;
    Update(number, current / 10);
  }
}

void Precalculate(void) {
  for (int number = 1; number <= N; number++) {
    for (int digit = 0; digit < 10; digit++) {
      cnt[number][digit] = cnt[number - 1][digit];
    }
    Update(number, number);
  }
}

void Solve(void) {
  int bound, digit;
  cin >> bound >> digit;
  cout << cnt[bound][digit] << '\n';
}

int main(void) {
  FAST_IO;
  Precalculate();
  int q;
  cin >> q;
  while (q--) Solve();
  return 0;
}
