#include <vector>
#include <algorithm>

using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

pair<int, int> backtracking(vector<vector<int>>& board, vector<vector<int>*>& locs, int turn)
{
    int n = board.size();
    int m = board[0].size();

    int player = turn % 2;
    int enemy = 1 - player;
    vector<int>& loc = *locs[player];

    if (!board[loc[0]][loc[1]])
        return { enemy, turn };

    int win = 1e9, lose = turn;

    for (int d = 0; d < 4; d++)
    {
        int ny = loc[0] + dy[d];
        int nx = loc[1] + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || !board[ny][nx])
            continue;

        board[loc[0]][loc[1]] = 0;
        loc[0] += dy[d];
        loc[1] += dx[d];

        auto [w, t] = backtracking(board, locs, turn + 1);
        if (w == player)
            win = min(win, t);
        else
            lose = max(lose, t);

        loc[0] -= dy[d];
        loc[1] -= dx[d];
        board[loc[0]][loc[1]] = 1;
    }

    if (win != 1e9)
        return { player, win };
    else
        return { enemy, lose };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    vector<vector<int>*> locs = { &aloc, &bloc };
    return backtracking(board, locs, 0).second;
}
