#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L;
int max_D = 0, cnt = 0, max_idx = 0;
int P[155];
int D[155];

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> L;
	P[0] = 0;
	for (int i=1;i<=N;i++)
		cin >> P[i];
	sort(P, P+N);
	P[N+1] = L;
	for (int i=0;i<=N;i++)
		D[i] = P[i+1] - P[i];
	while (M > 0)
	{
		for (int i=0;i<=N+cnt;i++)
		{
			if (max_D < D[i])
			{
				max_D = D[i];
				max_idx = i;
			}
		}
		cnt++;
		max_D = int(max_D/2);
		P[N+cnt] = P[max_idx] + max_D;
		sort(P, P+N+cnt+1);
		for (int i=1;i<=N+cnt;i++)
			D[i] = P[i+1] - P[i];
		M--;
	}
	for (int i=0;i<=N+cnt;i++)
		if (max_D < D[i]) max_D = D[i];
	cout << max_D;
}