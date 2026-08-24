#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    vector<int> temp = priorities;
    sort(temp.rbegin(), temp.rend());

    queue<pair<int, int>> q;
    int l = 0;
    for (int num : priorities)
    {
        q.push({ l++, num });
    }

    int cnt = 0;
    while (!q.empty())
    {
        auto [loc, num] = q.front();
        q.pop();

        if (num != temp[cnt])
        {
            q.push({ loc, num });
            continue;
        }

        cnt++;

        if (loc == location)
        {
            return cnt;
        }
    }

    return -1;
}
