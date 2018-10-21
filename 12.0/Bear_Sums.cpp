#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+4;
const int MAX_S = 2000005;
const int add = 1000000;
int a[MAX_N];
vector<int> b;
vector<int> ind[MAX_S];

int search(int number) {
	int answer = lower_bound(ind[number].begin(), ind[number].end(), 0) - ind[number].begin();
	if (answer == ind[number].size()) return -1;
	return ind[number][answer];
}

void initialize() {
	for (int i = 0; i < b.size(); i++) {
		ind[b[i]].clear();
	}
	b.clear();
}

void solve() {
	initialize();
	int sum, n;
	cin >> sum >> n;
	if (n == 0) {
		cout << "!OK" << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ind[a[i]+ add].push_back(i);
		b.push_back(a[i]+add);
	}	
	
	for (int i = 1; i < n; i++) {
		int y = a[i];
		int x = sum - y;
		int pos = search(x + add);
		if (pos != -1 and pos < i) {
			cout << min(x, y) << " " << max(x, y) << "\n";
			return;
		}
	}
	cout<< "!OK" << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}