//
// Created by ManuelLoaiza on 09/03/18
//
#include <bits/stdc++.h>

#define trace(x) cout << #x << " = " << x << endl

using namespace std;

const int MAX_N = 1e+4;
const int INF = 1e+9;

typedef pair<int, int> pii;

unordered_map<string, int> city;
vector<pii> graph[MAX_N];
int cost[MAX_N];

void initialize(int n) {
	city.clear();
	for (int i = 0; i < n; i++) graph[i].clear();
}

void Dijkstra(int s, int t) {
	priority_queue < pii, vector<pii>, greater<pii> > pq;
	cost[s] = 0;
	pq.push(make_pair(0, s));
	while (not pq.empty()) {
		pii actual = pq.top();
		pq.pop();
		int dist = actual.first;
		int u = actual.second;
		if(u == t) break;
		if (dist <= cost[u]) {
			int l = graph[u].size();
			for (int i = 0; i < l; i++) {
				int temp = dist + graph[u][i].first;
				int v = graph[u][i].second;
				if (temp < cost[v]) {
					cost[v] = temp;
					pq.push(make_pair(temp, v));
				}
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n;
	initialize(n);
	for (int u = 0; u < n; u++) {
		string name;
		cin >> name;
		city[name] = u;
		cin >> m;
		while (m--) {
			int v, c;
			cin >> v >> c;
			v--;
			graph[u].push_back(make_pair(c, v));
		}
	}

	int q;
	cin >> q;
	while (q--) {
		string uName, vName;
		cin >> uName >> vName;
		int u = city[uName];
		int v = city[vName];
		for(int i = 0; i < n; i++) cost[i] = INF;
		Dijkstra(u, v);
		cout << cost[v] << endl;
	} 
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
