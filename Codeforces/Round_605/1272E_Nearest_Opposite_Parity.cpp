// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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

vi adj[N + 2];
bool visited[N + 2];

void BFS(int root, ll h[]) {
	queue<int> q;
	visited[root] = true;
	q.push(root);
	h[root] = -1;
	while (not q.empty()) {
		int u = q.front();
		q.pop();
		int sz = adj[u].size();
		For(i,0,sz) {
			int v = adj[u][i];
			if (not visited[v]) {
				visited[v] = true;
				q.push(v);
				h[v] = h[u] + 1;
			}
		}
	}
}

int main() {
	fastio;
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	ll odd[n + 2], even[n + 2];
	For(i,0,n) odd[i] = even[i] = -1;
	For(i,0,n) {
		int l = i - a[i];
		int r = i + a[i];
		if (0 <= l and l < n) adj[l].pb(i);
		if (0 <= r and r < n) adj[r].pb(i);
		// (N)-> pares
		// (N+1)->impares
		if (a[i] % 2 == 0) adj[n].pb(i);
		else adj[n + 1].pb(i);
	}
	memset(visited, 0, sizeof(visited));
	BFS(n, even);
	memset(visited, 0, sizeof(visited));
	BFS(n + 1, odd);
	For(i,0,n) {
		ll ans;
		if (a[i] % 2 == 0) ans = odd[i];
		else ans = even[i];
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}
