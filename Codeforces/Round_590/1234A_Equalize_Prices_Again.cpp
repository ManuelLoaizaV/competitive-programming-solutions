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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int a[n];
		int maxi, sum;
		sum = 0;
		For(i,0,n) {
			cin >> a[i];
			sum += a[i];
		}
		maxi = ceil((ld)sum / n);
		cout << maxi << endl;
	}
	return 0;
}
