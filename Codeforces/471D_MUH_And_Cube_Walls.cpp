//
// Created by ManuelLoaiza on 05/29/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+5;
const int hashtag = 1e+9; 

int elephant[MAX_N];
int bearsWall[MAX_N];
int differences[2 * MAX_N + 1];

void fillDifferences(int w, int n) {
	// differences = elephant differences + # + bear's wall differences
	for (int i = 1; i < w; i++) {
		differences[i - 1] = elephant[i] - elephant[i - 1];
	}
	differences[w - 1] = hashtag;
	for (int i = 1; i < n; i++) {
		differences[w - 1 + i] = bearsWall[i] - bearsWall[i - 1];
	}
}

int KMP(int w, int n) {
	int answer = 0;
	vector <int> border(w + n + 1);
	for (int i = 1; i < w + n + 1; i++) {
		int j = border[i - 1];
		while (j > 0 and differences[i] != differences[j]) j = border[j - 1];
		if (differences[i] == differences[j]) j++;
		border[i] = j;
		if (border[i] == w) answer++;
	}
	return answer;
}

int main() {
	int n, w;
	cin	>> n >> w;
	for (int i = 0; i < n; i++) cin >> bearsWall[i];
	for (int i = 0; i < w; i++) cin >> elephant[i];
	
	int answer = 0;
	if (w == 1) answer = n;
	else {
		fillDifferences(w, n);
		answer = KMP(w - 1, n - 1);
	}
	cout << answer << endl;
	return 0;
}

