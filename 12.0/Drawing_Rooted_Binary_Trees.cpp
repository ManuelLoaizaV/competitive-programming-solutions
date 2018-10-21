#include <bits/stdc++.h>
using namespace std;

const int alph = 26;
int h[alph];
string infix, prefix;
char answer[alph][alph];

void initialize() {
	for (int i = 0; i < alph; i++) {
		h[i] = 0;
	}
	for (int i = 0; i < alph; i++) {
		for (int j = 0; j < alph; j++) {
			answer[i][j] = ' ';
		}
	}
}

void solve() {
	initialize();
	int l = prefix.size();
	int answerH = 0;
	for (int i = 0; i < l; i++) {
		char node = prefix[i];
		for (int j = 0; j < l; j++) {
			if (infix[j] == node) {
				int left = -1;
				int right = -1;
				for (int u = j - 1; u >= 0; u--) {
					if (h[u] != 0) {
						left = u;
						break;
					}
				}
				for (int v = j + 1; v < l; v++) {
					if (h[v] != 0) {
						right = v;
						break;
					}
				}
				int actualH = 0;
				if (0 <= left and left < l) actualH = max(actualH, h[left]);
				if (0 <= right and right < l) actualH = max(actualH, h[right]);
				h[j] = actualH + 1;
				answerH = max(answerH, h[j]);
				answer[j][actualH] = node; 
				break;
			}
		}
	}
	for (int i = 0; i < answerH; i++) {
		for (int j = 0; j < l; j++) {
			cout << answer[j][i];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> infix >> prefix) solve();
	return 0;
}
