// LeetCode 3453. Separate Squares I
#include <vector>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double sum = 0;

        for (const vector<int>& square : squares)
            sum += (double)square[2] * square[2];

        // lo는 F, hi는 T가 보장됨
        double lo = 0, hi = 2e9;

        // lo와 hi가 충분히 가까워질 때까지 반복
        while (lo + 1e-5 < hi)
        {
            double mid = (lo + hi) / 2;

            if (check(squares, mid, sum))
                hi = mid;
            else
                lo = mid;
        }

        return hi;
    }

    // height보다 아래에 있는 사각형 넓이가 전체 사각형 넓이의 절반을 넘는지 확인
    bool check(const vector<vector<int>>& squares, double height, double sum)
    {
        double localSum = 0;

        for (const vector<int>& square : squares)
        {
            double y = (double)square[1];

            if (y > height)
                continue;

            double l = (double)square[2];

            if (y + l <= height)
                localSum += l * l;
            else
                localSum += l * (height - y);
        }

        if (localSum * 2 >= sum)
            return true;

        return false;
    }
};
