#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

struct Men {
	int diff, ind, hat;
};

bool sort1(Men &a, Men &b) {
	return a.diff < b.diff;
}

bool sort2(Men &a, Men &b) {
	return a.ind < b.ind;	
}

void solve() {
	int n;
	cin >> n;
	Men mens[n];
	for (int i = 0; i < n; i++) {
		cin >> mens[i].diff;
		mens[i].ind = i;
	}
	sort(mens, mens + n, sort1);
	bool possible = true;
	int hatType = 1;
	int pos = 0;
	while (pos < n) {
		if (not possible) break;
		int l = n - mens[pos].diff;
		if (pos + l <= n) {
			int key = mens[pos].diff;
			for (int j = 0; j < l; j++) {
				if (mens[pos + j].diff == key) {
					mens[pos + j].hat = hatType;
				} else {
					possible = false;
					break;
				}
			}
			hatType++;
			pos = pos + l;
		} else {
			possible = false;
			break;
		}
	}
	if (possible) {
		cout << "Possible" << endl;
		sort(mens, mens + n, sort2);
		for (int i = 0; i < n; i++)
			cout << mens[i].hat << " ";
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}