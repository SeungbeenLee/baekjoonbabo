#include <iostream>
using namespace std;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i=0;i<num;i++)
    {
        int j=0;
        for (;j<i+1;j++)
            cout << "*";
        for (;j<2*num-1-i;j++)
            cout << " ";
        for (;j<2*num;j++)
            cout << "*";
        cout << "\n";
    }
    for (int i=0;i<num-1;i++)
    {
        int j=0;
        for (;j<num-1-i;j++)
            cout << "*";
        for (;j<num+1+i;j++)
            cout << " ";
        for (;j<2*num;j++)
            cout << "*";
        cout << "\n";
    }
    return (0);
}