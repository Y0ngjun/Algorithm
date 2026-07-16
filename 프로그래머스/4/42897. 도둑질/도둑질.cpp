#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
    int n = money.size();

    int a1 = money[0], a2 = 0;
    int b1 = max(a1, money[1]), b2 = money[1];
    int c1 = max(a1 + money[2], b1), c2 = max(a2 + money[2], b2);

    for (int i = 3; i < n; i++)
    {
        a1 = b1;
        a2 = b2;
        b1 = c1;
        b2 = c2;
        c1 = max(a1 + money[i], b1);
        c2 = max(a2 + money[i], b2);
    }

    return max(b1, c2);
}
