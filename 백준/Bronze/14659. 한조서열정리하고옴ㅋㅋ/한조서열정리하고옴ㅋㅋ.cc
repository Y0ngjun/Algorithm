#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N + 2);
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    v[0] = 100002;
    v[N + 1] = 100001;

    stack<int> stk;
    stk.push(0);

    int answer = 0;

    for (int i = 1; i <= N + 1; i++)
    {
        while (v[stk.top()] < v[i])
        {
            int kill = i - stk.top() - 1;
            answer = max(answer, kill);
            stk.pop();
        }

        stk.push(i);
    }

    cout << answer;

    return 0;
}
