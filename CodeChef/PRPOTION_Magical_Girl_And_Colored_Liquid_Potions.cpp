//
// Created by ManuelLoaiza on 05/27/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
int R[MAX_N], G[MAX_N], B[MAX_N];

void solve() {
	int r, g, b, m;
	cin >> r >> g >> b >> m;
	for (int i = 0; i < r; i++) cin >> R[i];
	for (int i = 0; i < g; i++) cin >> G[i];
	for (int i = 0; i < b; i++) cin >> B[i];
	while (m--) {
		int maxR = R[0];
		int maxG = G[0];
		int maxB = B[0];
		for (int i = 0; i < r; i++) maxR = max(maxR, R[i]);
		for (int i = 0; i < g; i++) maxG = max(maxG, G[i]);
		for (int i = 0; i < b; i++) maxB = max(maxB, B[i]);
		int maximum = max(maxR, max(maxG, maxB));
		if (maximum == maxR) {
			for (int i = 0; i < r; i++) R[i] /= 2;	
		} else {
			if (maximum == maxG) {
				for (int i = 0; i < g; i++) G[i] /= 2;	
			} else {
				for (int i = 0; i < b; i++) B[i] /= 2;
			}
		}
		
	}
	int answer = 0;
	for (int i = 0; i < r; i++) answer = max(answer, R[i]);
	for (int i = 0; i < g; i++) answer = max(answer, G[i]);
	for (int i = 0; i < b; i++) answer = max(answer, B[i]);
	cout << answer << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
