/*
1. 출발점에서 가로, 세로 출발
2. 우선순위 큐 BFS
*/

#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int y, x, cost;
    bool isHorizontal;

    bool operator()(const Node& a, const Node& b)
    {
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board)
{
    int n = board.size();
    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };
    bool dh[] = { true, false, true, false };

    priority_queue<Node, vector<Node>, Node> bfs;
    vector<vector<vector<char>>> visited(n, vector<vector<char>>(n, vector<char>(2, false)));

    bfs.push({ 0, 0, 0, 0 });
    bfs.push({ 0, 0, 0, 1 });

    int answer = -1;

    while (!bfs.empty())
    {
        auto [y, x, cost, isHorizontal] = bfs.top();
        bfs.pop();

        if (visited[y][x][isHorizontal])
            continue;

        visited[y][x][isHorizontal] = true;

        if (y == n - 1 && x == n - 1)
        {
            answer = cost;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];
            int ncost = cost + (isHorizontal == dh[d] ? 100 : 600);

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] || visited[ny][nx][dh[d]])
                continue;

            bfs.push({ ny, nx, ncost, dh[d] });
        }
    }

    return answer;
}
