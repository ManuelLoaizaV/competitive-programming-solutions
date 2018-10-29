//
// Created by ManuelLoaiza on 10/28/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	int elMen;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) elMen = a[i];
		else elMen = max(elMen, a[i]);
	}
	int k = elMen;
	int rival, you;
	while (true) {
		rival = you = 0;
		for (int j = 0; j < n; j++) {
			you += (k - a[j]);
			rival += a[j];
		}
		if (you > rival) break;
		k++;
	}		
	cout << k << endl;
	return 0;
}
