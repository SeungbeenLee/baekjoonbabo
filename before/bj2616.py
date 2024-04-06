N = int(input())
boxes = list(map(int, input().split()))
boxes[:N]
M = int(input())

dp = [[0]*(N+1) for _ in range(4)]

prefix = [0] * (N+1)
for i in range(1, N+1):
    prefix[i] = prefix[i-1] + boxes[i-1] # boxes의 index 조정 

for i in range(1, 4):
    for j in range(M, N+1):
        dp[i][j] = max(dp[i][j-1], dp[i-1][j-M] + prefix[j] - prefix[j-M])

print(dp[3][N])