//
// Created by ManuelLoaiza on 05/24/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50;
vector <int> adj[MAX_N * MAX_N];
string grid[MAX_N];
bool visited[MAX_N * MAX_N];
int letter[MAX_N * MAX_N];
int answer;

void initialize() {
	for (int i = 0; i < MAX_N * MAX_N; i++) {
		adj[i].clear();
		letter[i] = 0;
		visited[i] = false;
	}
	answer = 0;
}

void readLetters(int h) {
	for (int i = 0; i < h; i++) cin >> grid[i];
}

int transformation(int x, int y, int w) {
	return w * x + y;
}

void createGraph(int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int t1 = transformation(i, j, w);
			letter[t1] = grid[i][j] - 'A';
			for (int a = -1; a <= 1; a++) {
				for (int b = -1; b <= 1; b++) {
					int x = i + a;
					int y = j + b;
					if (x >= 0 and y >= 0 and x < h and y < w and (x != i or y != j)) {
						int t2 = transformation(x, y, w);
						adj[t1].push_back(t2);
					}
				}
			}
		}
	}
}

void BFS(int h, int w) {
	deque <int> path;
	for (int i = 0; i < h * w; i++) {
		if (letter[i] == 0) {
			visited[i] = true;
			answer = 1;
			path.push_back(i);
		}
	}
	
	while (not path.empty()) {
		int u = path.front();
		path.pop_front();
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			if (not visited[v] and letter[v] == letter[u] + 1) {
				visited[v] = true;
				answer = max(answer, letter[v] + 1);
				path.push_back(v); 
			}
		}
	}
}

void solve(int h, int w) {
	initialize();
	readLetters(h);
	createGraph(h, w);
	BFS(h, w);
	cout << answer << endl;
}

int main() {
	int h, w;
	int testCase = 0;
	while (cin >> h >> w) {
		if (h == 0 and w == 0) break;
		testCase++;
		cout << "Case " << testCase << ": ";
		solve(h, w);
	}
	return 0;
}
