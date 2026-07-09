#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct App
{
    int y, x;
    int size;
};

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands)
{
    int H = board.size();
    int W = board[0].size();
    int C = commands.size();

    int dy[] = { 0, 0, 1, 0, -1 };
    int dx[] = { 0, 1, 0, -1, 0 };

    unordered_map<int, App> apps;
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            int ID = board[r][c];

            if (ID != 0 && apps.count(ID) == 0)
            {
                int size = 1;
                while (c + size < W && board[r][c + size] == ID) size++;
                apps[ID] = { r, c, size };
            }
        }
    }

    for (int cmd = 0; cmd < C; cmd++)
    {
        int ID = commands[cmd][0];
        int arrow = commands[cmd][1];

        queue<int> seeds;
        seeds.push(ID);

        while (!seeds.empty())
        {
            unordered_set<int> movers;
            queue<int> bfs;

            while (!seeds.empty())
            {
                int seed = seeds.front();
                seeds.pop();

                movers.insert(seed);
                bfs.push(seed);
            }

            while (!bfs.empty())
            {
                int mover = bfs.front();
                bfs.pop();

                if (arrow == 1)
                {
                    int c = (apps[mover].x + apps[mover].size) % W;
                    for (int r = apps[mover].y; r < apps[mover].y + apps[mover].size; r++)
                    {
                        int adj = board[r][c];
                        if (adj != 0 && movers.count(adj) == 0)
                        {
                            movers.insert(adj);
                            bfs.push(adj);
                        }
                    }
                }
                else if (arrow == 2)
                {
                    int r = (apps[mover].y + apps[mover].size) % H;
                    for (int c = apps[mover].x; c < apps[mover].x + apps[mover].size; c++)
                    {
                        int adj = board[r][c];
                        if (adj != 0 && movers.count(adj) == 0)
                        {
                            movers.insert(adj);
                            bfs.push(adj);
                        }
                    }
                }
                else if (arrow == 3)
                {
                    int c = (apps[mover].x - 1 + W) % W;
                    for (int r = apps[mover].y; r < apps[mover].y + apps[mover].size; r++)
                    {
                        int adj = board[r][c];
                        if (adj != 0 && movers.count(adj) == 0)
                        {
                            movers.insert(adj);
                            bfs.push(adj);
                        }
                    }
                }
                else if (arrow == 4)
                {
                    int r = (apps[mover].y - 1 + H) % H;
                    for (int c = apps[mover].x; c < apps[mover].x + apps[mover].size; c++)
                    {
                        int adj = board[r][c];
                        if (adj != 0 && movers.count(adj) == 0)
                        {
                            movers.insert(adj);
                            bfs.push(adj);
                        }
                    }
                }
            }

            // 삭제
            for (int mover : movers)
            {
                for (int r = apps[mover].y; r < apps[mover].y + apps[mover].size; r++)
                {
                    int R = r % H;
                    for (int c = apps[mover].x; c < apps[mover].x + apps[mover].size; c++)
                    {
                        int C = c % W;
                        board[R][C] = 0;
                    }
                }
            }

            // 이동
            for (int mover : movers)
            {
                apps[mover].y = (apps[mover].y + dy[arrow] + H) % H;
                apps[mover].x = (apps[mover].x + dx[arrow] + W) % W;
            }

            // 삽입
            for (int mover : movers)
            {
                for (int r = apps[mover].y; r < apps[mover].y + apps[mover].size; r++)
                {
                    int R = r % H;
                    for (int c = apps[mover].x; c < apps[mover].x + apps[mover].size; c++)
                    {
                        int C = c % W;
                        board[R][C] = mover;
                    }
                }
            }

            // 시드 탐색
            for (int mover : movers)
            {
                if (apps[mover].y + apps[mover].size > H ||
                    apps[mover].x + apps[mover].size > W)
                    seeds.push(mover);
            }
        }
    }

    return board;
}
