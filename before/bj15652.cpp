#include <iostream>
using namespace std;

int n, m;
int arr[10];
int st = 1;

void func(int k)
{
	if (k == m)
	{
		for (int i=0;i<m;i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	if (k != 0) st = arr[k-1];
	for (int i=st;i<=n;i++)
	{
		arr[k] = i;
		func(k+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
}