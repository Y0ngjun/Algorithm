#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<int> dx = { 1, 0, -1, 0 };
    vector<int> dy = { 0, 1, 0, -1 };

    int Sx, Sy;
    int Lx, Ly;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (maps[y][x] == 'S')
            {
                Sx = x;
                Sy = y;
            }
        }
    }

    // S to L
    int S2L = -1;
    queue<vector<int>> bfs;
    vector<vector<char>> visited(n, vector<char>(m, false));

    bfs.push({ Sx, Sy, 0 });
    visited[Sy][Sx] = true;

    while (!bfs.empty())
    {
        int x = bfs.front()[0];
        int y = bfs.front()[1];
        int c = bfs.front()[2];
        bfs.pop();

        if (maps[y][x] == 'L')
        {
            S2L = c;
            Lx = x;
            Ly = y;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || maps[ny][nx] == 'X')
                continue;

            bfs.push({ nx, ny, c + 1 });
            visited[ny][nx] = true;
        }
    }

    if (S2L == -1)
    {
        return -1;
    }

    // L to E
    int L2E = -1;
    while (!bfs.empty())
    {
        bfs.pop();
    }
    visited.assign(n, vector<char>(m, false));

    bfs.push({ Lx, Ly, 0 });
    visited[Ly][Lx] = true;

    while (!bfs.empty())
    {
        int x = bfs.front()[0];
        int y = bfs.front()[1];
        int c = bfs.front()[2];
        bfs.pop();

        if (maps[y][x] == 'E')
        {
            L2E = c;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx] || maps[ny][nx] == 'X')
                continue;

            bfs.push({ nx, ny, c + 1 });
            visited[ny][nx] = true;
        }
    }

    if (L2E == -1)
    {
        return -1;
    }

    // answer
    int answer = S2L + L2E;
    return answer;
}
