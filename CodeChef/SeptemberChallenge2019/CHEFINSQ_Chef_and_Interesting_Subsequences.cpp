#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); i++)
using namespace std;

typedef long long ll;

const int N = 50;
const int A = 100;
ll freq[A + 1];
ll nCr[N + 1][N + 1];

void combinatorics() {
	For(i,0,N+1) nCr[i][0] = 1LL;
	For(i,1,N+1)
		For(j,1,i+1)
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
}

void solve() {
	ll n, k;
	cin >> n >> k;
	ll a[n], aux[n];
	For(i,0,n) {
		cin >> a[i];
		aux[i] = a[i];
	}
	sort(aux, aux + n);
	// frecuencia de cada numero para hallar #maneras de escoger a ese elemento
	memset(freq, 0, sizeof(freq));
	For(i,0,n) freq[a[i]]++;
	map<ll, ll> used;
	For(i,0,k) used[aux[i]]++;
	// para cada numero utilizado para la suma minima
	ll answer = 1LL;
	std::map<ll, ll>::iterator it;
	for (it = used.begin(); it != used.end(); it++) {
		ll num = it -> first;
		ll num_used = it -> second;
		answer *= nCr[freq[num]][num_used];
	}
	cout << answer << endl;
}

int main() {
	fastio;
	combinatorics();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

