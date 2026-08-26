#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> clothes(n + 2, 1);

    clothes[0] = 0;
    clothes[n + 1] = 0;

    for (int i : lost) clothes[i]--;
    for (int i : reserve) clothes[i]++;

    int ret = n;

    for (int i = 1; i <= n; i++)
    {
        if (clothes[i] >= 1) continue;

        if (clothes[i - 1] > 1)
        {
            clothes[i - 1]--;
            continue;
        }

        if (clothes[i + 1] > 1)
        {
            clothes[i + 1]--;
            continue;
        }

        ret--;
    }

    return ret;
}
