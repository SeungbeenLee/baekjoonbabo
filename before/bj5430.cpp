#include <iostream>
#include <deque>
#include <sstream>
#include <string>
using namespace std;

void write(const deque<int>& DQ, bool reverse)
{
		cout << '[';
		if (!reverse)
		{
			for (size_t j=0;j<DQ.size();j++)
			{
				cout << DQ[j];
				if (j == DQ.size() - 1)
					break;
				cout << ",";
			}
		}
		else
		{
			for (int j=(int)DQ.size()-1;j>=0;j--)
			{
				cout << DQ[j];
				if (j == 0)
					break;
				cout << ",";
			}
		}
		cout << ']';
		cout << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		string p, X, item;
		int num;
		deque<int> DQ;
		cin >> p;
		cin >> num;
		cin >> X;
		stringstream ss(X);
		while (getline(ss, item, ','))
		{
			if (item.front() == '[')
				item = item.substr(1);
			if (item.back() == ']')
				item = item.substr(0,item.size()-1);
			if (!item.empty())
				DQ.push_back(stoi(item));
		}
		bool reverse = false;
		for(size_t i=0;i<p.length();i++)
		{
			if (DQ.empty())
			{
				cout << "error" << "\n";
				break;
			}
			if (p[i] == 'R') reverse = !reverse;
			else
			{
				if (reverse)
					DQ.pop_back();
				else
					DQ.pop_front();
			}
		}
		if (!DQ.empty()) write(DQ, reverse);
	}
	return (0);
}