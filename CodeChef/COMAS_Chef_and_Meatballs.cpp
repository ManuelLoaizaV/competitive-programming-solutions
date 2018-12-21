#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
using namespace std;

struct Men {
	int xd;
	int m3;
	int m4;
};

void query(vector<int> &a, int i) {
	cout << "?";
	for (int j = 0; j < 5; j++)
		cout << " " << a[(i + j) % 6];
	cout << endl;
}

void Delete(vector<int> &a, int x){
	int l = a.size();
	for (int i = 0; i < l; i++)
		if (a[i] == x) {
			a.erase(a.begin() + i);
			break;
		}
}

void Delete(vector<Men> &a, int x) {
	int l = a.size();
	for (int i = 0; i < l; i++) {
		if (a[i].xd == x) {
			a.erase(a.begin() + i);
			break;
		}
	}
}

bool check(int i, int j, vector<Men> &a){
	if (i == j) return false;
	if (a[i].m3 == a[j].m3 and a[i].m4 == a[j].m4) return true;
	return false;
}

void solve(){
	int n, x, y;
	cin >> n;
	vector<int> a;
	for (int i = 1; i <= n; i++)
		a.pb(i);
	if (a.size() % 2 != 0) {
		query(a, 0);
		cin >> x >> y;
		Delete(a, x);
	}
	while (a.size() > 6) {
		query(a, 0);
		cin >> x >> y;
		Delete(a, x);
		Delete(a, y);
	}
	vector<Men> answer(6);
	map<int, bool> mrd;
	for (int i = 0; i < 6; i++) {
		query(a, i + 1);
		answer[i].xd = a[i];
		cin >> answer[i].m3;
		cin >> answer[i].m4;
		mrd[answer[i].m3] = true;
		mrd[answer[i].m4] = true;
	}
	std::map<int, bool>::iterator it;
	for (it = mrd.begin(); it != mrd.end(); it++)
		Delete(answer, it->first);
	for (int i = 0; i < 3; i++) {
		bool print = true;
		for (int j = 0; j < 3; j++) 
			if (check(i, j, answer)) {
				print = false;
				break;
			}
		if (print) {
			cout << "! " << answer[i].xd << endl;
			return;
		}
	}	
}

int main(){
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
