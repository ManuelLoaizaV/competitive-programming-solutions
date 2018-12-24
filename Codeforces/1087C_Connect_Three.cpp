#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

struct Point {
	int x, y;
	Point(){}
	Point(int a, int b) {
		x = a;
		y = b;
	}
	bool operator < (const Point &xd) const {
		if (x == xd.x) return y < xd.y;
		return x < xd.x;
	}
	void print() {
		cout << x << " " << y << endl;
	}
};

void solve() {
	Point p[3];
	for (int i = 0; i < 3; i++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + 3);
	int minY, maxY;
	for (int i = 0; i < 3; i++) {
		if (i == 0) minY = maxY = p[i].y;
		else {
			minY = min(minY, p[i].y);
			maxY = max(maxY, p[i].y);
		}
	}
	vector<Point> answer;
	for (int y = minY; y <= maxY; y++)
		answer.pb(Point(p[1].x, y));
	for (int x = p[0].x; x < p[1].x; x++)
		answer.pb(Point(x, p[0].y));
	for (int x = p[1].x + 1; x <= p[2].x; x++)
		answer.pb(Point(x, p[2].y));
	int l = answer.size();
	cout << l << endl;
	for (int i = 0; i < l; i++) answer[i].print();
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}