//
// Created by ManuelLoaiza on 05/27/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
const int mod = 1000000009;

struct Node {
	char color;
	int index;
	Node(){}
	Node(char _color, int _index) {
		color = _color;
		index = _index;
	}
	bool operator < (Node b) const {
		return index < b.index;
	}
} fence[MAX_N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char brush;
		int y;
		cin >> brush >> y;
		fence[i] = Node(brush, y);
	}
	sort(fence, fence + m);
	long long answer = 1;
	for (int  i = 0; i < m - 1; i++) {
		if (fence[i].color != fence[i + 1].color) {
			answer = (answer * (fence[i + 1].index - fence[i].index) % mod) % mod;
		}
	}
	cout << answer << endl;	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
