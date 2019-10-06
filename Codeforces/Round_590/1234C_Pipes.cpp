// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e4;
const ll INF = 1e18;
const ld EPS = 10e-9;
//bool dp[6][6][N + 5][2];
/*
	DP(up, down, pos, from)
	up: configuracion
	down:
	pos: columna en la que me encuentro
	from: 0 (el agua fluye desde la fila 1) 1 (el agua fluye de la fila 2)
*/
int n;
string pipes[2];
map<char, int> h;
/*
	Hay ciertos pipes equivalentes
	1 y 2: los llamare tipo 0
	3, 4, 5 y 6: los llamare tipo 1

	A las diferentes rotaciones les colocare numeros
	| 0
	- 1
	|- 2
	-| 3
	_| 4
	|_ 5
*/

/*
void clean(int n) {
	For(i,0,6)
		For(j,0,6)
			For(k,0,n+1)
				For(l,0,2)
					dp[i][j][k][l] = used[i][j][k][l] = false;
}
*/

bool DP(int pos, int from) {
	if (pos == n) {
		if(from == 1) return true;
		return false;
	}
	//if (used[up][down][pos][from]) return dp[up][down][pos][from];
	//used[up][down][pos][from] = true;
	int tipo_1 = h[pipes[0][pos]];
	int tipo_2 = h[pipes[1][pos]];
	// Si fluye el agua desde arriba
	if (from == 0) {
		if (tipo_1 == 0) return DP(pos + 1, 0);
		if (tipo_1 == 1 and tipo_2 == 1) return DP(pos + 1, 1);
		return false;
	} else {
		if (tipo_2 == 0) return DP(pos + 1, 1);
		if (tipo_2 == 1 and tipo_1 == 1) return DP(pos + 1, 0);
		return false;
	}
}

void solve() {
	cin >> n;
	For(i,0,2) cin >> pipes[i];
	//if (DP(0,0,0,0)) cout << "YES" << endl;
	if (DP(0, 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
	//clean(n);
}

int main() {
	fastio;
	h['1'] = h['2'] = 0;
	h['3'] = h['4'] = h['5'] = h['6'] = 1;
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}
