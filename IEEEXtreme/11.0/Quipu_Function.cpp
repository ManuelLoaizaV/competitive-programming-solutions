//
// Created by ManuelLoaiza on 09/15/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e+6;
const int MAX_WIDTH = 1e+5;

bool isPrime[MAX_N + 1];
ll number[MAX_WIDTH + 1];
ll numberOfDivisors[MAX_WIDTH + 1];
vector<ll> primes;

void sieve() {
	for (int i = 0; i <= MAX_N; i++) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MAX_N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= MAX_N; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void segmentedSieve(ll a, ll b) {
	for (ll i = 2; i * i <= b; i++) {
		if (isPrime[i]) primes.push_back(i);
	}
	
	for (ll i = 0; i <= MAX_WIDTH; i++) {
		number[i] = a + i;
		numberOfDivisors[i] = 1;
	}
	
	int l = primes.size();
	for (int i = 0; i < l; i++) {
		ll prime = primes[i];
		ll firstNumber = prime * ceil(1.0 * a / prime);
		for (ll j = firstNumber; j <= b; j += prime) {
			ll k = j - a;
			ll exponent = 0;
			while (number[k] % prime == 0) {
				exponent++;
				number[k] /= prime;
			}
			numberOfDivisors[k] *= (exponent + 1);
		}
	}
	
	for (ll i = a; i <= b; i++) {
		ll j = i - a;
		if (number[j] > 1) numberOfDivisors[j] *= 2;
	}
}

ll quipu(ll a, ll i, ll d) {
	ll answer = numberOfDivisors[i - a];
	ll exponent = 0;
	while (i % d == 0) {
		exponent++;
		i /= d;
	}
	answer = answer / (exponent + 1);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t, a, b, d;
	cin >> t >> a >> b;
	sieve();
	segmentedSieve(a, b);
	while (t--) {
		cin >> d;
		ll answer = 0;
		for (ll i = a; i <= b; i++) answer += quipu(a, i, d);
		cout << answer << endl;	
	}
	return 0;
}
