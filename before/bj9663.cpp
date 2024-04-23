#include <iostream>
#include <utility>
using namespace std;

#define x first
#define y second
int num, cnt;
pair<int, int> ans[20];

int ck_pair(pair<int, int> p)
{
    for (int i=0;i<p.x;i++)
    {
        if (p.y == ans[i].y) return (0);
        if (p.x + p.y == ans[i].x + ans[i].y ||
            p.x - p.y == ans[i].x - ans[i].y) return (0);
    }
    return (1);
}

void func(int k)
{
    if (k == num)
    {
        cnt++;
        return ;
    }
    for (int j=0;j<num;j++)
    {
        if (ck_pair(make_pair(k, j)))
        {
            ans[k] = make_pair(k, j);
            func(k+1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    func(0);
    cout << cnt;
}