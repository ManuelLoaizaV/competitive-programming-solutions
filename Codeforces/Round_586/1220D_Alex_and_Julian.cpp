#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = int(a); i < int(b); i++)
#define roF(i,a,b) for (int i = int(a); i >= int(b); i--)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 2e5;

bool comp(pll a, pll b) {
	return a.second < b.second;
}

int main() {
	fastio;
	int n;
	cin >> n;
	pll b[n];
	For(i,0,n) {
		cin >> b[i].first;
		b[i].second = -1LL;
	}
	// Precalcular potencias de 2 hasta 2^59
	// <2^i, freq(2^i)>
	vector<pll> pot;
	pot.push_back(make_pair(1LL, 0LL));
	For(i,1,60) {
		ll aux = pot[pot.size() - 1].first * 2LL;
		pot.push_back(make_pair(aux, 0LL));
	}
	int sz = pot.size();
	// Que potencia de 2 dividio a b_i
	ll raise[n];
	For(i,0,n)
		For(j,0,sz)
			if (b[i].first % pot[j].first == 0LL) {
				if (b[i].second != -1LL) {
					ll k = raise[i];//TODO
					pot[k].second--;
				}
				b[i].second = pot[j].first;
				pot[j].second++;
				raise[i] = j;
			}
	sort(pot.begin(), pot.end(), comp);
	ll found = pot[sz - 1].first;
	ll k = n - pot[sz - 1].second;
	cout << k << endl;
	For(i,0,n) if (b[i].second != found) cout << b[i].first << " ";
	return 0;
}
