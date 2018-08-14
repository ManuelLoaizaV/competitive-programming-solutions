//
// Created by ManuelLoaiza on 02/27/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e+4;
long long tree[MAX + 1];
long long answer[MAX + 1];

struct FenwickTree {
    void update(int i, long long delta) {
        while (i <= MAX) {
            tree[i] += delta;
            i += (i & -i);
        }
    }
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
} ft;

struct Task {
    long long time;
    int index;
    bool operator < (Task b) const {
        if (time == b.time) return index < b.index;
        return time < b.time;
    }
} tasks[MAX];

int main() {
    long long n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &tasks[i].time);
        tasks[i].index = i + 1;
    }
    sort(tasks, tasks + n);

    int index = 0;
    long long lastTime = 0;
    long long actualTime;
    long long lastSum = 0;
    long long size = n;
    long long count;

    while (index < n) {
        count = 0;
        actualTime = tasks[index].time;
        while (index < n and tasks[index].time == actualTime) {
            answer[tasks[index].index] = lastSum + (actualTime - lastTime - 1) * size + tasks[index].index + ft.query(tasks[index].index) + count;
            ft.update(tasks[index].index, -1);
            index++;
            count++;
        }
        lastSum = lastSum + (actualTime - lastTime) * size;
        size -= count;
        lastTime = actualTime;
    }

    for (int  i = 1; i <= n; i++) {
        printf("%lld\n", answer[i]);
    }
    return 0;
}
