//
// Created by ManuelLoaiza on 05/14/18
//
#include <bits/stdc++.h>

using namespace std;

map <string, int> code;
std :: map <string, int> :: iterator it;

struct Tuple {
	string number;
	int frequency;
	Tuple() {}
	Tuple (string _number, int _frequency) {
		number = _number;
		frequency = _frequency;
	}
};

vector<Tuple> answer;

int main() {
	string s;
	int n = 0;
	while (cin >> s) {
		it = code.find(s);
		if (it == code.end()) {
			code[s] = n;
			n++;
			answer.push_back(Tuple(s, 0));
		}
		answer[code[s]].frequency++;
	}
	
	for (int i = 0; i < n; i++) {
		cout << answer[i].number << " " << answer[i].frequency << endl;
	}
	return 0;
}
