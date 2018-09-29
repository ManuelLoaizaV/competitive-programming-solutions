#
# Created by ManuelLoaiza on 09/29/18
#
from sys import stdin, stdout

n = int(stdin.readline())
MAX_N = 10000
dp_0 = []
dp_1 = []
for i in range (0, n + 1) :
    dp_1.append(0)
    dp_0.append(0)

dp_0[1] = 1
dp_1[1] = 1
for i in range(2, n + 1) :
    dp_0[i] = dp_1[i - 1]
    dp_1[i] = dp_1[i - 1] + dp_0[i - 1]
answer = dp_0[n] + dp_1[n]
print(answer)