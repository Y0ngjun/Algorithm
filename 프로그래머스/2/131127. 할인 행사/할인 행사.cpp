#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    unordered_map<string, int> sale;
    for (int i = 0; i < 9; i++)
        sale[discount[i]]++;

    int answer = 0;

    for (int i = 9; i < discount.size(); i++)
    {
        sale[discount[i]]++;

        bool same = true;
        for (int j = 0; j < want.size(); j++)
        {
            if (sale[want[j]] != number[j])
            {
                same = false;
                break;
            }
        }

        if (same)
            answer++;

        sale[discount[i - 9]]--;
    }

    return answer;
}
