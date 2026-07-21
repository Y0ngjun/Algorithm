#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int i = 0; // stations[i]: 가장 가까운 기지국
    int j = 1; // 현재 위치
    int k = 0; // 새로운 기지국 개수
    int width = w + 1 + w;

    while (j <= n)
    {
        while (i < stations.size() && stations[i] + w < j)
        {
            i++;
        }

        if (i < stations.size() && stations[i] - w <= j && j <= stations[i] + w)
        {
            j = stations[i] + w + 1;
            i++;
        }
        else
        {
            j += width;
            k++;
        }
    }

    return k;
}
