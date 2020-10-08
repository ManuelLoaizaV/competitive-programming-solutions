#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

//vector<vector<int>> g, rg;
int seen[N], id[N], tag;

/*
void DFS1(int u, stack<int>& st) {
  seen[u] = true;
  for (int v : g[u]) if (!seen[v]) DFS1(v, st);
  st.push(u);
}

void DFS2(int u) {
  seen[u] = true;
  id[u] = tag;
  cout << u << " ";
  for (int v : rg[u]) if (!seen[v]) DFS2(v);
}
*/

vector<vector<int>> g[2];
void DFS(int ind, int u, stack<int>& st) {
  seen[u] = true;
  if (ind) cout << u << " ";
  for (int v : g[ind][u]) if (!seen[v]) DFS(ind, v, st);
  if (ind == 0) st.push(u);
  else id[u] = tag;
}

int main() {
  int n, m;
  cin >> n >> m;
  //g.assign(n + 1, {});
  //rg.assign(n + 1, {});
  g[0].assign(n + 1, {});
  g[1].assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    //g[a].push_back(b);
    //rg[b].push_back(a);
    g[0][a].push_back(b);
    g[1][b].push_back(a);
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    //if (!seen[i]) DFS1(i, st);
    if (!seen[i]) DFS(0, i, st);
  }
  // En el stack tengo los nodos ordenados en orden topologico por componente
  memset(seen, 0, sizeof(seen));
  while (st.size()) {
    int u = st.top();
    st.pop();
    if (seen[u]) continue;
    tag++;
    DFS(1, u, st);
    cout << endl;
  }

  vector<vector<int>> ng(tag + 1);
  for (int i = 1; i <= n; i++) {
    for (int j : g[0][i]) {
      if (id[i] != id[j]) ng[id[i]].push_back(id[j]);
    }
  }
  return 0;
}
