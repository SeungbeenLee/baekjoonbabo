#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    vector<int> ans;
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            Q.push(num);
        }
        else if (s == "pop")
        {
            if (Q.empty()) ans.push_back(-1);
            else
            {
                ans.push_back(Q.front());
                Q.pop();
            }
        }
        else if (s == "size") ans.push_back(Q.size());
        else if (s == "empty") ans.push_back(Q.empty());
        else if (s == "front")
        {
            if (Q.empty()) ans.push_back(-1);
            else ans.push_back(Q.front());
        }
        else if (s == "back")
        {
            if (Q.empty()) ans.push_back(-1);
            else ans.push_back(Q.back());
        }
    }
    for (auto i : ans) cout << i << "\n";
    return (0);
}