#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long Long;
typedef long double Double;

const Long INF = 9223372036854775807LL;
const Double PI = acos(-1);
const int MAX_N = 5e4 + 5;

Long mini(Long a, Long b) {
	if (a < b) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Long n;
	cin >> n;
	Long a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1LL) {
		cout << a[0] << endl;
		return 0;
	}
	sort(a, a + n);
	Long sum = 0LL;
	for (int i = 0; i < n; i++) sum += a[i];
	Long answer = sum;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (a[i] == 1LL) {
				answer = mini(answer, sum);
			} else {
				for (Long j = 2LL; j <= a[i]; j++) {
					if (a[i] % j == 0) {
						Long temp = sum - a[i] - a[1];
						temp += (a[1] * j + a[i] / j);
						answer = mini(answer, temp);
					}
				}
			}
		} else {
			if (a[i] == 1LL) {
				answer = mini(answer, sum);
			} else {
				for (Long j = 2LL; j <= a[i]; j++) {
					if (a[i] % j == 0) {
						Long temp = sum - a[i] - a[0];
						temp += (a[0] * j + a[i] / j);
						answer = mini(answer, temp);
					}
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}