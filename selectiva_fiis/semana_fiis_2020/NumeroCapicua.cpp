#include <iostream>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;

const int  N = 10;

char number[N];

void AddReverse(int pos, int len) {
  for (int i = 0; i < len; i++) {
    number[pos + i] = number[len - 1 - i];
  }
}

bool Check(int len, Long maximum) {
  Long current = 0;
  for (int i = 0; i < len; i++) {
    current = 10LL * current + (number[i] - '0');
  }
  return (current <= maximum);
}

Long Backtracking(int pos, int len, Long maximum) {
  Long cnt = 0LL;
  if (len == 1) {
    return min(9LL, maximum);
  }
  if (pos == (len / 2)) {
    if (len & 1) {
      AddReverse(pos + 1, len / 2);
      for (int digit = 0; digit <= 9; digit++) {
        number[pos] = char('0' + digit);
        if (Check(len, maximum)) cnt++;
      }
    } else {
      AddReverse(pos, len / 2);
      if (Check(len, maximum)) cnt++;
    }
    return cnt;
  }
  for (int digit = 0; digit <= 9; digit++) {
    if (pos == 0 && digit == 0) continue;
    number[pos] = char('0' + digit);
    cnt += Backtracking(pos + 1, len, maximum);
  }
  return cnt;
}

Long Count(Long maximum) {
  if (maximum == 0) return 0LL;
  Long answer = 0LL;
  for (int len = 1; len <= N; len++) {
    answer += Backtracking(0, len, maximum);
  }
  return answer;
}

int main(void) {
  FAST_IO;
  Long l, r;
  cin >> l >> r;
  Long answer = Count(r) - Count(l - 1);
  cout << answer << '\n';
  return 0;
}
