#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	ll x;
	ll y;
};

ll boardSize, numberOfPlayers, numberOfSnakes, numberOfLadders, K;
map<ll, ll> snakes;
map<ll, ll> ladders;
std::map<ll, ll>::iterator itSnakes;
std::map<ll, ll>::iterator itLadders;

ll transform(point p) {
	ll answer = (p.y - 1) * boardSize;
	if (p.y % 2 == 0) answer += (boardSize - p.x + 1);
	else answer += p.x;
	return answer;
}

void printTransformation(ll position) {
	if (position == 0) {
		cout << "0 1" << endl;
		return;
	}
	ll y = (position - 1) / boardSize + 1;
	ll x = position % boardSize;
	if (y % 2 == 0) x = boardSize - x + 1;
	else if (x == 0) x = boardSize;
	cout << x << " " << y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> boardSize >> numberOfPlayers >> numberOfSnakes;
	ll playerPosition[numberOfPlayers];
	for (int i = 0; i < numberOfPlayers; i++) playerPosition[i] = 0;
	// S lines, for each snake head towards snake tail
	for (int i = 0; i < numberOfSnakes; i++) {
		point head, tail;
		cin >> head.x >> head.y;
		cin >> tail.x >> tail.y;
		ll headPosition = transform(head);
		ll tailPosition = transform(tail);
		snakes[headPosition] = tailPosition;
	}
	cin >> numberOfLadders;
	// L lines, for each ladder start towards ladder end
	for (int i = 0; i < numberOfLadders; i++) {
		point start, end;
		cin >> start.x >> start.y;
		cin >> end.x >> end.y;
		ll startPosition = transform(start);
		ll endPosition = transform(end);
		ladders[startPosition] = endPosition;
	}
	cin >> K;
	ll actualPlayer = 0;
	ll winners = 0;
	for (int i = 0; i < K; i++) {
		if (winners == numberOfPlayers) break;
		while (playerPosition[actualPlayer] > boardSize * boardSize) {
			actualPlayer++;
			actualPlayer = (actualPlayer ) % numberOfPlayers;
		}
		point dice;
		cin >> dice.x >> dice.y;
		ll move = dice.x + dice.y;
		playerPosition[actualPlayer] += move;
		itSnakes = snakes.find(playerPosition[actualPlayer]);
		itLadders = ladders.find(playerPosition[actualPlayer]);
		vector<ll> snakeChanges;
		vector<ll> ladderChanges;
		while (itSnakes != snakes.end() or itLadders != ladders.end()) {
			if (itSnakes != snakes.end()) {
				snakeChanges.push_back(playerPosition[actualPlayer]);
				playerPosition[actualPlayer] = snakes[playerPosition[actualPlayer]];
			} else {
				ladderChanges.push_back(playerPosition[actualPlayer]);
				playerPosition[actualPlayer] = ladders[playerPosition[actualPlayer]];
			}
			itSnakes = snakes.find(playerPosition[actualPlayer]);
			itLadders = ladders.find(playerPosition[actualPlayer]);
		}
		for (int i = 0; i < snakeChanges.size(); i++) snakes[snakeChanges[i]] = playerPosition[actualPlayer];
		for (int i = 0; i < ladderChanges.size(); i++) ladders[ladderChanges[i]] = playerPosition[actualPlayer];
		if (playerPosition[actualPlayer] > boardSize * boardSize) winners++;
		actualPlayer = (actualPlayer + 1) % numberOfPlayers;
	}

	for (int i = 0; i < numberOfPlayers; i++) {
		cout << i + 1 << " ";
		if (playerPosition[i] > boardSize * boardSize) cout << "winner";
		else printTransformation(playerPosition[i]);
		cout << endl;
	}
	return 0;
}