#include <iostream>
using namespace std;

int arr[10001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, num_max = 1;
	cin >> N;
	for (int i=0;i<N;i++)
	{
		int num;
		cin >> num;
		if (num > num_max) num_max = num;
		arr[num]++;
	}
	for (int i=1;i<=num_max;i++)
	{
		if (arr[i] == 0) continue;
		while (arr[i]-- > 0) cout << i << '\n';
	}
}