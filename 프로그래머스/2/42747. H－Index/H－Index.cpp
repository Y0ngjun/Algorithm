#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.rbegin(), citations.rend());

    int answer = 0;

    for (int i : citations)
    {
        if (i > answer)
        {
            answer++;
        }
        else
        {
            break;
        }
    }

    return answer;
}
