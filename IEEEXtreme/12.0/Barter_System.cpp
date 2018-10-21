#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 20005;
const ll mod = 998244353;

bool visited[MAX_N];
int comp[MAX_N];
int nodes = 0;
int components = 0;
map<string, int> h;
std::map<string, int>::iterator it;
vector<int> adj[MAX_N];
vector<ll> r[MAX_N];
ll val[MAX_N];

void DFS(int u) {
	visited[u] = true;
	comp[u] = components;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			val[v] = (val[u] * r[u][i]) % mod;
			DFS(v);
		}
	}
}

ll gcdExtended(ll a, ll b, ll &x, ll &y) { 
    if (a == 0) { 
        x = 0;
		y = 1; 
        return b; 
    } 
    ll x1, y1;  
    ll gcd = gcdExtended(b % a, a, x1, y1); 
    x = y1 - (b / a) * x1; 
    y = x1; 
    return gcd; 
}
 
ll mod_inv(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, x, y); 
    if (g != 1) return 0; 
    else {  
    	ll res = (x % m + m) % m; 
        return res;
    } 
}

void f(string &s) {
	it = h.find(s);
	if (it == h.end()) {
		h[s] = nodes;
		nodes++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < MAX_N; i++) comp[i] = -1;
	for (int i = 0; i < N; i++) {
		string A, B;
		ll R;
		cin >> A >> B >> R;
		f(A);
		f(B);
		int u = h[A];
		int v = h[B];
		adj[u].push_back(v);
		r[u].push_back(R);
		adj[v].push_back(u);
		r[v].push_back(mod_inv(R,mod));
	}
	for (int i = 0; i < nodes; i++) {
		if (not visited[i]) {
			val[i] = 1;
			DFS(i);
			components++;
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		string a, b;
		cin >> a >> b;
		int u = h[a];
		int v = h[b];
		if (comp[u] != comp[v]) cout << "-1" << endl;
		else {
			ll answer = (val[v] * mod_inv(val[u], mod)) % mod;
			cout << answer << endl;
		}
	}
	return 0;
}
