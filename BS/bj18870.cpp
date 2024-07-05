#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int         A[1000001];
vector<int> uniq;
int         N;

void    only_unique(void)
{
    for (int i=0;i<N;i++)
        uniq.push_back(A[i]);
    sort(uniq.begin(), uniq.end());
    uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++)
        cin >> A[i];
    only_unique();
    for (int i=0;i<N;i++)
        cout << lower_bound(uniq.begin(), uniq.end(), A[i]) - uniq.begin() << ' ';
}