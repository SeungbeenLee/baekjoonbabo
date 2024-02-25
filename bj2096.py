n = int(input())
dp_max = [[0] * 3 for _ in range(n)]
dp_min = [[0] * 3 for _ in range(n)]
for i in range(n):
		values = list(map(int, input().split()))
		dp_max[i] = values.copy()
		dp_min[i] = values.copy()

for i in range(1,n):
	for j in range(3):
		candi = [dp_max[i-1][k] for k in [j-1, j, j+1] if k >= 0 and k <= 2]
		dp_max[i][j] += max(candi)
max = max([dp_max[n-1][m] for m in range(3)])

for i in range(1,n):
	for j in range(3):
		candi = [dp_min[i-1][k] for k in [j-1, j, j+1] if k >= 0 and k <= 2]
		dp_min[i][j] += min(candi)
min = min([dp_min[n-1][m] for m in range(3)])
print(max, min)