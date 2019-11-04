#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)

typedef long long ll;
typedef long double Double;
typedef pair<ll, ll> ii;
typedef pair<Double, Double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<dd> vd;

const int N = 1e6;
const ll INF = 1e18;
const Double EPS = 10e-9;

ll dist2(ii a, ii b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

dd IntCirRecHor(ll Y, ii c, ll R, bool derecha) {
	Double d = sqrt((Double)(R * R - (Y - c.y) * (Y - c.y)));
	if (derecha) return mp(c.x + d, Y);
	return mp(c.x - d, Y);
}

dd IntCirRecVer(ll X, ii c, ll R, bool arriba) {
	Double d = sqrt((Double)(R * R - (X - c.x) * (X - c.x)));
	if (arriba) return mp(X, c.y + d);
	return mp(X, c.y - d);
}

dd Vector(dd o, dd a) {
	return mp(a.x - o.x, a.y - o.y);
}

Double dot(dd a, dd b) {
	return a.x * b.x + a.y * b.y;
}

Double norm(dd a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

Double Angulo(dd a, dd o, dd b) {
	dd oa = Vector(o, a);
	dd ob = Vector(o, b);
	return acos(dot(oa, ob) / (norm(oa) * norm(ob)));
}

Double cross(dd a, dd b) {
	return a.x * b.y - a.y * b.x;
}

Double SectorMenosTriangulo(ii c, dd i2, dd i1, Double R) {
	dd c2 = Vector(c, i2);
	dd c1 = Vector(c, i1);
	Double sector = Angulo(i2, c, i1) * R * R / 2.0;
	Double triangulo = abs(cross(c2, c1)) / 2.0;
	return sector - triangulo;
}

Double AreaPoligono(vd puntos) {
	Double ans = 0.0;
	Double x1, y1, x2, y2;
	int len = puntos.size();
	For(i,0,len) {
		x1 = puntos[i].x;
		x2 = puntos[(i + 1) % len].x;
		y1 = puntos[i].y;
		y2 = puntos[(i + 1) % len].y;
		ans += (x1 * y2 - x2 * y1);
	}
	return abs(ans) / 2.0;
}

dd h(ii a) { return mp((Double)a.x, (Double)a.y); }

int main() {
    fastio;
	ii c, A, B;
	ll R;
	cin >> c.x >> c.y >> R >> A.x >> A.y >> B.x >> B.y;
	ll R2 = R * R;
	// Obtendre el extremo superior izquierdo del rectangulo
	// y el extremo inferior derecho del rectangulo
	ii LU, RD;
	LU.x = min(A.x, B.x);
	LU.y = max(A.y, B.y);
	RD.x = max(A.x, B.x);
	RD.y = min(A.y, B.y);
	Double ans = 0.0;
	// Para cada cuadradito unitario que pertenece al rectangulo hallare si tiene interseccion con
	// la circunferencia
	For(i,LU.x,RD.x) {
		roF(j,LU.y, RD.y+1) {
			/*
			Cuadradito actual
			lu:=(i,j)   ru:=(i+1,j)
			ld:=(i,j-1) rd:=(i+1,j-1)
			*/
			ii lu = mp(i, j);
			ii ru = mp(i + 1, j);
			ii ld = mp(i, j - 1);
			ii rd = mp(i + 1, j - 1);
			// Distancias al cuadrado de cada extremo del cuadradito
			ll dlu = dist2(c, lu);
			ll dru = dist2(c, ru);
			ll dld = dist2(c, ld);
			ll drd = dist2(c, rd);
			// si es un cuadradito interior, sumo toda su area
			if (dlu <= R2 and dru <= R2 and dld <= R2 and drd <= R2) {
				ans += 1.0;
				continue;
			}
			// Si es un cuadradito exterior, le doy skip
			if (dlu >= R2 and dru >= R2 and dld >= R2 and drd >= R2) continue;
			
			// Sino estoy en algun caso de intersecci[on entre la circunferencia y los cuadraditos
			vd puntos;
			dd i1, i2;
			// Caso 1
			if (dlu >= R2 and dru >= R2 and dld >= R2 and drd <= R2) {
				i1 = IntCirRecHor(ld.y, c, R, false);
				i2 = IntCirRecVer(rd.x, c, R, true);
				puntos.pb(i1);
				puntos.pb(h(rd));
				puntos.pb(i2);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 2
			if (dlu >= R2 and dru <= R2 and dld >= R2 and drd <= R2) {
				i1 = IntCirRecHor(ld.y, c, R, false);
				i2 = IntCirRecHor(lu.y, c, R, false);
				puntos.pb(h(rd));
				puntos.pb(h(ru));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 3
			if (dlu <= R2 and dru <= R2 and dld >= R2 and drd <= R2) {
				i1 = IntCirRecHor(ld.y, c, R, false);
				i2 = IntCirRecVer(ld.x, c, R, false);
				puntos.pb(h(rd));
				puntos.pb(h(ru));
				puntos.pb(h(lu));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}

			// Caso 4 
			if (dlu >= R2 and dru <= R2 and dld >= R2 and drd >= R2) {
				i1 = IntCirRecVer(rd.x, c, R, false);
				i2 = IntCirRecHor(lu.y, c, R, false);
				puntos.pb(h(ru));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 5
			if (dlu <= R2 and dru <= R2 and dld >= R2 and drd >= R2) {
				i1 = IntCirRecVer(rd.x, c, R, false);
				i2 = IntCirRecVer(ld.x, c, R, false);
				puntos.pb(h(ru));
				puntos.pb(h(lu));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 6
			if (dlu <= R2 and dru <= R2 and dld <= R2 and drd >= R2) {
				i1 = IntCirRecVer(rd.x, c, R, false);
				i2 = IntCirRecHor(ld.y, c, R, true);
				puntos.pb(h(ru));
				puntos.pb(h(lu));
				puntos.pb(h(ld));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}

			// Caso 7
			if (dlu <= R2 and dru >= R2 and dld >= R2 and drd >= R2) {
				i1 = IntCirRecHor(lu.y, c, R, true);
				i2 = IntCirRecVer(lu.x, c, R, false);
				puntos.pb(h(lu));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 8
			if (dlu <= R2 and dru >= R2 and dld <= R2 and drd >= R2) {
				i1 = IntCirRecHor(lu.y, c, R, true);
				i2 = IntCirRecHor(ld.y, c, R, true);
				puntos.pb(h(lu));
				puntos.pb(h(ld));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 9
			if (dlu <= R2 and dru >= R2 and dld <= R2 and drd <= R2) {
				i1 = IntCirRecHor(lu.y, c, R, true);
				i2 = IntCirRecVer(rd.x, c, R, true);
				puntos.pb(h(lu));
				puntos.pb(h(ld));
				puntos.pb(h(rd));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}

			// Caso 10
			if (dlu >= R2 and dru >= R2 and dld <= R2 and drd >= R2) {
				i1 = IntCirRecVer(ld.x, c, R, true);
				i2 = IntCirRecHor(ld.y, c, R, true);
				puntos.pb(h(ld));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 11
			if (dlu >= R2 and dru >= R2 and dld <= R2 and drd <= R2) {
				i1 = IntCirRecVer(ld.x, c, R, true);
				i2 = IntCirRecVer(rd.x, c, R, true);
				puntos.pb(h(ld));
				puntos.pb(h(rd));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
			// Caso 12
			if (dlu >= R2 and dru <= R2 and dld <= R2 and drd <= R2) {
				i1 = IntCirRecVer(ld.x, c, R, true);
				i2 = IntCirRecHor(lu.y, c, R, false);
				puntos.pb(h(ld));
				puntos.pb(h(rd));
				puntos.pb(h(ru));
				puntos.pb(i2);
				puntos.pb(i1);
				ans += (AreaPoligono(puntos) + SectorMenosTriangulo(c, i2, i1, R));
				continue;
			}
		}
	}
	cout << fixed << setprecision(4) << ans << endl;
    return 0;
}
