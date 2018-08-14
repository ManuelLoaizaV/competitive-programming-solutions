//
// Created by ManuelLoaiza on 04/02/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e+3;
bool appeared[MAX_N];

int main() {
	int n, number, answer = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		appeared[number - 1] = true;	
	}
	for (int i = 0; i < n; i++) {
		if (not appeared[i]) answer++;
	}
	printf("%d", answer);
	return 0;
}

