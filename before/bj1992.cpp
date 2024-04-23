#include <iostream>
using namespace std;

int N;
int board[65][65];

bool check(int x, int y, int num)
{
    for (int i=x;i<x+num;i++)
    for (int j=y;j<y+num;j++)
        if (board[x][y] != board[i][j]) return false;
    return true;
}
void func(int x, int y, int num)
{
    if (num == 1)
    {
        cout << board[x][y];
        return ;
    }
    if (check(x,y,num)) cout << board[x][y];
    else
    {
        int n = num/2;
        cout << "(";
        for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            func(x+n*i,y+n*j, n);
        cout << ")";
    }
    return ;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int idx;

    cin >> N;
    cin.ignore();
    for (int i=0;i<N;i++)
    {
        getline(cin, s);
        idx = 0;
        for (int j=0;j<N;j++)
            board[i][j] = s[idx++] - '0';
    }
    func(0, 0, N);
}
