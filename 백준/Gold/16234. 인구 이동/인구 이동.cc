// BOJ 16234. 인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> visited(N, vector<int>(N, 0));
    vector<pair<int, int>> temp;
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int answer = 0;

    for (int i = 1; i <= 2001; i++)
    {
        bool moved = false;

        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                if (visited[r][c] == i)
                {
                    continue;
                }

                queue<pair<int, int>> bfs;
                int sum = 0;
                temp.clear();

                bfs.push({ r, c });
                sum += A[r][c];
                temp.push_back({ r, c });
                visited[r][c] = i;

                while (!bfs.empty())
                {
                    auto [y, x] = bfs.front();
                    bfs.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int ny = y + dy[d];
                        int nx = x + dx[d];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] == i)
                        {
                            continue;
                        }

                        int diff = abs(A[ny][nx] - A[y][x]);

                        if (diff < L || diff > R)
                        {
                            continue;
                        }

                        bfs.push({ ny, nx });
                        sum += A[ny][nx];
                        temp.push_back({ ny, nx });
                        visited[ny][nx] = i;
                    }
                }

                int a = sum / temp.size();

                for (auto [y, x] : temp)
                {
                    if (!moved && A[y][x] != a)
                        moved = true;

                    A[y][x] = a;
                }
            }
        }

        if (!moved)
        {
            cout << i - 1;
            break;
        }
    }

    return 0;
}
