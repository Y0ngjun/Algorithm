#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k)
{
    int n = number.length();

    string answer;

    for (int i = 0; i < n; i++)
    {
        answer.push_back(number[i]);

        while (!answer.empty() && i + 1 < n && answer.back() < number[i + 1] && k > 0)
        {
            k--;
            answer.pop_back();
        }
    }

    while (k > 0)
    {
        k--;
        answer.pop_back();
    }

    return answer;
}
