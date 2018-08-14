//
// Created by ManuelLoaiza on 05/06/18
//
#include <bits/stdc++.h>

using namespace std;

map <string, int> twoGram;
map <string, int> :: iterator it; 

int main() {
	int n;
	int maxCont = 0;
	string s, aux, answer;
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		aux = s.substr(i, 2);
		it = twoGram.find(aux);
		if (it != twoGram.end()) twoGram[aux]++;
		else twoGram[aux] = 1;
		if (twoGram[aux] > maxCont) {
			maxCont = twoGram[aux];
			answer = aux; 
		}
	}
	cout << answer << endl;
	return 0;
}

