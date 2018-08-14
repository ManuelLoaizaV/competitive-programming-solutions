#
# Created by ManuelLoaiza on 03/01/18
#
import sys

f = []
f.append(0)
f.append(1)
for i in range (2, 5001):
    f.append(f[i - 1] + f[i - 2])

for n in sys.stdin:
    n = int(n)
    print("The Fibonacci number for %d is %d" % (n, f[n]))