n = int(input())
dp_max = [0] * 3
dp_min = [0] * 3

values = list(map(int, input().split()))
dp_max = values.copy()
dp_min = values.copy()

for i in range(1, n):
	values = list(map(int, input().split()))
	dp_max_cp = dp_max.copy()
	dp_min_cp = dp_min.copy()
	for j in range(3):
		candi = [dp_max_cp[k] for k in [j-1, j, j+1] if k >= 0 and k <= 2]
		dp_max[j] = max(candi) + values[j]
		candi = [dp_min_cp[k] for k in [j-1, j, j+1] if k >= 0 and k <= 2]
		dp_min[j] = min(candi) + values[j]

print(max(dp_max), min(dp_min))