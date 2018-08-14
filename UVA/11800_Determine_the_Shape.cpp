//
// Created by ManuelLoaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

#define Vector Point
const double EPS = 1e-8;
double edgeLenght[4];

struct Point{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double norm2() { return x*x + y*y; }
    double norm() { return sqrt(x*x + y*y); }
    long double argument() { return atan2l(y, x); }
    Point orthogonal() { return Point(-y, x); }
    Point unit() { double k = norm(); return Point(x/k, y/k); }
} points[4];

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
bool operator ==(const Point &a, const Point &b){
    return fabs(a.x - b.x) < EPS and fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b){
    return !(a==b);
}
bool operator <(const Point &a, const Point &b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
double distance(const Point &A, const Point &B) { return hypot(A.x - B.x, A.y - B.y); }
double distance2(const Point &A, const Point &B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
double dot(const Vector &A, const Vector &B) { return A.x * B.x + A.y * B.y; }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
bool isParallel(const Vector &A, const Vector &B) { return cross(A, B) == 0; }
bool counterClockwise(const Point &A, const Point &B) {
    Vector X = A - points[0];
    Vector Y = B - points[0];
    return X.argument() < Y.argument();
}

void solve() {
    for(int i = 0; i < 4; i++) {
        scanf("%lf %lf", &(points[i].x), &(points[i].y));
    }
    sort(points, points + 4);
    sort(points + 1, points + 4, counterClockwise);

    for (int i = 0; i < 4; i++) {
        edgeLenght[i] = distance2(points[i], points[(i + 1) % 4]);
    }

    if (edgeLenght[0] == edgeLenght[1] and edgeLenght[1] == edgeLenght[2] and edgeLenght[2] == edgeLenght[3]) {
        if (dot(points[3] - points[0], points[1] - points[0]) == 0) {
            printf("Square\n");
            return;
        } else {
            printf("Rhombus\n");
            return;
        }
    }

    if (edgeLenght[0] == edgeLenght[2] and edgeLenght[1] == edgeLenght[3]) {
        if (dot(points[3] - points[0], points[1] - points[0]) == 0) {
            printf("Rectangle\n");
            return;
        } else {
            printf("Parallelogram\n");
            return;
        }
    }

    if (isParallel(points[1] - points[0], points[2] - points[3]) or
        isParallel(points[2] - points[1], points[3] - points[0])) {
        printf("Trapezium\n");
        return;
    }

    printf("Ordinary Quadrilateral\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}
