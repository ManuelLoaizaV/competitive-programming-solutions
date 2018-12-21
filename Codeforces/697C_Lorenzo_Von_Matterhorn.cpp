#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;

map <pll, ll> edges;
std::map <pll, ll>::iterator it;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		ll t, u, v, w;
		cin >> t >> u >> v;
		if (t == 1) {
			cin >> w;
			while (u != v) {
				ll m = min(u, v);
				ll M = max(u, v);
				ll ancestor = M / 2;
				pll edge = make_pair(ancestor, M);
				it = edges.find(edge);
				if (it == edges.end()) edges[edge] = w;
				else edges[edge] += w;
				u = ancestor;
				v = m;
			}
		} else { // t == 2
			ll sum = 0;
			while (u != v) {
				ll m = min(u, v);
				ll M = max(u, v);
				ll ancestor = M / 2;
				pll edge = make_pair(ancestor, M);
				it = edges.find(edge);
				if (it != edges.end()) sum += edges[edge];
				u = ancestor;
				v = m;
			}
			cout << sum << endl;	
		}
	}
	return 0;
}