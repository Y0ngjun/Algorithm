#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int m, vector<vector<int>> timetable)
{
    vector<int> cnt(721, 0);
    for (const auto& v : timetable)
    {
        for (int i = v[0] - 600; i <= v[1] - 600; i++)
        {
            cnt[i]++;
        }
    }

    int maxCnt = 0;
    for (int i : cnt)
    {
        maxCnt = max(maxCnt, i);
    }

    if (maxCnt <= 1)
    {
        return 0;
    }

    for (int d = 2 * n; d > 2; d--)
    {
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            vector<pair<int, int>> nodes;
            nodes.push_back({ 0, i });

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    bool valid = true;

                    for (auto [y, x] : nodes)
                    {
                        int dist = abs(r - y) + abs(c - x);

                        if (dist < d)
                        {
                            valid = false;
                            break;
                        }
                    }

                    if (valid)
                    {
                        nodes.push_back({ r, c });
                    }
                }
            }

            if (nodes.size() >= maxCnt)
            {
                return d;
            }
        }
    }

    if (maxCnt <= (n * n + 1) / 2)
    {
        return 2;
    }

    return 1;
}
