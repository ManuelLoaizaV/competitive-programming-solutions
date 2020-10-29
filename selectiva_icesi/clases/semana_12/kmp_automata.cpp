#include <bits/stdc++.h>
using namespace std;

vector<int> CalculatePi(string& p) {
  int n = p.size();
  vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1, j = 0; j < n; i++) {
    if (p[i] == p[j]) {
      j++;
    } else {
      while (j > 0 && p[i] != p[j]) j = pi[j - 1];
      if (p[i] == p[j]) j++;
    }
    pi[i] = j;
  }
  return pi;
}

const int N = 102;
const int ALPHABET = 256;
int automata[N][ALPHABET];

int main(void) {
  string p;
  cin >> p;
  vector<int> pi = CalculatePi(p);
  int n = p.size();

  for (int i = 0; i < ALPHABET; i++) automata[0][i] = 0;
  automata[0][p[0]] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ALPHABET; j++) {
      if (i < n && j == p[i]) {
        automata[i][j] = i + 1;
      } else {
        automata[i][j] = automata[pi[i - 1]][j];
      }
    }
  }
  return 0;
}
