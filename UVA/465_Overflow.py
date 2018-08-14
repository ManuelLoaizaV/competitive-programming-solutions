#
# Created by ManuelLoaiza on 05/17/18
#
import sys

limit = 2 ** 31 - 1

for line in sys.stdin :
  line = line[:-1]
  print(line)
  a, sign, b = line.split(' ')
  
  a = int(a)
	
  if a > limit :
	  print("first number too big")
	
  b = int(b)
	
  if b > limit :
    print("second number too big")
	
  if sign == '+' :
    result = a + b
  else :
	  result = a * b
	
  if result > limit :
	  print("result too big")
