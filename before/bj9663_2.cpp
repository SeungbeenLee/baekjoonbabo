#include <iostream>
using namespace std;

int n, cnt = 0;
int isused1[40];
int isused2[40];
int isused3[40];

void func(int k)
{
	if (k == n)
	{
		cnt++;
		return ;
	}
	for (int i=0;i<n;i++)
	{
		if (isused1[i] || isused2[i+k] || isused3[i-k+n-1]) continue;
		isused1[i] = 1;
		isused2[i + k] = 1;
		isused3[i - k + n - 1] = 1;
		func(k+1);
		isused1[i] = 0;
		isused2[i + k] = 0;
		isused3[i - k + n - 1] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << cnt;
}