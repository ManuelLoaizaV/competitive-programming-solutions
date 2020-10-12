// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int N = 26;

bool seen[N], used[N];
int n, in[N], ans[N];
vector<int> adj[N];

void Print() {
  for (int i = 0; i < n; i++) {
    cout << char('a' + ans[i]);
  }
  cout << '\n';
}

void Backtracking(int pos) {
  if (pos == n) {
    Print();
    return;
  }
  vector<int> can;
  for (int i = 0; i < N; i++) {
    if (seen[i] && !used[i] && in[i] == 0) {
      can.push_back(i);
    }
  }
  for (int from : can) {
    for (int to : adj[from]) in[to]--;
    used[from] = true;
    ans[pos] = from;
    Backtracking(pos + 1);
    for (int to : adj[from]) in[to]++;
    used[from] = false;
  }
}

void Initialize() {
  n = 0;
  for (int i = 0; i < N; i++) {
    adj[i].clear();
    seen[i] = false;
    used[i] = false;
    in[i] = 0;
  }
}

int main() {
  FAST_IO;
  string line;
  bool first_time = true;
  while (getline(cin, line)) {
    Initialize();
    stringstream ss(line);
    char chr;
    while (ss >> chr) {
      n++;
      seen[chr - 'a'] = true;
    }

    getline(cin, line);
    stringstream aux(line);
    char u, v;
    while (aux >> u >> v) {
      adj[u - 'a'].push_back(v - 'a');
      in[v - 'a']++;
    }
    if (first_time) {
      first_time = false;
    } else {
      cout << '\n';
    }
    Backtracking(0);
  }
  return 0;
}
