#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string digits = "0123456789";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	string answer = s;
	s = s + s;
	for (int i = 0; i < 10; i++) {
		string permutation;
		for (int j = 0; j < 2 * n; j++) {
			permutation += digits[(s[j] - '0' + i) % 10];
		}
		for (int j = 0; j < n; j++) {
			string temp = permutation.substr(j, n);
			if (temp < answer) answer = temp;
		}
	}
	cout << answer << endl;
	return 0;
}