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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 100;
const ll INF = 1e18;
const ld EPS = 10e-9;
const ll MOD = 1000000007LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll p[2] = {29LL, 31LL};
ll pot[2][N + 1];

void calc() {
	For(i,0,N+1)
		For(j,0,2)
			if (i == 0) pot[j][i] = 1LL;
			else pot[j][i] = (pot[j][i - 1] * p[j]) % MOD;
}

ii Hash(ll a[], int n) {
	ll aux[2];
	For(i,0,2) aux[i] = 0LL;
	For(i,0,n) a[i] += 16LL;
	For(i,0,n)
		For(j,0,2)
			aux[j] = (aux[j] + (a[i] * pot[j][i]) % MOD) % MOD;
	ii ans;
	ans.ff = aux[0];
	ans.ss = aux[1];
	return ans;
}

int main() {
	fastio;
	int n;
	cin >> n;
	ll a[n];
	For(i,0,n) cin >> a[i];
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	// Obtengo las mitades derechas e izquierdas de cada numero
	calc();
	ll l[n], r[n];
	ll lim = 1 << 15;
	For(i,0,n) {
		r[i] = a[i] % lim;
		l[i] = a[i] / lim;
		//debug(l[i]);
		//debug(r[i]);
	}
	// Precalculo los hashes de la derecha
	map<ii, ll> dp;
	For(x,0,lim) {
		ll _r[n];
		For(j,0,n) _r[j] = r[j] xor x;
		ll freq[n];
		For(j,0,n) {
			freq[j] = 0;
			For(k,0,15) {
				if (_r[j] & 1) freq[j]++;
				_r[j] /= 2;
			}
		}
		// Construyo el arreglo de diferencias adyacentes
		ll diff[n - 1];
		For(i,0,n-1) diff[i] = freq[i] - freq[i + 1];
		//For(i,0,n-1) debug(diff[i]);
		ii aux = Hash(diff, n - 1);
		dp[aux] = x;
		//debug(x);
		//debug(aux.ff);
		//debug(aux.ss);
	}
	// Calculo los hashes de la izquierda y si es que existe
	// un hash de la derecha que cumple lo requerido, hago merge de ambas
	// soluciones y escribo esto como respuesta
	std::map<ii, ll>::iterator it;
	For(x,0,lim) {
		ll _l[n];
		For(j,0,n) _l[j] = l[j] xor x;
		ll freq[n];
		For(j,0,n) {
			freq[j] = 0;
			For(k,0,15) {
				if (_l[j] & 1) freq[j]++;
				_l[j] /= 2;
			}
		}
		ll diff[n - 1];
		For(i,0,n-1) diff[i] = freq[i] - freq[i + 1];
		//For(i,0,n-1) debug(diff[i]);
		For(i,0,n-1) diff[i] *= (-1);
		ii busco = Hash(diff, n - 1);
		it = dp.find(busco);
		if (it == dp.end()) continue;
		ll temp = x * lim + dp[busco];
		cout << temp << endl;
		return 0;
	}
	cout << "-1" << endl;
	return 0;
}
