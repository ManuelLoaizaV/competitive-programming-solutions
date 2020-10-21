#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int N = 1e5;
int nxt[N][26];
int cnt[N];
bool terminal[N];
int nodes = 1;

void add(string& s, int val) {
  int from = 0;
  for (char c : s) {
    int to = c - 'a';
    if (nxt[from][to] == 0) {
      nxt[from][to] = nodes++;
    }
    from = nxt[from][to];
    cnt[from] += val;
  }
  terminal[from] = (val == 1);
}

bool find(string& s) {
  int from = 0;
  for (char c : s) {
    int to = c - 'a';
    if (nxt[from][to] == 0) return false;
    from = nxt[from][to];
  }
  return terminal[from];
}

int main(void) {
  FAST_IO;
  int q;
  cin >> q;
  while (q--) {
    string cmd, w;
    cin >> cmd >> w;
    if (cmd == "add") add(w, 1);
    if (cmd == "del") add(w, -1);
    if (cmd == "query") {
      if (find(w)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
