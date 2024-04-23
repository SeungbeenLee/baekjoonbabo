#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, m, idx;
int arr[10];
int num[10];

int ck_dup(int k)
{
    for (int i=0;i<n;i++)
        if (k == num[i]) return (1);
    return (0);
}

void func(int k)
{
    if (k == m)
    {
        for (int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i=0;i<idx;i++)
    {
        arr[k] = num[i];
        func(k+1);
    }

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp;
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        cin >> tmp;
        if (!ck_dup(tmp)) num[idx++] = tmp;
    }
    sort(num, num + idx);
    func(0);
}