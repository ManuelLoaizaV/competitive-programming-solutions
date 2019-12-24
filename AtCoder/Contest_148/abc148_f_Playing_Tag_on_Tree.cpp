// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int n, ta, ao;
bool used[N], below[N];
int h[N], anc[N];
bool ok;
vi adj[N];

void BFS(int root) {
	used[root] = true;
	h[root] = 0;
	anc[root] = -1;
	queue<int> q;
	q.push(root);
	while (not q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (not used[v]) {
				used[v] = true;
				h[v] = h[u] + 1;
				anc[v] = u;
				q.push(v);
			}
		}
	}
}

void DFS(int u) {
	used[u] = true;
	if (u == ta) ok = true;
	if (ok) below[u] = true;
	for (int v : adj[u]) {
		if (not used[v]) DFS(v);
	}
	if (u == ta) ok = false;
}

int main() {
	fastio;
	cin >> n >> ta >> ao;
	For(i,0,n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	BFS(ao);
	int ans = 0;
	int subir = (h[ta] % 2 == 0 ? (h[ta] / 2 - 1) : h[ta] / 2);
	ans += subir;
	For(i,0,subir) ta = anc[ta];
	memset(used, 0, sizeof(used));
	DFS(ao);
	int maxi = 0;
	For(i,0,n+1) if (below[i]) maxi = max(maxi, h[i]);
	bool tak = true;
	int h_ao = h[ao] + subir;
	int h_ta = h[ta];
	while (1) {
		//debug(h_ta);
		//debug(h_ao);
		if (h_ao == h_ta) break;
		if (tak) {
			if (h_ta < maxi) h_ta++;
			else h_ta--;
		} else {
			ans++;
			h_ao++;
		}
		tak = not tak;
	}
	cout << ans << endl;
	return 0;
}
