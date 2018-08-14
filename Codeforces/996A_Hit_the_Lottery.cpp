//
// Created by ManuelLoaiza on 06/24/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int answer = 0;
	while (n > 0) {
		if (n >= 100) {
			int aux = n / 100;
			n -= 100 * aux;
			answer += aux;
		} else {
			if (n >= 20) {
				int aux = n / 20;
				n -= 20 * aux;
				answer += aux;
			} else {
				if (n >= 10) {
					int aux = n / 10;
					n -= 10 * aux;
					answer += aux;
				} else {
					if (n >= 5) {
						int aux = n / 5;
						n -= 5 * aux;
						answer += aux;
					} else {
						if (n >= 1) {
							int aux = n / 1;
							n -= 1 * aux;
							answer += aux;
						}	
					}
				}
			}
		}
	}
	
	cout << answer << endl;
	return 0;
}

