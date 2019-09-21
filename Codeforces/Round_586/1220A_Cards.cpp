#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = int(a); i < int(b); i++)
#define roF(i,a,b) for (int i = int(a); i >= int(b); i--)
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

const int N = 1e6;
int freq[27];

int main() {
	fastio;
	int sz;
	cin >> sz;
	string s;
	cin >> s;
	For(i,0,sz) freq[s[i] - 'a']++;
	int o = 'o' - 'a';
	int n = 'n' - 'a';
	int e = 'e' - 'a';
	int z = 'z' - 'a';
	int r = 'r' - 'a';
	int one = min(freq[o], min(freq[n], freq[e]));
	For(i,0,one) cout << "1 ";
	freq[o] -= one;
	freq[n] -= one;
	freq[e] -= one;
	int zero = min(freq[z], min(freq[e], min(freq[r], freq[o])));
	For(i,0,zero) cout << "0 ";
	return 0;
}
