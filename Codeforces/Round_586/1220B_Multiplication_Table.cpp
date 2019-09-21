#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = int(a); i < int(b); i++)
#define roF(i,a,b) for (int i = int(a); i >= int(b); i--)
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1e3;

int main() {
	fastio;
	ll n;
	cin >> n;
	ll M[n + 5][n + 5];
	For(i,1,n+1)
		For(j,1,n+1)
			cin >> M[i][j];
	ll a[n + 5];
	For(col,3,n+1) a[col] = sqrt(M[1][col] * M[2][col] / M[1][2]);
	a[1] = M[1][3] / a[3];
	a[2] = M[1][2] / a[1];
	For(i,1,n+1) cout << a[i] << " ";
	return 0;
}
