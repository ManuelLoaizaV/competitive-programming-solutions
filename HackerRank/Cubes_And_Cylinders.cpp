//
// Created by ManuelLoaiza on 02/23/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_EDGE_LENGHT = 500;
int numberOfCubes[MAX_EDGE_LENGHT + 1];

struct cylinder {
    int radius;
    int capacity;
    bool operator < (cylinder b) const {
        if (radius == b.radius) return capacity < b.capacity;
        return radius < b.radius;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int edge_lenght[n];
    int numberOfCopies[n];
    for (int i = 0; i < n; i++) {
        cin >> edge_lenght[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> numberOfCopies[i];
    }

    cylinder cylinders[m];
    for (int i = 0; i < m; i++) {
        cin >> cylinders[i].radius;
    }
    for (int i = 0; i < m; i++) {
        cin >> cylinders[i].capacity;
    }
    sort(cylinders, cylinders + m);

    for (int i = 0; i < n; i++) {
        numberOfCubes[edge_lenght[i]] += numberOfCopies[i];
    }

    int result = 0;
    int actualEdgeLenght = 0;
    int maxEdgeLenght;
    for (int i = 0; i < m; i++) {
        maxEdgeLenght = 2.0 * cylinders[i].radius / sqrt(2);
        while (true) {
            while (actualEdgeLenght < 501) {
                if (numberOfCubes[actualEdgeLenght] == 0) actualEdgeLenght++;
                else break;
            }
            if (actualEdgeLenght == 501) break;
            if (cylinders[i].capacity == 0) break;
            if (actualEdgeLenght > maxEdgeLenght) break;
            numberOfCubes[actualEdgeLenght]--;
            cylinders[i].capacity--;
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
