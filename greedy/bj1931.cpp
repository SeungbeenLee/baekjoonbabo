#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i=0;i<N;i++)
	{
		int x, y;
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	sort(vec.begin(), vec.end(), cmp);
	int time = vec[0].second, cnt = 1, idx = 1;
	while (idx < N)
	{
		if (vec[idx].first >= time)
		{
			time = vec[idx].second;
			cnt++;
		}
		idx++;
	}
	cout << cnt;
}