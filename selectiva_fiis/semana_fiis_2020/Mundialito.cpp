#include <algorithm>
#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int N = 1e6;

bool decreasing(const int& a, const int& b) {
  return (a > b);
}

bool IsValid(vector<int> a) {
  while (a.size() > 2) {
    vector<int> temp;
    int size = a.size();
    int new_size = a.size() / 2;
    if (size % 2 == 0) new_size--;
    for (int i = 0; i < new_size; i++) {
      temp.push_back(max(a[2 * i], a[2 * i + 1]));
    }
    if (size % 2 == 0) {
      if (a[size - 1] > a[size - 2]) {
        temp.push_back(a[size - 1]);
      } else {
        return false;
      }
    } else {
      temp.push_back(a[size - 1]);
    }
    a = temp;
  }
  return true;
}

void Print(int score, vector<int>& a) {
  int size = a.size();
  a[size - 1] = score;
  cout << score << '\n';
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int n;
  cin >> n;
  vector<int> a;
  vector<bool> has_appeared(N + 1, false);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    has_appeared[x] = true;
  }

  sort(a.begin(), a.end(), decreasing);
  a.push_back(1);
  int left = 1;
  int right = N + 1;

  if (IsValid(a)) {
    for (int i = left; i <= N; i++) {
      if (!has_appeared[i]) {
        Print(i, a);
        return 0;
      }
    }
    Print(N + 1, a);
    return 0;
  }

  while (right - left > 1) {
    int mid = (left + right) / 2;
    a[n] = mid;
    if (IsValid(a)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  for (int i = right; i <= N; i++) {
    if (!has_appeared[i]) {
      Print(i, a);
      return 0;
    }
  }

  Print(N + 1, a);
  return 0;
}
