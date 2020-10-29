#include <iostream>
#include <map>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef pair<int, int> Pair;

const int N = 1e6;
int factor[N + 1];

void Sieve(void) {
  for (int i = 0; i <= N; i++) factor[i] = i;
  for (int i = 2; i * i <= N; i++) {
    if (factor[i] == i) {
      for (int j = i * i; j <= N; j += i) factor[j] = i;
    }
  }
}

vector<Pair> Factorize(int number) {
  vector<Pair> result;
  while (number > 1) {
    int prime = factor[number];
    int exponent = 0;
    while (number % prime == 0) {
      number /= prime;
      exponent++;
    }
    result.push_back({prime, exponent});
  }
  return result;
}

int main(void) {
  FAST_IO;
  int n, k;
  cin >> n >> k;

  Sieve();
  map<int, int> maximum;
  for (int i = 0; i < n; i++) {
    if (factor[i] == i) {
      maximum[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int current;
    cin >> current;
    vector<Pair> factorization = Factorize(current);
    for (Pair p : factorization) {
      int prime = p.first;
      int exponent = p.second;
      int previous = maximum[prime];
      maximum[prime] = max(exponent, previous);
    }
  }

  vector<Pair> factorization = Factorize(k);
  for (Pair p : factorization) {
    int prime = p.first;
    int exponent = p.second;
    if (maximum[prime] >= exponent) continue;
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  return 0;
}
