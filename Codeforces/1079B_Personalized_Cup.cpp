#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

void solve() {
	string s;
	cin >> s;
	int l = s.size();
	if (l <= 20) {
		cout << "1 " << l << endl;
		cout << s << endl;
		return;
	} 
	int a, b;
	for (a = 2; a <= 5; a++) {
		int aux = l / a;
		if (aux > 20) continue;
		if (l % aux == 0) {
			b = aux;
			cout << a << " " << b << endl;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					cout << s[i * b + j];
				}
				cout << endl;
			}
			return;	
		} else {
			int c = aux + 1;
			if (c > 20) continue;
			int xd = a * c - l;
			cout << a << " " << c << endl;
			string nuevo = "";
			int j = 1;
			for (int i = 0; i < l; i++) {
				if (j % c == 0 and xd > 0) {
					nuevo += '*';
					i--;
					xd--;	
				} else {
					nuevo += s[i];
				}
				j++;
			}
			s = nuevo;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < c; j++) {
					cout << s[i * c + j];
				}
				cout << endl;
			}
			return;	
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}

