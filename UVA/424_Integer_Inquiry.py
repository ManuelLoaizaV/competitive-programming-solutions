#
# Created by ManuelLoaiza on 05/17/18
#
import sys

answer = 0

for x in sys.stdin:
  x = int(x)
  if x == 0 :
    break
  answer = answer + x
  
print(answer)
