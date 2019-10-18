#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i =a ; i >= b; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int  N = 1e5;
const ll INF = 1e18;
const ld EPS = 1e-9;

void solve() {
	ll n, k;
	cin >> n >> k;
	int A[n];
	For(i,0,n) cin >> A[i];
	ll period = 3LL * n;
	ll _k = k % period;
	For(i,0,_k) {
		int a = A[i % n];
		int b = A[n - 1 - (i % n)];
		A[i % n] = a xor b;
	}
	if (n % 2 != 0 and k > n / 2) A[n / 2] = 0;
	For(i,0,n) cout << A[i] << " ";
	cout << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
