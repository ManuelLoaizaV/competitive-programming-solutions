#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

map <int, int> g;
std::map <int, int>::iterator it;

int binarySearch(int l, int r, int x, vector <pii> &a) {
	if (a[r].first < x) return r;
	if (a[l].first >= x) return l;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (a[mid].first >= x) r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		it = g.find(num);
		if (it != g.end()) g[num]++;
		else g[num] = 1;
	}
	
	vector <int> answer;
	vector <pii> gcd;
	for (it = g.begin(); it != g.end(); it++) {
		gcd.push_back(make_pair(it->first, it->second));
	}
	sort(gcd.begin(), gcd.end());
	int l = gcd.size() - 1;
	while (l >= 0) {
		if (gcd[l].second == 0) {
			l--;
		} else {
			answer.push_back(gcd[l].first);
			gcd[l].second--;
			int count = answer.size() - 1;
			for (int i = count - 1; i >= 0; i--) {
				int gcd_i_j = __gcd(answer[count], answer[i]);
				int index = binarySearch(0, gcd.size() - 1, gcd_i_j, gcd);
				gcd[index].second -= 2;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << answer[i] << " ";
	return 0;
}