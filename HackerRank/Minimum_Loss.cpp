//
// Created by ManuelLoaiza on 05/20/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+5;

long long minimumLoss = 1e+16;

struct Price {
	long long price;
	int index;
	
	bool operator < (Price &b) const {
		return price < b.price;
	}
} prices[MAX_N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> prices[i].price;
		prices[i].index = i;
	}	
	
	sort(prices, prices + n);
	for (int i = 1; i < n; i++) {
		long long loss = prices[i].price - prices[i - 1].price;
		if (prices[i].index < prices[i - 1].index) minimumLoss = min(minimumLoss, loss);		
	}
	
	cout << minimumLoss << endl;
	return 0;
}
