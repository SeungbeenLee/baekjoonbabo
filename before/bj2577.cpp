#include <iostream>
#include <algorithm>
using namespace std;

int freq[10];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c, mul = 0;
	cin >> a >> b >> c;
	mul = a * b * c;
	while (mul >= 1)
	{
		int	ans;
		ans = mul % 10;
		freq[ans] += 1;
		mul /= 10;
	}
	for (int i=0;i<10;i++)
		cout << freq[i] << "\n";
	return (0);
}