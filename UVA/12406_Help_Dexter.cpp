//
// Created by ManuelLoaiza on 04/05/18
//
#include <bits/stdc++.h>

using namespace std;

const long long MAX_N = 1e+17;

void solve() {
	int p, q;
	scanf("%d %d", &p, &q);
	
	int permutations = 1 << p;
	int powerOfTwo = 1 << q;
	long long largest = -1;
	long long smallest = MAX_N;
	long long number;
    
	for(int i = 0; i < permutations; i++) {
    	number = 0;
		for(int j = 0; j < p; j++) {
        	if (i & (1 << j)) number = 10 * number + 1;
            else number = 10 * number + 2;
		}
		if (number % powerOfTwo == 0) {
			smallest = min(smallest, number);
			largest = max(largest, number);
	    }
    }
    
    if (smallest == MAX_N and largest == -1) {
    	printf("impossible\n");
		return;	
	}
    if (smallest == largest) {
    	printf("%lld\n", smallest);
		return;	
	}
	printf("%lld %lld\n", smallest, largest);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case %d: ", i);
		solve();
	}
	return 0;
}

