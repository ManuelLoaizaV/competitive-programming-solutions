//
// Created by ManuelLoaiza on 04/05/18
//
#include <bits/stdc++.h>

using namespace std;

deque<int> deck;

void inicialize(int n) {
	deck.clear();
	for (int i = 1; i <= n; i++) deck.push_back(i);
}

int main() {
	int n, discardedCards;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		inicialize(n);
		discardedCards = 0;
		printf("Discarded cards:");
		while (deck.size() > 1) {
			if (discardedCards > 0) printf(",");
			printf(" %d", deck.front());
			deck.pop_front();
			discardedCards++;
			deck.push_back(deck.front());
			deck.pop_front();
		}
		printf("\n");
		printf("Remaining card: %d\n", deck.front());
	}
	return 0;
}

