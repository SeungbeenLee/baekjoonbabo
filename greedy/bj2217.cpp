#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int min = 10000;
	for (int i=0;i<N;i++)
		cin >> arr[i];
	sort(arr, arr+N);
	int max = arr[0] * N;
	for (int i=0;i<N;i++)
		if (max < arr[i] * (N - i)) max = arr[i] * (N-i);
	cout << max;
}