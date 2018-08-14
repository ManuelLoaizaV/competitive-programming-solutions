//
// Created by ManuelLoaiza on 05/30/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;
const int ALPH = 26;

int portuguesPrefix[MAX_N][ALPH];
int espaniolSufix[MAX_N][ALPH];
long long notPortuguesBegin[ALPH];
long long notEspaniolEnd[ALPH];
long long portuguesNodes, espaniolNodes;

void initialize() {
	portuguesNodes = 1;
	espaniolNodes = 1;
	memset(portuguesPrefix, 0, sizeof(portuguesPrefix));
	memset(espaniolSufix, 0, sizeof(espaniolSufix));
	memset(notPortuguesBegin, 0, sizeof(notPortuguesBegin));
	memset(notEspaniolEnd, 0, sizeof(notEspaniolEnd));
}

void addPortuguesWord(string &s) {
	int l = s.size();
	int u = 0;
	for (int i = 0; i < l; i++) {
		int c = s[i] - 'a';
		if (portuguesPrefix[u][c] == 0) {
			portuguesPrefix[u][c] = portuguesNodes++;
			if (i > 0) notPortuguesBegin[c]++;
		}
		u = portuguesPrefix[u][c];
	}
}

void addEspaniolWord(string &s) {
	int l = s.size();
	int u = 0;
	for (int i = l - 1; i >= 0; i--) {
		int c = s[i] - 'a';
		if (espaniolSufix[u][c] == 0) {
			espaniolSufix[u][c] = espaniolNodes++;
			if (i < l - 1) notEspaniolEnd[c]++;
		}
		u = espaniolSufix[u][c];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int P, S;
	string word;
	while (cin >> P >> S) {
		if (P == 0 and S == 0) break;
		
		initialize();
		for (int i = 0; i < P; i++) {
			cin >> word;
			addPortuguesWord(word);
		} 
		for (int i = 0; i < S; i++) {
			cin >> word;
			addEspaniolWord(word);
		}
		
		long long answer = (portuguesNodes - 1) * (espaniolNodes - 1);
		for (int i = 0; i < ALPH; i++) {
			answer -= notPortuguesBegin[i] * notEspaniolEnd[i];
		}
		cout << answer << endl;
	}
	return 0;
}
