// LeetCode 1970. Last Day Where You Can Still Cross
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 물이 들어오는 날짜를 기록
        vector<vector<int>> board(row, vector<int>(col, 0));

        for (int i = 0; i < row * col; ++i)
        {
            board[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
        }

        // lo = T, hi = F
        int lo = 0, hi = row * col;

        while (lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;

            if (check(board, mid))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }

    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    // day 기준 횡단이 가능한지 판별
    bool check(const vector<vector<int>>& board, int day)
    {
        int row = board.size(), col = board[0].size();
        queue<pair<int, int>> bfs;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < col; ++i)
        {
            // 아직 물이 안들어옴
            if (board[0][i] > day)
            {
                bfs.push({ 0, i });
                visited[0][i] = true;
            }
        }

        while (!bfs.empty())
        {
            auto [y, x] = bfs.front();
            bfs.pop();

            if (y + 1 == row)
            {
                return true;
            }

            for (int d = 0; d < 4; ++d)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || ny >= row || nx < 0 || nx >= col || board[ny][nx] <= day || visited[ny][nx])
                {
                    continue;
                }

                bfs.push({ ny, nx });
                visited[ny][nx] = true;
            }
        }

        return false;
    }
};
