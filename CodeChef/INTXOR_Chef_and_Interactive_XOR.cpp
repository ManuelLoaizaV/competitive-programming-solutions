#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

void block4 (int a[], int first, int times) {
	for (int ctmr = 0; ctmr < times; ctmr++) {
		int mrd1, mrd2, mrd3, mrd4, mrd;
		int i = first + 4 * ctmr + 1;
		int j = i + 1;
		int k = j + 1;
		int l = k + 1;
		cout << "1 " << i << " " << j << " " << k << endl;
		cin >> mrd1;
		cout << "1 " << i << " " << j << " " << l << endl;
		cin >> mrd2;
		cout << "1 " << i << " " << k << " " << l << endl;
		cin >> mrd3;
		cout << "1 " << j << " " << k << " " << l << endl;
		cin >> mrd4;
		i--;
		j--;
		k--;
		l--;
		mrd = mrd1 xor mrd2 xor mrd3 xor mrd4;
		a[i] = mrd xor mrd4;
		a[j] = mrd xor mrd3;
		a[k] = mrd xor mrd2;
		a[l] = mrd xor mrd1;
	}
}

void block567 (int a[], int n) {
	int mod = n % 3;
	int ward = n / 3;
	if (mod == 0) {
		int a1a2a3, a1a3a4,a3a5a6,a1a5a6,a2a4a5,a2a4a6;
		cout << "1 1 2 3" << endl;
		cin >> a1a2a3;
		cout << "1 1 3 4" << endl;
		cin >> a1a3a4;
		cout << "1 3 5 6" << endl;
		cin >> a3a5a6;
		cout << "1 1 5 6" << endl;
		cin >> a1a5a6;
		cout << "1 2 4 5" << endl;
		cin >> a2a4a5;
		cout << "1 2 4 6" << endl;
		cin >> a2a4a6;
		int total = a1a2a3 xor a1a3a4 xor a3a5a6 xor a1a5a6 xor a2a4a5 xor a2a4a6;
		int a4a5a6, a2a5a6, a1a2a4, a2a3a4, a1a3a6, a1a3a5;
		a4a5a6 = total xor a1a2a3;
		a2a5a6 = total xor a1a3a4;
		a1a2a4 = total xor a3a5a6;
		a2a3a4 = total xor a1a5a6;
		a1a3a6 = total xor a2a4a5;
		a1a3a5 = total xor a2a4a6;
		a[1] = a1a2a3 xor a1a5a6 xor a3a5a6;
		a[3] = a2a4a5 xor a2a4a6 xor a4a5a6;
		a[4] = a2a4a5 xor a[1] xor a[3];
		a[5] = a2a4a6 xor a[1] xor a[3];
		a[0] = a1a2a4 xor a[1] xor a[3];
		a[2] = a1a3a5 xor a[0] xor a[4];
	} else {
		int trio[n], duo[n];
		for (int xd = 0; xd < n; xd++) {
			int i = xd % n + 1;
			int j = (xd + 1) % n + 1;
			int k = (xd + 2) % n + 1;
			cout << "1 " << i << " " << j << " " << k << endl;
			cin >> trio[xd];
		}
		for (int i = 0; i < n; i++)
			duo[i] = trio[i] xor trio[(i + 1) % n];
		a[0] = a[1] = a[2] = 0;
		if (mod == 1) {
			for (int i = 0; i <= ward; i++)
				a[1] = a[1] xor duo[3 * i];
			for (int i = 0; i < ward; i++)
				a[2] = a[2] xor duo[1 + 3 * i];
			for (int i = 0; i < ward; i++)
				a[0] = a[0] xor duo[2 + 3 * i];
		} else { // mod == 2
			for (int i = 0; i <= ward; i++)
				a[2] = a[2] xor duo[3 * i];
			for (int i = 0; i <= ward; i++)
				a[0] = a[0] xor duo[1 + 3 * i];
			for (int i = 0; i < ward; i++)
				a[1] = a[1] xor duo[2 + 3 * i];
		}
		a[0] = a[0] xor trio[0];
		a[1] = a[1] xor trio[0];
		a[2] = a[2] xor trio[0];
		for (int i = 0; i + 3 < n; i++)
			a[i + 3] = a[i] xor duo[i];
	}
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	int ward = n / 4;
	int mod = n % 4;
	switch (mod) {
		case 0 :
			block4(a, 0, ward);
			break;
		case 1 :
			block567(a, 5);
			block4(a, 5, ward - 1);
			break;
		case 2 :
			block567(a, 6);
			block4(a, 6, ward - 1);
			break;
		case 3 :
			block567(a, 7);
			block4(a, 7, ward - 1);
			break;
	}
	cout << "2";
	for (int i = 0; i < n; i++)
		cout << " " << a[i];
	cout << endl;
	cin >> n;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}