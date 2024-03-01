#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);

	vector<int>	arr;
	int	temp, sum = 0;
	for (int i=0;i<9;i++)
	{
		cin >> temp;
		sum += temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i=0;i<9;i++)
	{
		for (int j=i+1;j<9;j++)
		{
			if (sum - (arr[i] + arr[j]) == 100)
			{
				arr.erase(arr.begin() + j); // 앞에 있는 걸 삭제하면 뒤에 있는 거에 영향있느니까 뒤에 있는 걸 먼저 제거
				arr.erase(arr.begin() + i);
				for (int i=0;i<int(arr.size());i++)
					cout << arr[i] << '\n';
				return (0);
			}
		}
	}
	return (0);
}