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

const int N = 1e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int freq[N + 5];
bool used[N + 5];
vi pos[N + 5];

int main() {
	fastio;
	int n;
	cin >> n;
	int q[n - 2][3];
	For(i,0,n-2) {
		For(j,0,3) cin >> q[i][j];
		For(j,0,3) freq[q[i][j]]++;
		For(j,0,3) pos[q[i][j]].pb(i);
	}
	vi ans;
	int inicio;
	For(i,1,n+1) if (freq[i] == 1) inicio = i;
	ans.pb(inicio);
	used[inicio] = true;
	// busco el segundo
	int ind = pos[inicio][0];
	For(i,0,3) {
		int men = q[ind][i];
		if (freq[men] == 2) {
			ans.pb(men);
			used[men] = true;
		}
	}
	For(k,0,n-4) {
		For(i,0,3) {
			int men = q[ind][i];
			if (not used[men] and freq[men] == 3) {
				ans.pb(men);
				used[men] = true;
				int len = pos[men].size();
				For(j,0,len) {
					int count = 0;
					For(k,0,3) if (not used[q[pos[men][j]][k]]) count++;
					if (count == 1) {
						ind = pos[men][j];
						break;
					}
				}
			}
		}
	}
	For(i,1,n+1)
		if (not used[i] and freq[i] == 2) {
			ans.pb(i);
			used[i] = true;
			break;
		}
	For(i,1,n+1)
		if (not used[i] and freq[i] == 1) {
			ans.pb(i);
			used[i] = true;
			break;
		}
	For(i,0,n)
		if (i == 0) cout << ans[i];
		else cout << " " << ans[i];
	return 0;
}
