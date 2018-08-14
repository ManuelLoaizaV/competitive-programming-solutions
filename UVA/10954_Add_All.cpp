//
// Created by ManuelLoaiza on 05/15/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	while (cin >> N) {
		if (N == 0) break;
		
		priority_queue <long long> A;
		long long aux;
		for (int i = 0; i < N; i++) {
			cin >> aux;
			A.push(-1 * aux);	
		}
		
		long long answer = 0;
		long long add;
		while (A.size() > 1) {
			add = A.top();
			A.pop();
			add += A.top();
			A.pop();
			A.push(add);
			answer += add;
		}
		
		cout << -1 * answer << endl;
	}
	return 0;
}

