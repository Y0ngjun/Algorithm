#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int go = 0;
    int back = 0;
    int totalCap = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        go += deliveries[i];
        back += pickups[i];

        int temp = max(go, back);

        if (temp > totalCap)
        {
            int need = (temp - totalCap + cap - 1) / cap;

            answer += need * (i + 1) * 2;
            totalCap += need * cap;
        }
    }

    return answer;
}
