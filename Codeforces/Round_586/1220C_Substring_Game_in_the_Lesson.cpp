#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = int(a); i < int(b); i++)
#define roF(i,a,b) for (int i = int(a); i >= int(b); i--)
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 30;
int tree[N + 10];

int update(int i, int delta) {
	while (i <= N) {
		tree[i] += delta;
		i += (i & -i);
	}
}

int query(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main() {
	fastio;
	string s;
	cin >> s;
	int sz = s.size();
	// si hay letras menores antes que yo, ann gana
	For(k,0,sz) {
		int c = s[k] - 'a' + 1;
		int count = query(c - 1);
		update(c, 1);
		if (count > 0) cout << "Ann" << endl;
		else cout << "Mike" << endl;
	}
	return 0;
}
