#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
  
struct Observation { 
    int s, f, d;
}; 
  
bool obsComp(Observation o1, Observation o2) { 
    if (o1.f == o2.f) return o1.s < o2.s;
    return o1.f < o2.f;
}

int latestNonConflict(Observation arr[], int i) { 
    for (int j = i - 1; j >= 0; j--) { 
        if (arr[j].f < arr[i].s) 
            return j; 
    } 
    return -1; 
} 
  
int findMaxDesirability(Observation arr[], int n) {   
    sort(arr, arr + n, obsComp);
    int *table = new int[n]; 
    table[0] = arr[0].d; 
    for (int i = 1; i < n; i++) { 
        int inclD = arr[i].d; 
        int l = latestNonConflict(arr, i); 
        if (l != -1) inclD += table[l];
        table[i] = max(inclD, table[i - 1]); 
    } 
    int result = table[n - 1]; 
    delete[] table;
    return result; 
} 
  
int main() { 
    fastio;
    int n;
    cin >> n;
    Observation a[n];
    for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].f >> a[i].d;
    cout << findMaxDesirability(a, n); 
    return 0; 
} 