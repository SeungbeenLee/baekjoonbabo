#include <iostream>
#include <algorithm>
using namespace std;

int		n, m;
char	ans[20];
char	arr[20];
int		isused[20];

void func(int k, int before, int cons, int vowel)
{
	if (k == n)
	{
		if (cons < 2 || vowel < 1)
			return ;
		for (int i=0;i<n;i++) cout << ans[i];
		cout << '\n';
		return ;
	}
	for (int i=before;i<m;i++)
	{
		if (!isused[i])
		{
			ans[k] = arr[i];
			isused[i] = 1;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				func(k+1, i, cons, vowel+1);
			else
				func(k+1, i, cons+1, vowel);
			isused[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0;i<m;i++) cin >> arr[i];
	sort(arr, arr+m);
	func(0, 0, 0, 0);
}