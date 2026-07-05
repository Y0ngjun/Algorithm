#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int Same(const unordered_map<string, int>& a, unordered_map<string, int>& b)
{
    for (const auto& [s, i] : a)
        if (b[s] != i)
            return 0;

    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> buy;
    for (int i = 0; i < want.size(); i++)
        buy[want[i]] = number[i];

    unordered_map<string, int> sale;
    for (int i = 0; i < 10; i++)
        sale[discount[i]]++;

    int answer = Same(buy, sale);

    for (int i = 10; i < discount.size(); i++)
    {
        sale[discount[i - 10]]--;
        sale[discount[i]]++;

        answer += Same(buy, sale);
    }

    return answer;
}
