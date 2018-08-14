// 
// Created by ManuelLoaiza on 03/29/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	int shower[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> shower[i][j];
		}
	}
	
	int permutations[5] = {0, 1, 2, 3, 4};
	int happiness, maxHappiness = 0;
	do {
		happiness = shower[permutations[0]][permutations[1]] + shower[permutations[1]][permutations[0]] +
					shower[permutations[2]][permutations[3]] + shower[permutations[3]][permutations[2]] +
					shower[permutations[2]][permutations[1]] + shower[permutations[1]][permutations[2]] +
					shower[permutations[3]][permutations[4]] + shower[permutations[4]][permutations[3]] +
					shower[permutations[2]][permutations[3]] + shower[permutations[3]][permutations[2]] + 
					shower[permutations[3]][permutations[4]] + shower[permutations[4]][permutations[3]];
		maxHappiness = max(maxHappiness, happiness);
	} while (next_permutation(permutations, permutations + 5));
	
	cout << maxHappiness << endl;
	return 0;
}

