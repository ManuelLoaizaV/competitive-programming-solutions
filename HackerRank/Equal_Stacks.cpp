//
// Created by ManuelLoaiza on 05/13/18
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e+5;
int tower1[MAX_N], tower2[MAX_N], tower3[MAX_N];
int maxHeight[10000001];

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	for (int i = n1 - 1; i >= 0; i--) cin >> tower1[i];
	for (int i = n2 - 1; i >= 0; i--) cin >> tower2[i];
	for (int i = n3 - 1; i >= 0; i--) cin >> tower3[i];
	
	int accumulated = 0;
	for (int i = 0; i < n1; i++) {
	    accumulated += tower1[i];
	    maxHeight[accumulated]++;
	}
	accumulated = 0;
	for (int i = 0; i < n2; i++) {
	    accumulated += tower2[i];
	    maxHeight[accumulated]++;
	}
	accumulated = 0;
	for (int i = 0; i < n3; i++) {
	    accumulated += tower3[i];
	    maxHeight[accumulated]++;
	}
	int answer = 0;
	for (int i = 1; i <= 10000000; i++) {
	    if (maxHeight[i] == 3) answer = i;
	}
	cout << answer << endl;
	return 0;
}
