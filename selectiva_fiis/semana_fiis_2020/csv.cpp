#include <iostream>
#include <string>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

int StringToInt(string& s) {
  int value = 0;
  int len = s.size();
  for (int i = 0; i < len; i++) {
    value = 10 * value + (s[i] - '0');
  }
  return value;
}

int main(void) {
  FAST_IO;
  int size;
  cin >> size;
  string csv;
  cin >> csv;

  string answer = "";
  int first = 0;
  while (first < size) {
    int last = first;
    while (csv[last] != '*') last++;
    string len = csv.substr(first, last - first);
    int int_len = StringToInt(len);
    if (first > 0) answer += ' ';
    answer += csv.substr(last + 1, int_len);
    first = last + int_len + 1;
  }
  cout << answer << '\n';
  return 0;
}
