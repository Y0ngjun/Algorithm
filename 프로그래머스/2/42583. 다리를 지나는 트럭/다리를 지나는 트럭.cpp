#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> bridge;

    for (int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }

    int n = truck_weights.size();
    int w = 0;
    int t = 0;
    int i = 0;

    while (true)
    {
        int temp = bridge.front();
        bridge.pop();

        w -= temp;

        if (i < n && truck_weights[i] + w <= weight)
        {
            bridge.push(truck_weights[i]);
            w += truck_weights[i];
            i++;
        }
        else
        {
            bridge.push(0);
        }

        t++;

        if (w == 0)
        {
            break;
        }
    }

    return t;
}
