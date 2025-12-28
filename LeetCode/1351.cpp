// LeetCode 1351 Count Negative Numbers in a Sorted Matrix
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // + + + -
        // + ? ? -
        // + ? ? -
        // - - - -

        return recursion(0, 0, grid.size(), grid[0].size(), grid);
    }

    int recursion(int m1, int n1, int m2, int n2, const vector<vector<int>>& grid)
    {
        if (m2 <= m1 || n2 <= n1)
        {
            return 0;
        }

        int m = m2;

        for (int i = m1; i < m2; ++i)
        {
            if (grid[i][n1] < 0)
            {
                m = i;
                break;
            }
        }

        int n = n2;

        for (int i = n1; i < n2; ++i)
        {
            if (grid[m1][i] < 0)
            {
                n = i;
                break;
            }
        }

        return (m2 - m) * (n2 - n1) + (n2 - n) * (m2 - m1) - (m2 - m) * (n2 - n) + recursion(m1 + 1, n1 + 1, m, n, grid);
    }
};
