//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

const int N = 1e5;
const int K = 22;
bool dp[N][K][2][2][2];
bool is_done[N][K][2][2][2];
bool is_palindrome[N];
bool is_lucky[N];

int n, k;
// DP(i, d, who, h1, h2): Es posible configurar a los elementos [i .. n - 1]
// cuando not_who  mas cercano dista d y who dista 1, who es el seleccionado en el anterior paso
// donde h1 significa que el ultimo grupo de palindromos tiene al menos dos miembros
// y h2 significa que el ultimo grupo de palindromos tiene al menos dos miembros.
//
// last {
// 0: palindrome
// 1: lucky
// }
bool DP(int pos, short distance_not_last, bool last_is_lucky, bool has_palindrome_friend, bool has_lucky_friend) {
  if (pos == n) {
    if (has_palindrome_friend && has_lucky_friend) return true;
    return false;
  }
  if (distance_not_last == k + 1) {
    if (last_is_lucky) {
      if (!has_palindrome_friend) return false;
    } else {
      if (!has_lucky_friend) return false;
    }
  }
  if (is_done[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend])
    return dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend];
  dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] = false;
  if (is_palindrome[pos]) {
    if (last_is_lucky) {
      if (distance_not_last == k + 1) {
      	dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
          dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
          DP(pos + 1, 2, false, false, has_lucky_friend);
      } else {
      	dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
          dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
          DP(pos + 1, 2, false, true && pos > 0, has_lucky_friend);
      }
    } else {
      // Si el ultimo era palindromo
      dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
        dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
        DP(pos + 1, min(k + 1, distance_not_last + 1), false, true && pos > 0, has_lucky_friend);
    }
  }
  // Si el actual puede ir a la clase supersticiosa
  if (is_lucky[pos]) {
    if (last_is_lucky) {
      dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
        dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
        DP(pos + 1, min(k + 1, distance_not_last + 1), true && pos > 0, has_palindrome_friend, true);
    } else {
      // Si el ultimo era palindromo
      if (distance_not_last == k + 1) {
      	dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
          dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
          DP(pos + 1, 2, true, has_palindrome_friend, false);	
      } else {
      	dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] =
          dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] |
          DP(pos + 1, 2, true, has_palindrome_friend, true && pos > 0);
      }
    }
  }
  is_done[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend] = true;
  return dp[pos][distance_not_last][last_is_lucky][has_palindrome_friend][has_lucky_friend];
}

bool IsPalindrome(const string& s) {
  int len = s.size();
  for (int i = 0; i < len / 2; i++) if (s[i] != s[len - 1 - i]) return false;
  return true;
}

bool IsLucky(const string& s) {
  int len = s.size();
  for (int i = 0; i < len; i++) if (s[i] != '4' && s[i] != '7') return false;
  return true;
}

void Solve(void) {
  cin >> n >> k;
  string s;
  bool is_valid = true;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (IsPalindrome(s)) is_palindrome[i] = true;
    if (IsLucky(s)) is_lucky[i] = true;
    if (!is_palindrome[i] && !is_lucky[i]) is_valid = false;
  }
  if (!is_valid) {
    cout << "No\n";
    return;
  }
  if (n == 1) {
    cout << "No\n";
    return;
  }
  if (DP(0, k + 1, false, true, true)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

