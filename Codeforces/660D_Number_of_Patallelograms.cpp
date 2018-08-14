//
// Created by manuelloaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

#define Vector Point
const long double EPS = 1e-8;
const int MAX_N = 2e+3;

struct Point{
    long double x, y;
    Point(){}
    Point(long double a, long double b) { x = a; y = b; }
    long double norm2() { return x*x + y*y; }
    long double norm() { return sqrt(x*x + y*y); }
    long double argument() { return atan2l(y, x); }
    Point orthogonal() { return Point(-y, x); }
    Point unit() { long double k = norm(); return Point(x/k, y/k); }
} points[MAX_N], centers[MAX_N * MAX_N];

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, long double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, long double k) { return Point(a.x*k, a.y*k); }
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
long double distance(const Point &A, const Point &B) { return hypot(A.x - B.x, A.y - B.y); }
long double distance2(const Point &A, const Point &B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
long double dot(const Vector &A, const Vector &B) { return A.x * B.x + A.y * B.y; }
long double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
long double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
bool isParallel(const Vector &A, const Vector &B) { return cross(A, B) == 0; }
bool counterClockwise(const Point &A, const Point &B) {
    Vector X = A - points[0];
    Vector Y = B - points[0];
    return X.argument() < Y.argument();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%Lf %Lf", &(points[i].x), &(points[i].y));
    }
    
    long long answer = 0;
    if (n >= 4) {
        int numberOfCenters = 0;
        Point sum;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                centers[numberOfCenters] = (points[i] + points[j]) / 2.0;
                numberOfCenters++;
            }
        }
        sort(centers, centers + numberOfCenters);
        long long aux = 1;
        for (int i = 1; i < numberOfCenters; i++) {
            if (centers[i] == centers[i - 1]) aux++;
            else {
                answer += (aux * (aux - 1) / 2);
                aux = 1;
            }
        }    
    }
    printf("%lld", answer);
    return 0;
}
