#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;
    int prev = 1;

    for (int station : stations)
    {
        int dist = station - w - prev;

        if (dist > 0)
            ans += (dist + w + w) / (w + w + 1);

        prev = station + w + 1;
    }

    if (prev <= n)
    {
        int dist = n - prev + 1;

        ans += (dist + w + w) / (w + w + 1);
    }

    return ans;
}
