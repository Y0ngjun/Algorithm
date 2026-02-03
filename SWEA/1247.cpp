// SWEA 1247. [S/W 문제해결 응용] 3일차 - 최적 경로
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int calcDist(int a, int b, const vector<pair<int, int>>& pos)
{
    int dist = abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);

    return dist;
}

int backtracking(int N, int M, int curr, int dist, int bitmask, const vector<pair<int, int>>& pos)
{
    if (M == N + 2)
    {
        return dist;
    }
    else if (M == N + 1)
    {
        return backtracking(N, M + 1, 1, dist + calcDist(curr, 1, pos), bitmask | (1 << 1), pos);
    }
    else
    {
        int ret = 1e9;

        for (int i = 2; i < N + 2; ++i)
        {
            if (bitmask & (1 << i))
            {
                continue;
            }

            int temp = backtracking(N, M + 1, i, dist + calcDist(curr, i, pos), bitmask | (1 << i), pos);
            ret = min(ret, temp);
        }

        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> pos(N + 2);

        for (int i = 0; i < N + 2; ++i)
        {
            cin >> pos[i].first >> pos[i].second;
        }

        cout << '#' << t << ' ' << backtracking(N, 1, 0, 0, 1, pos) << '\n';
    }

    return 0;
}
