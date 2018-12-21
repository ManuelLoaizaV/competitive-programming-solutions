#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 100;

string s[MAX_N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int answer = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (s[j].substr(0, i + 1) > s[j + 1].substr(0, i + 1)) {
				answer++;
				for (int k = 0; k < n; k++) s[k][i] = 'a';
			}
		}
	}
	cout << answer << endl;
	return 0;
}