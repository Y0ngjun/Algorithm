#include <vector>

using namespace std;

int backtracking(int k, const vector<vector<int>>& dungeons, unsigned char bitmask)
{
    int n = dungeons.size();
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        if (bitmask & (1 << i) || dungeons[i][0] > k)
        {
            continue;
        }

        ret = max(ret, 1 + backtracking(k - dungeons[i][1], dungeons, bitmask | (1 << i)));
    }

    return ret;
}

int solution(int k, vector<vector<int>> dungeons)
{
    return backtracking(k, dungeons, 0);
}
