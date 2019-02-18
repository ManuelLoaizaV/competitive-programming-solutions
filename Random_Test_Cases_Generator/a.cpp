#include <algorithm>
#include <iostream>
using namespace std;

int n, a[50000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];

    int sol = sum;
    for (int i = 1; i < n; i++) {
        for (int d = 2; d <= a[i]; d++) {
            if(a[i] % d != 0) continue;
            sol = min(sol, sum-a[0]-a[i] + d*a[0] + a[i]/d);
        }
    }
    cout << sol << endl;
    return 0;
}