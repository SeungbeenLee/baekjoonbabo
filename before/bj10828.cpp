#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* 1. 배열 */
/* const int	MX = 100000;
int			dat[MX];
int			pos = 0;

void ft_push(int x)
{
	dat[pos++] = x;
}
int ft_pop()
{
	if (pos > 0)
		return (dat[--pos]);
	else 
		return (-1);
}

int ft_top()
{
	if (pos > 0) return (dat[pos - 1]);
	else return (-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ans;
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int x;
			cin >> x;
			ft_push(x);
		}
		else if (s == "pop") ans.push_back(ft_pop());
		else if (s == "size") ans.push_back(pos);
		else if (s == "empty") ans.push_back(pos > 0 ? 0 : 1);
		else ans.push_back(ft_top());
	}
	for (auto j : ans) cout << j << "\n";
} */

/* 2. STL */
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> stack;
	vector<int> ans;
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (s == "pop")
		{
			if (stack.empty())
				ans.push_back(-1);
			else
			{
				ans.push_back(stack.top());
				stack.pop();
			}
		}
		else if (s == "size") ans.push_back(stack.size());
		else if (s == "empty") ans.push_back(stack.empty());
		else
		{
			if (stack.empty()) ans.push_back(-1);
			else ans.push_back(stack.top());
		}
	}
	for (auto answer : ans) cout << answer << "\n";
}