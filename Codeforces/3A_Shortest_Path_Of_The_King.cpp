//
// Created by ManuelLoaiza on 05/24/18
//
#include <bits/stdc++.h>

using namespace std;

struct Position {
	int x;
	int y;
	Position(){}
	Position(int _x, int _y) {
		x = _x;
		y = _y;
	}
	bool operator == (Position b) const {
		return x == b.x and y == b.y;
	}
};

bool isLU(Position k, Position t) {
	return t.x < k.x and t.y > k.y;
}

bool isLD(Position k, Position t) {
	return t.x < k.x and t.y < k.y;
}

bool isRU(Position k, Position t) {
	return t.x > k.x and t.y > k.y;
}

bool isRD(Position k, Position t) {
	return t.x > k.x and t.y < k.y;
}

int main() {
	string king, target;
	cin >> king >> target;
	Position k = Position(king[0] - 'a', king[1] - '0');
	Position t = Position(target[0] - 'a', target[1] - '0');
	
	int answer = 0;
	vector <string> moves;
	while (not (k == t)) {
		answer++;
		if (k.x == t.x) {
			if (k.y < t.y) {
				k.y++;
				moves.push_back("U");
			} else {
				k.y--;
				moves.push_back("D");
			}
		} else {
			if (k.y == t.y) {
				if (k.x < t.x) {
					k.x++;
					moves.push_back("R");
				} else {
					k.x--;
					moves.push_back("L");
				}	
			} else {
				if (isLU(k, t)) {
					k.x--;
					k.y++;
					moves.push_back("LU");
				} else {
					if (isLD(k, t)) {
						k.x--;
						k.y--;
						moves.push_back("LD");
					} else {
						if (isRU(k, t)) {
							k.x++;
							k.y++;
							moves.push_back("RU");
						} else {
							if (isRD(k, t)) {
								k.x++;
								k.y--;
								moves.push_back("RD");	
							}
						}
					}
				}
			}
		}
	}
	
	cout << answer << endl;
	for (int i = 0; i < moves.size(); i++) cout << moves[i] << endl;
	return 0;
}