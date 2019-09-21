#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int INF = 1e9;
int steps[2 * N + 5];
int found[2 * N + 5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int maxi = 0;
	for (int i = 0; i < n; i++) maxi = max(maxi, a[i]);
	// construimos todos los numeros a los cuales puedo bajar y a los cuales puedo subir
	for (int i = 0; i < n; i++) {
		int curr = a[i];
		int time = 0;
		while (curr <= 2 * maxi) {
			steps[curr] += time;
			found[curr]++;
			time++;
			curr *= 2;
		}
		time = 0;
		curr = a[i];
		bool fromEven = true;
		while (curr >= 1) {
			if (not fromEven) {
				int new_curr = curr * 2;
				int new_time = time + 1;
				while (new_curr <= 2 * maxi) {
					steps[new_curr] += new_time;
					found[new_curr]++;
					new_time++;
					new_curr *= 2;
				}
			}
			if (curr % 2 == 0) fromEven = true;
			else fromEven = false;
			steps[curr] += time;
			found[curr]++;
			time++;
			curr /= 2;
		}
		found[a[i]]--;
	}
	int ans = INF;
	int aux = a[0];
	while(aux <= 2 * maxi) {
		if (found[aux] >= n) ans = min(ans, steps[aux]);
		aux *= 2;
	}
	aux = a[0];
	bool fromEven = true;
	while (aux >= 1) {
		if (not fromEven) {
			int new_aux = aux * 2;
			while (new_aux <= 2 * maxi) {
				if (found[new_aux] >= n) ans = min(ans, steps[new_aux]);
				new_aux *= 2;
			}
		}
		if (found[aux] >= n) ans = min(ans, steps[aux]);
		if (aux % 2 == 0) fromEven = true;
		else fromEven = false;
		aux /= 2;
	}
	cout << ans << endl;
	return 0;
}
