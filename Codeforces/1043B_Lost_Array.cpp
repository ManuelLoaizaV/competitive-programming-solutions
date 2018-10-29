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
	int a[n + 1], x[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> answer;
	for (int k = 1; k <= n; k++) {
		bool possible = true;
		for (int i = 1; i <= k; i++) x[i - 1] = a[i] - a[i - 1];
		for (int i = k; i <= n; i++) {
			int temp = a[i] - a[i - 1];
			if (x[(i - 1) % k] != temp) {
				possible = false;
				break;
			}
		}
		if (possible) answer.push_back(k);
	}
	int l = answer.size();
	cout << l << endl;
	for (int i = 0; i < l; i++) cout << answer[i] << " ";
	return 0;
}
