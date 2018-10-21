#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef long long int ll;

int main() {
	fastio;
	int n,m,s;
	cin >> n >> m >> s;
	int r = 1;
	int a = 0;
	while (r < n) {
		r *= 2;
		a++;
	}
	cout << m * (n - 1) + a * s;
	return 0;
}