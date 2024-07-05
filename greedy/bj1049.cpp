#include <iostream>
#include <utility>
using namespace std;

int N, M;
int package[51];
int one[51];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<M;i++)
        cin >> package[i] >> one[i];
    int pm = package[0], om = one[0];
    for (int i=0;i<M;i++)
    {
        if (pm > package[i]) pm = package[i];
        if (om > one[i]) om = one[i];
    }
    int ans = om * N, cnt = 0, tmp = 0;
    while (1)
    {
        if (N < 6 * cnt)
        {
            tmp = pm * cnt;
            if (tmp < ans) ans = tmp;    
            break;
        }
        tmp = pm * cnt + om * (N - (6 * cnt));
        if (tmp < ans) ans = tmp;
        cnt++;
    }
    cout << ans;
}