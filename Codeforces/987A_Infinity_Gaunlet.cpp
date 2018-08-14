//
// Created by ManuelLoaiza on 05/28/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 6;
string gems[MAX_N] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
bool used[MAX_N];

void checkColor(string &s) {
	if (s == "purple") {
		used[0] = true;
		return;
	}
	if (s == "green") {
		used[1] = true;
		return;
	}
	if (s == "blue") {
		used[2] = true;
		return;
	}
	if (s == "orange") {
		used[3] = true;
		return;
	}
	if (s == "red") {
		used[4] = true;
		return;
	}
	if (s == "yellow") {
		used[5] = true;
		return;
	}
}

int main() {
	int n;
	cin >> n;
	int m = MAX_N - n;
	while (n--) {
		string color;
		cin >> color;
		checkColor(color);
	}
	cout << m << endl;
	for (int i = 0; i < MAX_N; i++) {
		if (not used[i]) cout << gems[i] << endl;
	}
	return 0;
}

