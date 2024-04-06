#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 영식 30초 -> 10원
    // 만식 60초 -> 15원

    int T_num, T_cp, Y = 0, M = 0;
    cin >> T_num;
    int T[T_num];
    for (int i=0;i<T_num;i++)
        cin >> T[i];

    for (int i=0;i<T_num;i++)
    {
        T_cp = T[i];
        while (1)
        {
            Y += 10;
            T_cp -= 30;
            if (T_cp < 0)
                break;
        }
        T_cp = T[i];
        while (1)
        {
            M += 15;
            T_cp -= 60;
            if (T_cp < 0)
                break;
        }
    }
    if (Y < M)
        cout << "Y " << Y;
    else if (Y > M)
        cout << "M " << M;
    else
        cout << "Y M " << Y; 
}