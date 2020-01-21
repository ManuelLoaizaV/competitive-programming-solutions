#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define Vector Punto
using namespace std;

const long double EPS = 1e-9;
const long long INF = 1e9;
const long double PI = acos(-1);

struct Punto {
	long double x, y, z;
	Punto() {}
	Punto(long double _x, long double _y, long double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	void read() { cin >> x >> y >> z; }
	void print() { cout << x << " " << y << " " << z << endl; }
	long double norm() { return sqrt(x * x + y * y + z * z); }
	long double norm2() { return x * x + y * y + z * z; }
	bool operator == (Punto p) { return abs(x - p.x) <= EPS and abs(y - p.y) <= EPS and abs(z - p.z) <= EPS; }
	Punto operator + (Punto p) { return Punto(x + p.x, y + p.y, z + p.z); }
	Punto operator - (Punto p) { return Punto(x - p.x, y - p.y, z - p.z); }
	Punto operator * (long double k) { return Punto(x * k, y * k, z * k); }
	Punto operator / (long double k) { return Punto(x / k, y / k, z / k); }
	long double operator * (Punto p) { return x * p.x + y * p.y + z * p.z; }
	Punto operator ^ (Punto p) { return Punto(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }
	long double angle(Punto p) { return acos(*this * p / (norm() * p.norm())); }
	Punto unit() { return *this / norm(); }
};

long double dist(Punto A, Punto B) { return (B - A).norm(); }

int gauss_jordan(vector<vector<long double>> a, vector<long double> &ans) {
	int n = a.size();
	int m = a[0].size() - 1;
	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m and row < n; col++) {
		int sel = row;
		for (int i = row; i < n; i++) if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
		if (abs(a[sel][col]) < EPS) continue;
		for (int i = col; i <= m; i++) swap(a[sel][i], a[row][i]);
		where[col] = row;
		for (int i = 0; i < n; i++) {
			if (i != row) {
				long double c = a[i][col] / a[row][col];
				for (int j = col; j <= m; j++) a[i][j] -= a[row][j] * c;
			}
		}
		row++;
	}
	ans.assign(m, 0);
	for (int i = 0; i < n; i++) if (where[i] != -1) ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i = 0; i < n; i++) {
		long double sum = 0.0;
		for (int j = 0; j < m; j++) sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > EPS) return 0;
	}
	for (int i = 0; i < m; i++) if (where[i] == -1) return INF;
	return 1;
}

void solve() {
	Vector N;
	Punto A, B, C;
	N.read();
	A.read();
	long double L, h;
	cin >> L >> h;
	Punto H(0.0, 0.0, -h);
	Punto M = A / (-2.0);
	vector<vector<long double>> a;
	vector<long double> ans;
	a.push_back({A.x, A.y, A.z, cos(2 * PI / 3) * L * L / 3.0});
	a.push_back({0.0, A.z, -A.y, sin(2 * PI / 3) * L * L * N.x / (3.0 * N.norm())});
	a.push_back({-A.z, 0.0, A.x, sin(2 * PI / 3) * L * L * N.y / (3.0 * N.norm())});
	gauss_jordan(a, ans);
	B.x = ans[0];
	B.y = ans[1];
	B.z = ans[2];
	C = M * 2.0 - B;
	cout << fixed << setprecision(6);
	cout << dist(A, H) << " " << dist(C, H) << " " << dist(B, H) << endl;
}

int main() {
	freopen("jupiter.in", "r", stdin);
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
