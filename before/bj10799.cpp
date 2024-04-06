#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	stack<int> B;
	int ans = 0;
	for (size_t i=0;i<s.length();i++)
	{
		if (s[i] == '(')
		{
			if (s[i+1] == ')')
			{
				ans += B.size();
				i++;
			}
			else B.push(1);
		}
		else if (s[i] == ')')
		{
			ans++;
			B.pop();
		}
	}
	cout << ans;
}