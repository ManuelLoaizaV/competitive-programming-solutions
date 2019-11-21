// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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

void solve() {
	vector<char> dig;
	For(i,0,10) dig.pb(char('0' + i));
	For(i,0,26) dig.pb(char('a' + i));
	For(i,0,26) dig.pb(char('A' + i));
	int r, c, k;
	cin >> r >> c >> k;
	char ans[r][c];
	string farm[r];
	For(i,0,r) cin >> farm[i];
	int freq[k];
	For(i,0,k) freq[i] = 0;
	int rice = 0;
	For(i,0,r)
		For(j,0,c)
			if (farm[i][j] == 'R') rice++;
	if (rice == 0) {
		int row = 0;
		int col = 0;
		int pollo = 0;
		For(i,0,r*c) {
			ans[row][col] = dig[pollo];
			pollo++;
			if (pollo == k) pollo--;
			if (row % 2 == 0) {
				col++;
				if (col == c) {
					row++;
					col--;
				}
			} else {
				col--;
				if (col < 0) {
					row++;
					col++;
				}
			}
		}
	} else {
		For(i,0,rice) freq[i % k]++;
		int row = 0;
		int col = 0;
		int pollo = 0;
		int count = 0;
		bool ultimo = false;
		For(i,0,r*c) {
			// coloco al pollo
			ans[row][col] = dig[pollo];
			// Si hay arroz, hag modificaciones
			if (farm[row][col] == 'R') {
				count++;
				if (count == freq[pollo]) {
					pollo++;
					count = 0;
				}
				if (pollo == k) {
					pollo = k - 1;
					ultimo = true;
				}
			}
			// Modifico la direccion del movimiento
			if (row % 2 == 0) {
				col++;
				if (col == c) {
					row++;
					col--;
				}
			} else {
				col--;
				if (col < 0) {
					row++;
					col++;
				}
			}
		}
	}
	For(i,0,r) {
		For(j,0,c) cout << ans[i][j];
		cout << endl;
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
