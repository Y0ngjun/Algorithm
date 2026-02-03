// SWEA 1249. [S/W 문제해결 응용] 4일차 - 보급로
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0 , -1 };

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;

        vector<vector<int>> map(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;

            for (int j = 0; j < N; ++j)
            {
                map[i][j] = s[j] - '0';
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> visited(N, vector<int>(N, 0));

        pq.push({ 0, {0, 0} });
        visited[0][0] = 1;

        while (!pq.empty())
        {
            auto [dist, pos] = pq.top();
            pq.pop();

            if (pos.first == N - 1 && pos.second == N - 1)
            {
                cout << '#' << t << ' ' << -dist << '\n';
                break;
            }

            for (int d = 0; d < 4; ++d)
            {
                int ny = pos.first + dy[d];
                int nx = pos.second + dx[d];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
                {
                    continue;
                }

                pq.push({ dist - map[ny][nx], {ny, nx} });
                visited[ny][nx] = 1;
            }
        }
    }

    return 0;
}