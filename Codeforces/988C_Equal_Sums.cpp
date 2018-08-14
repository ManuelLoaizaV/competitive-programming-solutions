//
// Created by ManuelLoaiza on 06/01/18
//
#include <bits/stdc++.h>

using namespace std;

struct Tuple {
	int k;
	int ind; 
};

map <long long, vector<Tuple> > answer;
std::map <long long, vector<Tuple> >::iterator it;

int main() {
	int k;
	cin >> k;
	vector <long long> sum(k);
	vector <long long> a[k];
	int n[k];
	for (int i = 0; i < k; i++) {
		cin >> n[i];
		for (int j = 0; j < n[i]; j++) {
			long long x;
			cin >> x;
			a[i].push_back(x);
			sum[i] += a[i][j];
		}
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n[i]; j++) {
			Tuple t;
			t.k = i + 1;
			t.ind = j + 1;
			answer[sum[i] - a[i][j]].push_back(t);
		}
	}
	
	for (it = answer.begin(); it != answer.end(); ++it) {
		int l = (it->second).size();
		for (int i = 1; i < l; i++) {
			if ((it->second)[i].k != (it->second)[0].k) {
				cout << "YES" << endl;
				cout << (it->second)[0].k << " " << (it->second)[0].ind << endl;
				cout << (it->second)[i].k << " " << (it->second)[i].ind << endl;
				return 0;
			}
		}
	}
    cout << "NO" << endl;
	return 0;
}

