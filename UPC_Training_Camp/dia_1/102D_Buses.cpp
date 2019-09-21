#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = int(a); i < int(b); i++)
#define roF(i,a,b) for (int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll MOD = 1000000007LL;
const int N = 300010;

int tree[N];

bool comp(ii a, ii b) {
	if (a.second < b.second) return true;
	if (a.second == b.second) return a.first < b.first;
	return false;
}

void update(int i, ll delta) {
	while (i <= N) {
		tree[i] = (tree[i] + delta) % MOD;
		i += (i & -i);	
	}
}

ll query(int i) {
	ll answer = 0LL;
	while (i > 0) {
		answer = (answer + tree[i]) % MOD;
		i -= (i & -i);
	}
	return answer;
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vii stops;
	set<int> unique;
	For(i,0,m) {
		ii aux;
		cin >> aux.first >> aux.second;
		unique.insert(aux.first);
		unique.insert(aux.second);
		unique.insert(aux.second - 1);
		stops.push_back(aux);
	}
	sort(stops.begin(), stops.end(), comp);
	// Asimismo, a~nadimos el hogar y la escuela
	unique.insert(0);
	unique.insert(n);
	// Realizamos una compresion de coodenadas ya que a lo mas utilizaremos 2*10^5 + 2 stops
	std::set<int>::iterator it;
	vi elements;
	for (it = unique.begin(); it != unique.end(); it++) {
		elements.push_back(*it);
	}	
	sort(elements.begin(), elements.end());
	map<int, int> Hash;
	int sz = elements.size();
	For(i,0,sz) Hash[elements[i]] = i + 1;
	
	// Hay una sola manera de llegar a casa
	update(1, 1LL);
	For(i,0,m) {
		int l = Hash[stops[i].first];
		int r = Hash[stops[i].second];
		// De cuantas maneras puedo llegar a [l, r-1]
		ll ways = (query(r - 1) - query(l - 1) + MOD) % MOD;
		update(r, ways);
	}
	ll answer = (query(Hash[elements[sz - 1]]) - query(Hash[elements[sz - 2]]) + MOD) % MOD;
	cout << answer << endl;
	return 0;
}
