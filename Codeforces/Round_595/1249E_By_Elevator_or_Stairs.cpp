//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e5;
const ll INF = 1e18;
const ld EPS = 10e-9;
ll dp[N + 5][2];
// dp[i][j]: minimo costo de llegar al piso i de la manera j

int main() {
	fastio;
	int n, c;
	cin >> n >> c;
	ll a[n], b[n];
	For(i,0,n-1) cin >> a[i];
	For(i,0,n-1) cin >> b[i];
	dp[0][0] = 0LL;
	dp[0][1] = INF;
	For(i,1,n) {
		dp[i][0] = a[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = b[i - 1] + min(dp[i - 1][0] + c, dp[i - 1][1]);
	}
	For(i,0,n) cout << min(dp[i][0], dp[i][1]) << " ";
	cout << endl;
	return 0;
}
