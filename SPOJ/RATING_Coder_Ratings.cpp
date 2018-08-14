//
// Created by ManuelLoaiza on 02/06/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_CODERS = 3e+5;
const int MAX = 1e+5;
int tree[MAX + 1], answer[MAX_CODERS];

struct Coder {

    int index;
    int rating1;
    int rating2;

    Coder() {}

    Coder(int x, int y, int z) {
        index = x;
        rating1 = y;
        rating2 = z;
    }

    bool operator < (Coder rival) const {
        if (rating1 == rival.rating1) {
            return rating2 < rival.rating2;
        } else {
            return rating1 < rival.rating1;
        }
    }

} coders[MAX_CODERS];

struct FeinwickTree {
    void update(int i, int delta) {
        while (i <= MAX) {
            tree[i] += delta;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
} ft;

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> coders[i].rating1 >> coders[i].rating2;
        coders[i].index = i;
    }

    sort(coders, coders + N);

    int previousRating1 = 0, previousRating2 = 0;

    for (int i = 0; i < N; i++) {

        answer[coders[i].index] = ft.query(coders[i].rating2);

        if (previousRating1 == coders[i].rating1 and previousRating2 == coders[i].rating2) {
            answer[coders[i].index]--;
        }

        ft.update(coders[i].rating2, 1);
        previousRating1 = coders[i].rating1;
        previousRating2 = coders[i].rating2;
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
