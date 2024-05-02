#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[50];
int	B[50];

bool cmp(int a, int b)
{
	return (a > b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++) cin >> A[i];
	for (int i=0;i<N;i++) cin >> B[i];
	sort(A, A+N, cmp);
	sort(B, B+N);
	int ans = 0;
	for (int i=0;i<N;i++) ans += A[i] * B[i];
	cout << ans;
}