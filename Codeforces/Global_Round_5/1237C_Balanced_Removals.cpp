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

struct Punto {
	int x, y, z, id;
	void read() { cin >> x >> y >> z; }
	bool operator < (const Punto &otro) const {
		if (x == otro.x) {
			if (y == otro.y) {
				return z < otro.z;
			}
			return y < otro.y;
		}
		return x < otro.x;
	}
};

void print(Punto a, Punto b) {
	cout << a.id << " " << b.id << endl;
}

void solve() {
	int n;
	cin >> n;
	Punto p[n];
	For(i,0,n) {
		p[i].read();
		p[i].id = i + 1;
	}
	sort(p, p + n);
	vector<vector<Punto>> plano;
	vector<Punto> aux;
	For(i,0,n) {
		if (i == 0) {
			aux.pb(p[0]);
			plano.pb(aux);
			aux.clear();
		} else {
			int sz = plano.size();
			int x = plano[sz - 1].size();
			if (p[i].x == plano[sz - 1][x - 1].x) plano[sz - 1].pb(p[i]);
			else {
				aux.pb(p[i]);
				plano.pb(aux);
				aux.clear();
			}
		}
	}
	// Puntos sin matchear en una plano
	deque<Punto> pendiente_plano;
	// Para cada plano
	int planos = plano.size();
	//debug(planos);
	For(i,0,planos) {
		//debug(i);
		vector<vector<Punto>> recta;
		// Puntos sin matchear en una recta en ese plano
		deque<Punto> pendiente_recta;
		int sz_plano = plano[i].size();
		//debug(sz_plano);
		// Para cada punto en el plano
		For(j,0,sz_plano) {
			//debug(j);
			if (j == 0) {
				aux.pb(plano[i][0]);
				recta.pb(aux);
				aux.clear();
			} else {
				int sz = recta.size();
				int y = recta[sz - 1].size();
				if (plano[i][j].y == recta[sz - 1][y - 1].y) recta[sz - 1].pb(plano[i][j]);
				else {
					aux.pb(plano[i][j]);
					recta.pb(aux);
					aux.clear();
				}
			}
		}
		// Para cada recta
		int rectas = recta.size();
		//debug(rectas);
		For(j,0,rectas) {
			//debug(j);
			int sz_recta = recta[j].size();
			//debug(sz_recta);
			For(k,0,sz_recta) {
				//debug(k);
				if (k == sz_recta - 1) pendiente_recta.pb(recta[j][k]);
				else {
					print(recta[j][k], recta[j][k + 1]);
					k++;
				}
			}
		}
		// Matcheo los pendientes de las rectas
		while (pendiente_recta.size() > 1) {
			int sz = pendiente_recta.size();
			print(pendiente_recta[sz - 1], pendiente_recta[sz - 2]);
			pendiente_recta.pop_back();
			pendiente_recta.pop_back();
		}
		while (pendiente_recta.size() > 0) {
			int sz = pendiente_recta.size();
			pendiente_plano.pb(pendiente_recta[sz - 1]);
			pendiente_recta.pop_back();
		}
	}
	while (pendiente_plano.size() > 0) {
		int sz = pendiente_plano.size();
		print(pendiente_plano[sz - 1], pendiente_plano[sz - 2]);
		pendiente_plano.pop_back();
		pendiente_plano.pop_back();
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
