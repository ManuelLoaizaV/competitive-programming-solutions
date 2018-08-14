#
# Created by ManuelLoaiza on 01/03/18
#
import sys

for line in sys.stdin:
	n, a = line.split(' ')
	n = int(n)
	a = int(a)
	answer = 0
	for i in range (1, n + 1):
		answer += i * (a ** i)
	print(answer)
