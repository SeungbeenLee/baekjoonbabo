#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool	cmp(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	else
	{
		int a_sum = 0, b_sum = 0;
		for (int i=0;i<(int)a.length();i++)
			if (isdigit(a[i]))
				a_sum += a[i] - '0';
		for (int i=0;i<(int)b.length();i++)
			if (isdigit(b[i]))
				b_sum += b[i] - '0';
		if (a_sum != b_sum) return a_sum < b_sum;
		else return (a < b);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string>	ans;
	for (int i=0;i<N;i++)
	{
		string str;
		cin >> str;
		ans.push_back(str);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i=0;i<N;i++)
		cout << ans[i] << '\n';
}