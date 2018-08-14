//
// Created by ManuelLoaiza on 05/15/18
//
#include <bits/stdc++.h>

using namespace std;

map<int, bool> elements;

int main() {
	int Q, type, v;
	cin >> Q;
	while (Q--) {
		cin >> type;
		switch (type) {
			case 1 :
				cin >> v;
				elements[v] = 1;
				break;
			case 2 :
				cin >> v;
				elements.erase(v);
				break;
			case 3 :
				cout << elements.begin() -> first << endl;
				break;
		}
	}
	return 0;
}
