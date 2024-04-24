#include <iostream>
using namespace std;

int	arr[1000];
int	tmp[1000];

void	merge(int st, int en)
{
	int mid = (st + en)/2;

	int l = st;
	int r = mid;
	for (int i=st;i<en;i++)
	{
		if (l == mid) tmp[i] = arr[r++];
		else if (r == en) tmp[i] = arr[l++];
		else if (arr[l] <= arr[r]) tmp[i] = arr[l++];
		else tmp[i] = arr[r++];
	}
	for (int i=st;i<en;i++) arr[i] = tmp[i];
}

void	mergesort(int st, int en)
{
	if (en == st + 1) return ;
	int mid = (st + en) / 2;
	mergesort(st, mid);
	mergesort(mid, en);
	merge(st, en);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i=0;i<N;i++) cin >> arr[i];
	mergesort(0, N);
	for (int i=0;i<N;i++) cout << arr[i] << '\n';
}