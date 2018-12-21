#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 150000;
int height[MAX_N + 1];
int acc[MAX_N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> height[i];
	for (int i = 1; i <= n; i++) acc[i] = height[i] + acc[i - 1];
	int answer = 1;
	int minSum = acc[k];
	for (int i = 1; i <= n - k + 1; i++) {
		int sum = acc[i + k - 1] - acc[i - 1];
		if (sum < minSum) {
			answer = i;
			minSum = sum;
		} 
	}
	cout << answer << endl;
	return 0;
}