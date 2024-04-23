#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[4] = {1,2,3,4};
	for (int i=0;i<4;i++) cout << a[i];
	cout << '\n';
	next_permutation(a, a+3);
	for (int i=0;i<4;i++) cout << a[i];
	cout << '\n';
}