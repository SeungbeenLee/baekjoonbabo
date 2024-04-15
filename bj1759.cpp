#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char arr[20];
int per[20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0;i<m;i++) cin >> arr[i];
	sort(arr, arr+m);

	for (int i=0;i<n;i++) per[i] = 1;
	do
	{
		for (int i=0;i<m;i++)
			if (per[i] == 1) cout << arr[i];
		cout << '\n';
	} while (prev_permutation(per,per+m));
}