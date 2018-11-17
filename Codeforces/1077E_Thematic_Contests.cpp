//
// Created by ManuelLoaiza on 11/16/18
//
#include <bits/stdc++.h>
using namespace std;
map<int, int> ward;
std::map<int, int>::iterator it;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int xd;
		cin >> xd;
		ward[xd]++;
	}
	vector<int> freq;
	for (it = ward.begin(); it != ward.end(); it++) freq.push_back(it->second);
	sort(freq.begin(), freq.end());
	int answer = 0;
	int l = freq.size();
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		int problems = i;
		int low = lower_bound(freq.begin(), freq.end(), problems) - freq.begin();
		while (low < l) {
			temp += problems;
			problems *= 2;
			low = lower_bound(freq.begin() + low + 1, freq.end(), problems) - freq.begin();
		}
		answer = max(answer, temp);
	}
	cout << answer << endl;
	return 0;
}
