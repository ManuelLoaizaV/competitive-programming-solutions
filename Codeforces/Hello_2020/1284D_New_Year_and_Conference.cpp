// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 400001;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int t[4 * N], lazy[4 * N];

void init() {
	For(i,0,4*N) {
		t[i] = 0;
		lazy[i] = 0;
	}
}

void push(int v) {
    t[2 * v] += lazy[v];
    lazy[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += add;
        lazy[v] += add;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), add);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && tr == r) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

struct Lecture {
	pair<int, int> a, b;
};

bool creciente_l_a(Lecture a, Lecture b) {
	if (a.a.x == b.a.x) return a.a.y < b.a.y;
	return a.a.x < b.a.x;
}

bool creciente_r_a(Lecture a, Lecture b) {
	if (a.a.y == b.a.y) return a.a.x < b.a.x;;
	return a.a.y < b.a.y;
}

bool creciente_l_b(Lecture a, Lecture b) {
	if (a.b.x == b.b.x) return a.b.y < b.b.y;
	return a.b.x < b.b.x;
}

bool creciente_r_b(Lecture a, Lecture b) {
	if (a.b.y == b.b.y) return a.b.x < b.b.x;
	return a.b.y < b.b.y;
}

// busco la primera posicion en la cual los elementos superan al segundo
int search1(int t, int l, int r, Lecture A[]) {
	if (A[l].a.x > t) return l;
	if (A[r].a.x <= t) return -1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (A[m].a.x > t) r = m;
		else l = m;
	}
	if (A[l].a.x > t) return l;
	return r;
}

int search2(int t, int l, int r, Lecture A[]) {
	if (A[l].b.x > t) return l;
	if (A[r].b.x <= t) return -1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (A[m].b.x > t) r = m;
		else l = m;
	}
	if (A[l].b.x > t) return l;
	return r;
}

void solve() {
	int n;
	scanf("%d", &n);
	ii a[n], b[n];
	For(i,0,n) scanf("%d %d %d %d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
	unordered_set<int> uni;
	For(i,0,n) {
		uni.insert(a[i].x);
		uni.insert(a[i].y);
		uni.insert(b[i].x);
		uni.insert(b[i].y);
	}
	std::unordered_set<int>::iterator it;
	vector<int> mens;
	for (it = uni.begin(); it != uni.end(); it++) mens.pb(*it);
	sort(all(mens));
	map<int, int> h;
	int sz = mens.size();
	For(i,0,sz) h[mens[i]] = i + 1;
	For(i,0,n) {
		a[i].x = h[a[i].x];
		a[i].y = h[a[i].y];
		b[i].x = h[b[i].x];
		b[i].y = h[b[i].y];
	}
	Lecture A[n], B[n];
	For(i,0,n) {
		A[i].a = a[i];
		A[i].b = b[i];
		B[i] = A[i];
	}
	// Comenzando por la avenida a
	sort(A, A + n, creciente_l_a);
	sort(B, B + n, creciente_r_a);
	int prev = n;
	roF(i,n-1,0) {
		int pos_aux = search1(B[i].a.y, 0, n - 1, A);
		if (pos_aux == -1) continue;
		if (pos_aux == prev) continue;
		roF(j,prev-1,pos_aux) update(1, 1, sz, A[j].b.x, A[j].b.y, 1);
		int count = query(1, 1, sz, B[i].a.x, B[i].a.y);
		if (count > 0) {
			printf("NO\n");
			return;
		}
	}
	// Comenzando por la avenida b
	init();
	sort(A, A + n, creciente_l_b);
	sort(B, B + n, creciente_r_b);
	prev = n;
	roF(i,n-1,0) {
		int pos_aux = search2(B[i].b.y, 0, n - 1, A);
		if (pos_aux == -1) continue;
		if (pos_aux == prev) continue;
		roF(j,prev-1,pos_aux) update(1, 1, sz, A[j].a.x, A[j].a.y, 1);
		int count = query(1, 1, sz, B[i].a.x, B[i].a.y);
		if (count > 0) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
