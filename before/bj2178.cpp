#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int board[102][102];
int vis[102][102];
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    vis[0][0] = 1;
    Q.push(make_pair(0, 0));

    int N, M;
    cin >> N >> M;
    for (int i=0;i<N;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<M;j++)
            board[i][j] = int(s[j] - '0');
    }
    
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        int nx, ny;
        for (int i=0;i<4;i++)
        {
            nx = cur.X + dx[i];
            ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny >= M || ny < 0) continue;
            if (vis[nx][ny] != 0 || board[nx][ny] == 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push(make_pair(nx,ny));
        }
    }
    cout << vis[N-1][M-1];
}