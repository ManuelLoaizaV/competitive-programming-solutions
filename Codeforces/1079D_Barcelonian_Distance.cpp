#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define For(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
const ll INF = 9223372036854775807;

struct Point {
	ld x, y;
	Point() {}
	Point(ld _x, ld _y) {
		x = _x;
		y = _y;
	}
};

ld dist(Point A, Point B) {
	return (ld) sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void solve() {
	// ax + by + c = 0
	ld a, b, c;
	ld answer = (ld) INF; 
	Point A, B;
	cin >> a >> b >> c;
	cin >> A.x >> A.y >> B.x >> B.y;
	if (A.x == B.x) {
		answer = abs(A.y - B.y);
	} else {
		if (A.y == B.y) {
			answer = (ld) abs(A.x - B.x);
		} else {
			answer = (ld) abs(A.x - B.x) + abs(A.y - B.y);
			if (a != 0 and b != 0) {
				Point A1 = Point(A.x, ((ld)-1.0) * (c + a * A.x) / b);
				Point A2 = Point(((ld)-1.0) * (c + b * A.y) / a, A.y);
				Point B1 = Point(B.x, ((ld)-1.0) * (c + a * B.x) / b);
				Point B2 = Point(((ld)-1.0) * (c + b * B.y) / a, B.y);
				ld d1, d2, d3, d4;
				d1 = dist(A, A1) + dist(A1, B1) + dist(B1, B);
				d2 = dist(A, A1) + dist(A1, B2) + dist(B2, B);
				d3 = dist(A, A2) + dist(A2, B1) + dist(B1, B);
				d4 = dist(A, A2) + dist(A2, B2) + dist(B2, B);
				answer = min(answer, min(d1, min(d2, min(d3, d4))));
			}
		}
	}
	cout << fixed << setprecision(10) << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
