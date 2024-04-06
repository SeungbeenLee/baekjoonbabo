#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int board[102][102][102]; // board[H][N][M];
int dist[102][102][102];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0 ,-1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<tuple<int,int,int> > Q;
    int N, M, H, zero = 0, ans = 0;
    cin >> M >> N >> H;
    for (int i=0;i<H;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<M;k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 0) zero++;
            }
    for (int i=0;i<H;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<M;k++)
                if (board[i][j][k] == 1)
                {
                    dist[i][j][k] = 1;
                    Q.push(make_tuple(i,j,k));
                }
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for (int i=0;i<6;i++)
        { 
            int nx = get<1>(cur) + dx[i];
            int ny = get<2>(cur) + dy[i];
            int nz = get<0>(cur) + dz[i];
            if (nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H) continue;
            if (board[nz][nx][ny] != 0) continue;
            board[nz][nx][ny] = 1;
            zero--;
            if (dist[nz][nx][ny] == 0) dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            else dist[nz][nx][ny] = min(dist[nz][nx][ny], dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1);
            Q.push(make_tuple(nz,nx,ny));
            ans = max(ans, dist[nz][nx][ny]);
        }
    }
    if (zero == 0)
    {
        if (ans == 0)
            cout << ans;
        else
            cout << (ans-1);
    }
    else
        cout << -1;
}