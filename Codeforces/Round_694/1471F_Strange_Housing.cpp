//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N + 1];
int color[N + 1];
bool is_visited[N + 1];

void Initialize(int n) {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    color[i] = 0;
    is_visited[i] = false;
  }
}

// P(n): La componente coloreada tras la n-esima ejecucion del DFS
// es conexa y no tenemos nodos de color 1 conectados via una arista.
// 
// Prueba: Realizemos la prueba por induccion.
//
// P(1):
// Nuestro case base esta pintando el primer nodo de color 1. Por lo tanto,
// todos sus vecinos son de color 2 y no tenemos nodos de color 1 conectados via alguna arista.
// Asimismo, todo vecino de dicho nodo puede conectarse a otro via ese nodo, o ese nodo
// puede conectarse a alguno de ellos mediante su respectiva arista por lo cual la componente es conexa.
//
// Asumamos que P(n) es cierta. 
//
// P(n + 1):
// Aqui podemos analizar dos casos dependiendo del color del n-esimo nodo que permitio
// ejecutar DFS por (n + 1)-esima vez.
// Si mi padre fue de color 1, entonces el actual nodo es de color 2.
// Esto significa que yo buscare algun nodo sin colorear, el cual ser[a pintado de rojo.
// Al realizar esto, ese unico nodo se esta conectando con los anteriores por hipotesis inductiva
// y tampoco quiebro la condicion del color puesto que ese sujeto esta solo rodeado de nodos de color 2 o sin colorear.
// Si mi padre fue de color 2, entonces el actual nodo es de color 1.
// Esto significa que a mi alrededor todos son de color 2 o sin colorear, puesto que los
// nodos de color 2 solo visitan a nodos sin colorear y para no haber sido coloreado, ningun
// nodo de color 1 tuvo que ser mi vecino. Como soy de color 1, entonces a todos mis vecinos los pinto
// de color 2. Estos se pueden conectar a todos los anteriores puesto que por hipotesis inductiva, los otros eran conexos,
// y estos son conexos conmigo por el caso base de un solo paso. Asimismo, no se quiebra la condicion del color ya que he pintado
// a nodos de color 2 y yo no soy adyacente a nodos de color 1.
// En ambos casos la componente sigue siendo conexa y no quebramos la condicion del color.
//
// Finalmente, hemos completado la prueba por induccion.

void DFS(int u) {
  is_visited[u] = true;
  if (color[u] == 1) {
    for (int v : adj[u]) color[v] = 2;
    for (int v : adj[u]) if (!is_visited[v]) DFS(v);
  } else {
    for (int v : adj[u]) {
      if (!is_visited[v] && color[v] == 0) {
        color[v] = 1;
        DFS(v);
      }
    }
  }
}

void Solve(void) {
  int n, m;
  cin >> n >> m;
  Initialize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!is_visited[i]) {
      cnt++;
      color[i] = 1;
      DFS(i);
    }
  }
  if (cnt > 1) {
    cout << "NO" << '\n';
  } else {
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (color[i] == 1) ans.push_back(i);
    int len = ans.size();
    cout << "YES" << '\n';
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
