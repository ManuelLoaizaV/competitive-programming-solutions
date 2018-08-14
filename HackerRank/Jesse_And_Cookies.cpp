//
// Created by ManuelLoaiza on 05/15/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k, aux;
	priority_queue <long long> A;
	
	cin >> n >> k;
	k *= -1;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		A.push(-1 * aux);	
	}
	
	int answer = 0;
	long long add;
	while (A.size() > 1) {
		if (A.top() <= k) break;
		add = A.top();
		A.pop();
		add += 2 * A.top();
		A.pop();
		A.push(add);
		answer++;
	}
	
	if (A.top() > k) cout << "-1" << endl;
	else cout << answer << endl;
	
	return 0;
}
