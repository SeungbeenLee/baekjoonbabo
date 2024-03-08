#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, sum = 0;
	cin >> K;
	stack<int> s;
	for (int i=0;i<K;i++)
	{
		int n;
		cin >> n;
		if (n == 0) s.pop();
		else s.push(n); 
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
}