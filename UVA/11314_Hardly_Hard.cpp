//
// Created by ManuelLoaiza on 06/07/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ld MAX = 10000.0;
const ld MIN = 0.000000001;

ld dist2(ld ax, ld ay, ld bx, ld by) {
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

void solve() {
	ld ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	
	ld l1 = MIN;
	ld r1 = MAX;
	ld l2 = MIN;
	ld r2 = MAX;
	
	ld perimeter;
	ld ba = sqrt(dist2(bx, by, ax, ay));
	
	while (r1 - l1 > EPS) {
		ld c1 = l1 + (r1 - l1) / 3;
		ld c2 = l1 + (r1 - l1) * 2 / 3;
		
		ld cb1 = sqrt(dist2(0.0, c1, bx, by));
		l2 = MIN;
		r2 = MAX;	
		while (r2 - l2 > EPS) {
			ld m1 = l2 + (r2 - l2) / 3;
			ld m2 = l2 + (r2 - l2) * 2 / 3;
			ld fm1 = sqrt(dist2(m1, 0.0, 0.0, c1)) + sqrt(dist2(m1, 0.0, ax, ay));
			ld fm2 = sqrt(dist2(m2, 0.0, 0.0, c1)) + sqrt(dist2(m2, 0.0, ax, ay));
			if (fm1 >= fm2) l2 = m1;
			else r2 = m2;
		}
		ld d1 = (r2 + l2) / 2;
		ld ad1 = sqrt(dist2(ax, ay, d1, 0.0));
		ld dc1 = sqrt(dist2(d1, 0.0, 0.0, c1));
		ld perimeter1 = ba + ad1 + dc1 + cb1;
		
		ld cb2 = sqrt(dist2(0.0, c2, bx, by));
		l2 = MIN;
		r2 = MAX;	
		while (r2 - l2 > EPS) {
			ld m1 = l2 + (r2 - l2) / 3;
			ld m2 = l2 + (r2 - l2) * 2 / 3;
			ld fd1 = sqrt(dist2(m1, 0.0, 0.0, c2)) + sqrt(dist2(m1, 0.0, ax, ay));
			ld fd2 = sqrt(dist2(m2, 0.0, 0.0, c2)) + sqrt(dist2(m2, 0.0, ax, ay));
			if (fd1 >= fd2) l2 = m1;
			else r2 = m2;
		}
		ld d2 = (r2 + l2) / 2;
		ld ad2 = sqrt(dist2(ax, ay, d2, 0.0));
		ld dc2 = sqrt(dist2(d2, 0.0, 0.0, c2));
		ld perimeter2 = ba + ad2 + dc2 + cb2;
		
		perimeter = min(perimeter1, perimeter2);
		
		if (perimeter1 >= perimeter2) l1 = c1;
		else r1 = c2;
	}
	cout << setprecision(3) << fixed << perimeter << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

