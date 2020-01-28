#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 26;
bool found[N];
int deg[N];
vector<int> adj[N];
vector<char> nodes;
vector<pair<char, char>> edges;
deque<char> ans;

void init() {
	nodes.clear();
	edges.clear();
	for (int i = 0; i < N; i++) {
		found[i] = false;
		deg[i] = 0;
		adj[i].clear();
	}
}

void solve(set<pair<int, int>> order) {
	if (order.size() == 0) {
		int sz = ans.size();
		for (int i = 0; i < sz; i++) {
			cout << ans[i];
		}
		cout << endl;
		return;
	}
	for (pair<int, int> fst : order) {
		int in = fst.first;
		int u = fst.second;
		if (in != 0) return;
		ans.push_back(char('a' + u));
		set<pair<int, int>> copy = order;
		copy.erase({in, u});
		for (int v : adj[u]) {
			copy.erase({deg[v], v});
			deg[v]--;
			copy.insert({deg[v], v});
		}
		solve(copy);
		ans.pop_back();
		for (int v : adj[u]) deg[v]++;
	}
}

int main() {
	fastio;
	string V, E;
	bool fst = true;
	while (getline(cin, V)) {
		getline(cin, E);
		init();
		if (fst) fst = false;
		else cout << endl;
		stringstream ss(V);
		char u, v;
		while (ss >> u) {
			//debug(u);
			nodes.push_back(u);
		}
		ss.str("");
		ss.clear();
		ss << E;
		while (ss >> u) {
			ss >> v;
			edges.push_back({u, v});
			//debug(u, v);
		}
		// Aqui construyo el grafo
		int n = nodes.size();
		int m = edges.size();
		for (int i = 0; i < n; i++) found[nodes[i] - 'a'] = true;
		for (int i = 0; i < m; i++) {
			int from = edges[i].first - 'a';
			int to = edges[i].second - 'a';
			adj[from].push_back(to);
			deg[to]++;
			//debug(edges[i].first, edges[i].second, deg[edges[i].second]);
		}
		set<pair<int, int>> order;
		for (int i = 0; i < N; i++) if (found[i]) order.insert({deg[i], i});
		//debug(order);
		solve(order);
	}
	return 0;
}
