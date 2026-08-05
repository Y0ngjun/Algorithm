#include <vector>
#include <string>

using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;

    for (const string& str : s)
    {
        answer.push_back("");

        int len = str.size();
        int count1 = 0;
        int count110 = 0;

        for (int i = 0; i < len; i++)
        {
            if (str[i] == '0')
            {
                if (count1 >= 2)
                {
                    count1 -= 2;
                    count110++;
                }
                else
                {
                    while (count1)
                    {
                        answer.back().push_back('1');
                        count1--;
                    }
                    answer.back().push_back('0');
                }
            }
            else
            {
                count1++;
            }
        }
        for (int i = 0; i < count110; i++)
        {
            answer.back() += "110";
        }
        while (count1)
        {
            answer.back().push_back('1');
            count1--;
        }
    }

    return answer;
}