#include <bits/stdc++.h>
using namespace std;
typedef long double Double;

const int MAX_N = 1e6;
int trie[MAX_N + 1][26];
int freq[MAX_N + 1];
int nodes;

void init() {
	for (int i = 0; i < nodes; i++) {
		freq[i] = 0;
		for (int j = 0; j < 26; j++) {
			trie[i][j] = 0;
		}
	}
	nodes = 1;
}

void add_word(string &s) {
	int sz = s.size();
	int u = 0;
	for (int i = 0; i < sz; i++) {
		int v = s[i] - 'a';
		if (trie[u][v] == 0) trie[u][v] = nodes++;
		u = trie[u][v];
		freq[u]++;
	}
}

int keystroke_counting(string &s) {
	int sz = s.size();
	int ret, prev, u;
	ret = prev = u = 0;
	for (int i = 0; i < sz; i++) {
		int v = s[i] - 'a';
		u = trie[u][v];
		if (freq[u] == prev) continue;
		ret++;
		prev = freq[u];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		init();
		string words[n];
		for (int i = 0; i < n; i++) {
			cin >> words[i];
			add_word(words[i]);
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			answer += keystroke_counting(words[i]);
		}
		Double average = (Double) answer / n;
		cout << fixed << setprecision(2) << average << endl;
	}
	return 0;
}