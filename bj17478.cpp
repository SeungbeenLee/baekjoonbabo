#include <iostream>
using namespace std;

void func(int n)
{
    if (n == 0)
    {
        cout << "\"재귀함수가 뭔가요?\"\n" << "\"재귀 함수는 자기 자신을 호출하는 함수라네\"\n" << "라고 답변하였지.";
    }
    cout << "\"재귀함수가 뭔가요?\"\n";
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    func(n-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}