#include <iostream>
#include <algorithm>
using namespace std;

int hell[2000001];
int main (void)
{
	int n, x, cnt = 0;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
		hell[arr[i]] = 1;
	}
	cin >> x;
	for (int i=0;i<n;i++)
	{
		if (arr[i] < x && hell[x-arr[i]])
			cnt+=1;
	}
	cout << cnt/2;
	return (0);
}