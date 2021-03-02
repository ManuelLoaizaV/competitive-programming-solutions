//https://codeforces.com/contest/1494/problem/D
#include <bits/stdc++.h>

using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e5;

struct DisjointSets {
  int parent[N];
  int size[N];
  void MakeSet(int u) {
    parent[u] = u;
    size[u] = 1;
  }
  void Build(int n) { for (int i = 0; i < n; i++) MakeSet(i); }
  int Find(int u) {
    if (parent[u] == u) return u;
    return (parent[u] = Find(parent[u]));
  }
  void Join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
      if (size[u] > size[v]) swap(u, v);
      parent[u] = v;
      size[v] += size[u];
    }
  }
  bool SameSet(int u, int v) { return Find(u) == Find(v); }
  int GetSize(int u) { return size[Find(u)]; }
} dsu;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int nodes = n;
  vector<int> salary(N);
  vector<map<int, int>> link_salary(n);
  for (int i = 0; i < n; i++) salary[i] = a[i][i];
  dsu.Build(N);
  vector<int> adj[N];
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> lca;
    for (int j = 0; j < n; j++) {
      if (j != i) lca.emplace_back(a[i][j], j);
    }
    sort(lca.begin(), lca.end());
    int previous_ancestor = i;
    for (int j = 0; j < (int) lca.size(); j++) {
      int k = j;
      while (k < (int) lca.size() && lca[k].first == lca[j].first) k++;
      k--;
      int current_ancestor = -1;
      int current_salary = lca[j].first;
      for (int l = j; l <= k; l++) {
        int& leaf = lca[l].second;
        if (link_salary[leaf].count(current_salary) > 0) {
          current_ancestor = link_salary[leaf][current_salary];
          break;
        }
      }
      if (link_salary[i].count(current_salary) > 0) {
        current_ancestor = link_salary[i][current_salary];
      }
      if (current_ancestor == -1) {
        current_ancestor = nodes;
        salary[current_ancestor] = current_salary;
        nodes++;
      }
      for (int l = j; l <= k; l++) link_salary[lca[j].second][current_salary] = current_ancestor;
      link_salary[i][current_salary] = current_ancestor;
      if (!dsu.SameSet(previous_ancestor, current_ancestor)) {
        adj[current_ancestor].push_back(previous_ancestor);
        dsu.Join(previous_ancestor, current_ancestor);
      }
      previous_ancestor = current_ancestor;
      j = k;
    }
  }
  // Imprimo lo solicitado
  cout << nodes << '\n';
  for (int i = 0; i < nodes; i++) {
    if (i > 0) cout << " ";
    cout << salary[i];
  }
  int root = 0;
  for (int i = 1; i < nodes; i++) {
    if (salary[i] > salary[root]) {
      root = i;
    }
  }
  cout << '\n';
  cout << root + 1 << '\n';
  for (int i = 0; i < nodes; i++) {
    for (int j : adj[i]) {
      cout << j + 1 << " " << i + 1 << '\n';
    }
  }
  return 0;
}