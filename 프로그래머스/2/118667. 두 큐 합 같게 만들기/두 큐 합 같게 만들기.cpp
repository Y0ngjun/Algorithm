#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int n = queue1.size();
    int m = queue2.size();

    long long sum = 0LL;
    long long q1 = 0LL;

    for (int i : queue1)
    {
        sum += i;
        q1 += i;
    }

    for (int i : queue2)
    {
        sum += i;
    }

    if (sum % 2)
    {
        return -1;
    }

    long long half = sum / 2;

    int begin = 0;
    int end = 0;
    int answer = 0;

    while (begin < n + m && end < n + m)
    {
        if (q1 > half)
        {
            if (begin < n)
            {
                q1 -= queue1[begin++];
            }
            else
            {
                q1 -= queue2[begin++ - n];
            }
        }
        else if (q1 < half)
        {
            if (end < m)
            {
                q1 += queue2[end++];
            }
            else
            {
                q1 += queue1[end++ - m];
            }
        }
        else
        {
            return answer;
        }

        answer++;
    }

    return -1;
}
