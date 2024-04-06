#include <iostream>
using namespace std;

void    change_card(int (&card)[20], int start, int end)
{
    int temp;
    int gap = end - start + 1;
    for (int i=0;i<gap/2;i++)
    {
        temp = card[start + i];
        card[start + i] = card[end - i];
        card[end - i] = temp;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int card[20];
    for (int i=0;i<20;i++) card[i] = i+1;

    int start, end;
    for (int i=0;i<10;i++)
    {
        cin >> start >> end;
        start -= 1;
        end -= 1;
        change_card(card, start, end);
    }
    for (int i=0;i<20;i++) cout << card[i] << " ";
    return (0);
}