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
bool found[N], ok = true;
vector<int> adj[N], order;
int c[N];

void DFS(int u) {
	c[u]++;
	for (int v : adj[u]) {
		if (c[v] == 0) DFS(v);
		else if (c[v] == 1) ok = false;
	}
	c[u]++;
	order.push_back(u);
}

int main() {
	fastio;
	vector<string> s;
	while (true) {
		string t;
		cin >> t;
		if (t.size() == 1 and t[0] == '#') break;
		s.push_back(t);
	}
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int sz = s[i].size();
		for (int j = 0; j < sz; j++) found[s[i][j] - 'A'] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int sz1 = s[i].size();
		int sz2 = s[i + 1].size();
		if (sz1 <= sz2) {
			for (int j = 0; j < sz1; j++) {
				int c1 = s[i][j] - 'A';
				int c2 = s[i + 1][j] - 'A';
				if (c1 != c2) {
					adj[c1].push_back(c2);
					break;
				}
			}
		}
		if (sz1 > sz2) {
			bool foo = false;
			for (int j = 0; j < sz2; j++) {
				int c1 = s[i][j] - 'A';
				int c2 = s[i + 1][j] - 'A';
				if (c1 != c2) {
					adj[c1].push_back(c2);
					foo = true;
					break;
				}
			}
			if (not foo) ok = false;
		}
	}
	for (int i = 0; i < 26; i++) if (found[i] and c[i] == 0) DFS(i);
	int sz = order.size();
	if (ok)	for (int i = 0; i < sz; i++) cout << char('A' + order[sz - 1 - i]);
	cout << endl;
	return 0;
}