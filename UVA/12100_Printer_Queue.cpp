//
// Created by ManuelLoaiza on 05/14/18
//
#include <bits/stdc++.h>

using namespace std;

int tree[10];

struct Job {
	int priority;
	bool yourJob;
	Job(){}
	Job(int _priority, bool _yourJob) {
		priority = _priority;
		yourJob = _yourJob;
	}
};

struct FenwickTree {
	void update(int i, int delta) {
		while (i <= 9) {
			tree[i] += delta;
			i += (i & - i);
		}
	}
	
	int query(int i) {
		int answer = 0;
		while (i > 0) {
			answer += tree[i];
			i -= (i & - i);
		}
		return answer;
	}
}ft;

void solve() {
	int n, m, aux;
	deque<Job> jobs;
	memset(tree, 0, sizeof(tree));
	cin >> n >> m;
		
	for (int i = 0; i < n; i++) {
		cin >> aux;
		jobs.push_back(Job(aux, false));
		if (i == m) jobs[i].yourJob = true;
		ft.update(aux, 1);
	}
	int answer = 1;
	while (true) {
		int quantity = ft.query(9) - ft.query(jobs[0].priority);
		if (jobs[0].yourJob and quantity == 0) break;
		if (quantity == 0) {
			ft.update(jobs[0].priority, -1);
			jobs.pop_front();
			answer++;
		} else {
			jobs.push_back(jobs[0]);	
			jobs.pop_front();
		}
	}	
	cout << answer << endl;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}
