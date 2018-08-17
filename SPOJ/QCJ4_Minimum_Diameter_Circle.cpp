//
// Created by ManuelLoaiza on 06/09/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 300;
const ld INF = 1e+9;
const ld MIN = 0.0;
const ld MAX = 1000.0;
const ld EPS = 1e-9;

ld px[MAX_N], py[MAX_N];

ld dist2(ld ax, ld ay, ld bx, ld by) {
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

ld radius(ld cx, ld cy, int n) {
	ld r = 0;
	for (int i = 0; i < n; i++) {
		ld temp = dist2(cx, cy, px[i], py[i]);
		r = max(r, temp);
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0 ; i < n; i++) cin >> px[i] >> py[i];
	
	ld lx, rx, ly, ry, diameter;
	lx = MIN;
	rx = MAX;
	while (rx - lx > EPS) {
		ld m1x = lx + (rx - lx) / 3;
		ld m2x = lx + (rx - lx) * 2 / 3;
		
		ld diameter1 = INF;
		ly = MIN;
		ry = MAX;
		while (ry - ly > EPS) {
			ld m1y = ly + (ry - ly) / 3;
			ld m2y = ly + (ry - ly) * 2 / 3;
			ld radius1 = radius(m1x, m1y, n);
			ld radius2 = radius(m1x, m2y, n);
			if (radius1 >= radius2) ly = m1y;
			else ry = m2y;					
			diameter1 = min(radius1, radius2);
		}
			
		ld diameter2 = INF;
		ly = MIN;
		ry = MAX;
		while (ry - ly > EPS) {
			ld m1y = ly + (ry - ly) / 3;
			ld m2y = ly + (ry - ly) * 2 / 3;
			ld radius1 = radius(m2x, m1y, n);
			ld radius2 = radius(m2x, m2y, n);
			if (radius1 >= radius2) ly = m1y;
			else ry = m2y;					
			diameter2 = min(radius1, radius2);
		}
		
		if (diameter1 >= diameter2) lx = m1x;
		else rx = m2x;
		
		diameter = min(diameter1, diameter2);
	}
	
	diameter = sqrt(diameter) * 2;
	cout << setprecision(2) << fixed << diameter << endl;
	return 0;
}

