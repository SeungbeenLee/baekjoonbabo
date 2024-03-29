#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int dx[2] = {1,-1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int N, K;
    cin >> N >> K;
    dist[N] = 1;
    Q.push(N);

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for (int i=0;i<3;i++)
        {
            int nx;
            if (i < 2)
                nx = cur + dx[i];
            else
                nx = cur * 2;
            if (nx<0 || nx>100001 || dist[nx]) continue;
            dist[nx] = dist[cur] + 1;
            if (nx == K)
            {
                cout << (dist[K] - 1);
                return (0);
            }
            Q.push(nx);
        }
    }
    cout << 0;
}