// LeetCode 840. Magic Squares In Grid
#include <vector>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ret = 0;

        for (int r = 0; r + 2 < row; ++r)
        {
            for (int c = 0; c + 2 < col; ++c)
            {
                int check = 0;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        check |= (1 << grid[r + i][c + j]);
                    }
                }

                if (check != 0b1111111110)
                {
                    continue;
                }

                int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

                if (grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] == sum &&
                    grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] == sum &&
                    grid[r][c] + grid[r + 1][c] + grid[r + 2][c] == sum &&
                    grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] == sum &&
                    grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] == sum &&
                    grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == sum &&
                    grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == sum)
                {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
