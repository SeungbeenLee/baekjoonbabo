#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> arr;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int tmp, cnt = 0;
	for (int i=0;i<N;i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}
	int idx = 0;
	while (arr[idx] < K && idx < N - 1)
		idx++;
	while (K > 0)
	{
		if (arr[idx] > K && idx > 0)
		{
			idx--;
			continue;
		}
		K -= arr[idx];
		cnt++;
	}
	cout << cnt;
}