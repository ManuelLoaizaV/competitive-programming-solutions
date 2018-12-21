#include <bits/stdc++.h>
#define debug cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+6;
const int ALPH = 26;
const int INF = 1000000000;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int answer = INF;
	for (int x = 1; x <= n; x++) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			temp += a[i] * (abs(i + 1 - x) + (i) + (x - 1) + (x - 1) + (i) + abs(i + 1 - x));
		}
		answer = min(answer, temp);	
	}
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}