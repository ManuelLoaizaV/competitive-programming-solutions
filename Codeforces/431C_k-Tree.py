mod = 1000000007
n, k, d = [int(x) for x in raw_input().split()] 
totalDP = []
no_d_DP = []
for i in range (n + 1) :
  totalDP.append(0)
  no_d_DP.append(0)
totalDP[0] = 1
no_d_DP[0] = 1

for u in range (1, n + 1) :
  for edge in range (1, k + 1) :
    v = u - edge
    if v < 0 :
      break
    totalDP[u] = totalDP[u] + totalDP[v]
    if (edge < d) :
      no_d_DP[u] = no_d_DP[u] + no_d_DP[v]

answer = (totalDP[n] - no_d_DP[n]) % mod
print(answer) 