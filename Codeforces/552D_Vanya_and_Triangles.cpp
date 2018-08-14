//
// Created by ManuelLoaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+3;

struct Point{
    double x, y;
    Point operator - (Point &b) const {
        Point answer;
        answer.x = x - b.x;
        answer.y = y - b.y;
        return answer;
    }
} points[MAX_N];

double cross(Point &A, Point &B) { return A.x * B.y - A.y * B.x; }

double area(Point &A, Point &B, Point &C) {
    Point X, Y;
    X = B - A;
    Y = C - A;
    return cross(X, Y);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &(points[i].x), &(points[i].y));
    }
    long long answer = 0;
    if (n > 2) {
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (area(points[i], points[j], points[k]) != 0) answer++;
                }
            }
        }
    }
    printf("%lld", answer);
    return 0;
}
