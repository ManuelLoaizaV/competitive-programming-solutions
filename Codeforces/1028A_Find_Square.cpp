//
// Created by ManuelLoaiza on 08/28/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string square[n];
	for (int i = 0; i < n; i++) cin >> square[i];
	
	int x, y, count;
	x = y = count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (square[i][j] == 'B') {
				count++;
				x += i;
				y += j;
			}
		}
	}
	
	cout << x / count + 1 << " " << y / count + 1 << endl;
	return 0;
}
