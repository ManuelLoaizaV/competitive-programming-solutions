// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const Long INF = 1e13;

vector<vector<Pair>> adj;
vector<vector<Long>> t;
Long n, m;

// Encuentro primero >= x
Long Primero(Long who, Long x) {
  vector<Long>& cur = t[who];
  Long l = 0LL;
  Long r = (Long)(cur.size()) - 1LL;
  if (r < 0) return -1;
  if (cur[r] < x) return -1;
  if (cur[l] >= x) return l;
  while (r - l > 1) {
    Long mid = (l + r) / 2;
    if (cur[mid] >= x) r = mid;
    else l = mid;
  }
  if (cur[l] >= x) return l;
  return r;
}

// Estando en t[who][ind], cuanto debo esperar para no encontrar consecutivos
Long Longitud(Long who, Long ind) {
  vector<Long>& cur = t[who];
  Long l = ind;
  Long r = (Long)(cur.size()) - 1LL;
  if ((cur[r] - cur[ind]) == (r - ind)) return (r - ind + 1LL);
  while (r - l > 1) {
    Long mid = (l + r) / 2;
    if ((cur[mid] - cur[ind]) == (mid - ind)) l = mid;
    else r = mid;
  }
  if ((cur[r] - cur[ind]) == (r - ind)) return (r - ind + 1LL);
  return (l - ind + 1LL);
}

Long Esperar(Long u, Long t_u) {
  // Importante, si llego al destino, no espero nada
  if (u == n) return 0LL;
  // Primero, encuentro si es que tenemos que esperara alguien
  Long ind = Primero(u, t_u);
  if (ind == -1) return 0LL;  // Si nunca aparece
  if (t[u][ind] > t_u) return 0LL;  // El encontrado tampoco lo es
  // Si es que aparece, chequeo cuanto tiempo debo esperar para estar libre
  Long cnt = Longitud(u, ind);
  return cnt;
}

// Nueva metrica entre dos planetas
// dist(u, v) = d[u] + w + esperar(v, d[u] + w)
Long Dist(Long u, Long v, Long t_u, Long w) {
  Long t_v = t_u + w;
  Long ans = t_v + Esperar(v, t_v);
  return ans;
}

int main() {
  FAST_IO;
  cin >> n >> m;
  adj.resize(n + 1);
  t.resize(n + 1);
  for (int i = 0; i < m; i++) {
    Long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  // Pusheo las penalidades para hacer binary search sobre longitud de tiempo
  for (Long i = 0; i < n; i++) {
    Long n_i;
    cin >> n_i;
    for (Long j = 0; j < n_i; j++) {
      Long t_i_j;
      cin >> t_i_j;
      t[i + 1].push_back(t_i_j);
    }
  }
  // Dijkstra
  vector<Long> d(n + 1, INF);
  d[1] = Dist(1, 1, 0, 0);
  priority_queue<Pair, vector<Pair>, greater<Pair>> q;
  q.push({d[1], 1});
  while (q.size()) {
    Long u = q.top().second;
    Long w = q.top().first;
    //debug(u);
    //debug(w);
    q.pop();
    if (d[u] != w) continue;
    for (Pair e : adj[u]) {
      Long v = e.first;
      Long nw = Dist(u, v, w, e.second);
      //debug(v);
      //debug(nw);
      if (nw < d[v]) {
        d[v] = nw;
        q.push({d[v], v});
      }
    }
  }
  if (d[n] >= INF) cout << -1 << '\n';
  else cout << d[n] << '\n';
  return 0;
}
