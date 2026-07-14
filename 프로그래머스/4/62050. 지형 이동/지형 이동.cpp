#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

struct Edge
{
    int y, x;
    int cost;

    bool operator()(const Edge& a, const Edge& b)
    {
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> land, int height)
{
    int n = land.size();
    int answer = 0;
    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };
    vector<vector<char>> visited(n, vector<char>(n, false));
    priority_queue<Edge, vector<Edge>, Edge> pq;

    pq.push({ 0, 0, 0 });
    while (!pq.empty())
    {
        auto [y, x, cost] = pq.top();
        pq.pop();

        if (visited[y][x])
            continue;

        visited[y][x] = true;

        if (cost > height)
            answer += cost;

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
                continue;

            int ncost = abs(land[y][x] - land[ny][nx]);
            pq.push({ ny, nx, ncost });
        }
    }

    return answer;
}
