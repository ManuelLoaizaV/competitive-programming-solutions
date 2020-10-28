#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

bool IsValid(vector<vector<int>>& board, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += board[n - 1 - i][i];
  }

  int temp = 0;
  for (int i = 0; i < n; i++) {
    temp += board[i][i];
  }
  if (temp != sum) return false;

  for (int row = 0; row < n; row++) {
    temp = 0;
    for (int col = 0; col < n; col++) {
      temp += board[row][col];
    }
    if (temp != sum) return false;
  }

  for (int col = 0; col < n; col++) {
    temp = 0;
    for (int row = 0; row < n; row++) {
      temp += board[row][col];
    }
    if (temp != sum) return false;
  }

  return true;
}

int main(void) {
  FAST_IO;
  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));

  pair<int, int> empty_cell;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {
        empty_cell.first = i;
        empty_cell.second = j;
      } 
    }
  }

  for (int value = 1; value <= 1000; value++) {
    board[empty_cell.first][empty_cell.second] = value;
    if (IsValid(board, n)) {
      cout << value << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
