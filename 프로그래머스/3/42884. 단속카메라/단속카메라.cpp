#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

    int n = routes.size();
    int i = 0;
    int answer = 0;

    while (i < n)
    {
        answer++;

        int camera = routes[i][1];

        while (i < n && routes[i][0] <= camera)
        {
            i++;
        }
    }

    return answer;
}
