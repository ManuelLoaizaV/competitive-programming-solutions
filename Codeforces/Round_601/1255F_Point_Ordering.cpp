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
#define mt(a,b,c) mp(a,mp(b,c))
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef pair<int, pair<ll, int>> trio;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll query(int type, int i, int j, int k) {
	cout << type << " " << i << " " << j << " " << k << endl;
	ll input;
	cin >> input;
	return input;
}

bool menor_a_mayor_area(trio &a, trio &b) {
	return a.ss.ff <= b.ss.ff;
}

bool antihorario(trio a, trio b) {
	// Si el signo es diferente, -1 antes, 0 era pivote, 1 despues
	if (a.ss.ss != b.ss.ss) return a.ss.ss < b.ss.ss;
	// Si son de un mismo signo
	// Si son ambos negativos, el que tiene menor area primero
	if (a.ss.ss == -1) return a.ss.ff <= b.ss.ff;
	// Si ambos son positivos, el que tiene mayor area primero
	return a.ss.ff >= b.ss.ff;
}

vi Sort(int ini, int fin, vi puntos) {
	vi ret;
	int sz = puntos.size();
	if (sz == 0) return ret;
	// 2*area del triangulo es proporcional a la distancia de i a la recta que une ini y fin
	vector<trio> punto_area_signo;
	For(i,0,sz) {
		ll doble_area = query(1, ini, fin, puntos[i]);
		punto_area_signo.pb(mt(puntos[i], doble_area, 0));
	}
	sort(all(punto_area_signo), menor_a_mayor_area);
	// Selecciono al mas alejado como un pivote
	int pivote = punto_area_signo[sz - 1].ff;
	// Hallo quienes van antes
	For(i,0,sz-1) punto_area_signo[i].ss.ss = query(2, ini, pivote, punto_area_signo[i].ff);
	sort(all(punto_area_signo), antihorario);
	For(i,0,sz) ret.pb(punto_area_signo[i].ff);
	return ret;
}

int main() {
	fastio;
	int n;
	cin >> n;
	vi left, right;
	// Fijo el a1 y a2 como pivotes para tener una recta que parta al poligono en 2
	For(i,3,n+1) {
		if (query(2, 1, i, 2) == 1) right.pb(i);
		else left.pb(i);
	}
	vi sorted_right = Sort(1, 2, right);
	vi sorted_left = Sort(2, 1, left);
	// Fusiono a1, derecha, a2, izquierda
	vi ans;
	ans.pb(1);
	int sz = sorted_right.size();
	For(i,0,sz) ans.pb(sorted_right[i]);
	ans.pb(2);
	sz = sorted_left.size();
	For(i,0,sz) ans.pb(sorted_left[i]);
	// Chequeo si el sentido era correcto con tres adyacentes, si me sale negativo, invierto todo
	if (query(2, ans[0], ans[1], ans[2]) == -1)
		For(i,0,n/2) swap(ans[i], ans[n - 1 - i]);
	// Imprimo la respuesta
	cout << "0";
	For(i,0,n) cout << " " << ans[i];
	cout << endl;
	return 0;
}
