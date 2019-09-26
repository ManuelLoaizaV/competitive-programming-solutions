#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define Vector Pt
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ld PI = acos(-1);
const ll INF = 1e18;

// La metrica utilizada es el producto interno euclideano en R2
struct Pt {
	ld x, y;
	Pt(){}
	Pt(ld a, ld b) { x = a, y = b; }
	void read() { cin >> x >> y; }
	ld norm() { return sqrt(x * x + y * y); }
	ld norm2() { return x * x + y * y; }
	ld arg() { return atan2(y, x); }
	Pt ort() { return Pt(-y, x); }
	Pt unit() {
		ld k = norm();
		return Pt(x / k, y / k);
	}
};

Pt operator + (const Pt &a, const Pt &b) { return Pt(a.x + b.x, a.y + b.y); }
Pt operator - (const Pt &a, const Pt &b) { return Pt(a.x - b.x, a.y - b.y); }
Pt operator * (const Pt &a, ld k) { return Pt(a.x * k, a.y * k); }
Pt operator / (const Pt &a, ld k) { return Pt(a.x / k, a.y / k); }
bool operator == (const Pt &a, const Pt &b) { return abs(a.x - b.x) < EPS and abs(a.y - b.y) < EPS; }
bool operator != (const Pt &a, const Pt &b) { return !(a == b); }
// a < b : a se encuentra debajo de b, si hay empate, a esta a la izquierda de b
bool operator < (const Pt &a, const Pt &b) {
	if (abs(a.y - b.y) < EPS) return a.x < b.x;
	return a.y < b.y;
}

ld dist(const Pt &a, const Pt &b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
ld cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
ld dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
// Area con signo positivo si es antihorario, negativo si es horario
ld area(const Pt &a, const Pt &b, const Pt &c) { return cross(b - a, c - a); }
