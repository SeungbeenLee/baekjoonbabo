#include <iostream>
#include <algorithm>
using namespace std;

int	func2(int arr[], int N)
{
	int freq[101];
	fill(freq, freq+101, 0);
	for (int i=0;i<N;i++)
	{
		if (freq[100-arr[i]])
			return (1);
		freq[arr[i]] = 1;
	}
	return (0);
}
int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr1[] = {1,52,48};
	cout << func2(arr1, 3) << "\n";
	int arr2[] = {50,42};
	cout << func2(arr2, 2) << "\n";
	int arr3[] = {4, 13, 63, 87};
	cout << func2(arr3, 4) << "\n";
	return (0);
}