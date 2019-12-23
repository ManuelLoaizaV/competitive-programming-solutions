// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

bool check(int c[2][3]) {
	For(i,0,2)
		For(j,0,3)
			if (c[i][j] >= 0) continue;
			else return false;
	return true;
}

void solve() {
	bool ok = false;
	int c[2][3], f[7], d[7];
	For(i,0,2) For(j,0,3) cin >> c[i][j]; // c[i][j] : capacidad del aula j para el subgrupo i
	For(i,0,7) cin >> d[i]; // d[i] : alumnos del tipo i
	For(i,0,d[1]+1) { // i asisten a clases 0 y 1 del subgrupo 1
		For(j,0,d[2]+1) { // j asisten a clases 0 y 2 del subgrupo 1
			int temp[2][3];
			For(i,0,2) For(j,0,3) temp[i][j] = c[i][j];
			// Subgrupo 1
			temp[0][0] -= i;
			temp[0][1] -= i;
			temp[0][0] -= j;
			temp[0][2] -= j;
			// Subgrupo 2
			temp[1][0] -= (d[1] - i);
			temp[1][1] -= (d[1] - i);
			temp[1][0] -= (d[2] - j);
			temp[1][2] -= (d[2] - j);
			if (check(temp)) {
				int n[2]; // n[i] : alumnos del tipo 1 que asistiran al grupo i
				// Subgrupo 1
				n[0] = d[0];
				For(i,0,3) n[0] = min(n[0], temp[0][i]);
				// Subgrupo 2
				n[1] = d[0] - n[0];
				For(i,0,3) n[1] = min(n[1], temp[1][i]);
				if (n[0] + n[1] != d[0]) continue;
				For(i,0,2) For(j,0,3) temp[i][j] -= n[i];
				int m[2]; // m[i]: alumnos que asisten a las clases 1 y 2 del subgrupo i
				// Subgrupo 1
				m[0] = d[4];
				For(i,1,3) m[0] = min(m[0], temp[0][i]);
				// Subgrupo 2
				m[1] = d[4] - m[0];
				For(i,1,3) m[1] = min(m[1], temp[1][i]);
				if (m[0] + m[1] != d[4]) continue;
				For(i,0,2) For(j,1,3) temp[i][j] -= m[i];
				if (temp[0][0] + temp[1][0] >= d[3] and
					temp[0][1] + temp[1][1] >= d[5] and
					temp[0][2] + temp[1][2] >= d[6]) {
					ok = true;
					f[0] = n[0];
					f[1] = i;
					f[2] = j;
					f[3] = min(temp[0][0], d[3]);
					f[4] = m[0];
					f[5] = min(temp[0][1], d[5]);
					f[6] = min(temp[0][2], d[6]);
					break;
				}
			}
		}
		if (ok) break;
	}
	if (ok) For(i,0,7) cout << f[i] << " ";
	else cout << "-1";
	cout << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
