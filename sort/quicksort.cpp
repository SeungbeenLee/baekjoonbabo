#include <iostream>
using namespace std;

int N;
int arr[1000000];

void	quicksort(int st, int en)
{
	if (en <= st + 1) return ;
	int l = st + 1;
	int r = en - 1;
	int pivot = arr[st];
	while (1)
	{
		while (l <= r && arr[l] <= pivot) l++;
		while (l <= r && arr[r] >= pivot) r--;
		if (l > r) break;
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);
	quicksort(st, r);
	quicksort(r+1, en);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++) cin >> arr[i];
	quicksort(0, N);
	for (int i=0;i<N;i++) cout << arr[i] << ' ';
}