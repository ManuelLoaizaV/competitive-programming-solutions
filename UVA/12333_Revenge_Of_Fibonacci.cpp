//
// Created by ManuelLoaiza on 05/31/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_F = 1e+5;
const int ALPH = 10;
const int MAX_N = 5e+6;
const int limit = 41;

int trie[MAX_N][ALPH];
int ind[MAX_N];
int nodes = 1;
string F[3];
string digit = "0123456789";

void addWord(string &s, int n) {
	int l = s.size();
	int u = 0;
	for (int i = 0; i < l; i++) {
		if (i == limit) return;
		int c = s[i] - '0';
		if (trie[u][c] == 0) {
			trie[u][c] = nodes++;
			ind[trie[u][c]] = min(ind[trie[u][c]], n);	
		}
		u = trie[u][c];
	}
}

int isPrefix(string &s) {
	int l = s.size();
	int u = 0;
	for (int i = 0; i < l; i++) {
		int c = s[i] - '0';
		if (trie[u][c] == 0) return -1;
		u = trie[u][c];
	}
	return ind[u];
}

void sum(string &answer, string &a, string &b, int n) {
	answer = "";
	int aSize = a.size();
	int bSize = b.size();
	int carry = 0;
	int d = 0;
	for (int i = aSize - 1; i >= 0; i--) {
		if (i + bSize < aSize) {
			d = a[i] - '0' + carry;
		} else {
			d = a[i] - '0' + b[i - (aSize - bSize)] - '0' + carry;
		}
		if (d >= 10) {
			carry = 1;
			d -= 10;
		} else {
			carry = 0;
		}
		answer += digit[d];
	}
	if (carry > 0) answer += digit[carry];
	reverse(answer.begin(), answer.end());
	addWord(answer, n);
	b = a;
	a = answer;
}

void precalculate() {
	memset(ind, MAX_N, sizeof(ind));
	F[0] = F[1] = "1";
	addWord(F[0], 0);
	addWord(F[1], 1);
	for (int i = 2; i < MAX_F; i++) {
		sum(F[2], F[1], F[0], i);	
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	precalculate();
	int testCases;
	string sequence;
	
	cin >> testCases;
	for (int i = 1; i <= testCases; i++) {
		cin >> sequence;
		cout << "Case #" << i << ": " << isPrefix(sequence) << endl;
	}
	return 0;
}
