#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end(), [](int a, int b)
        {
            return stoll(to_string(a) + to_string(b)) > stoll(to_string(b) + to_string(a));
        });

    string answer = "";
    for (int num : numbers)
        answer += to_string(num);

    if (answer[0] == '0')
        return "0";

    return answer;
}
