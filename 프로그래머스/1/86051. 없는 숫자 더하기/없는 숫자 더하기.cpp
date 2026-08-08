#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;

    for (int number : numbers)
        answer -= number;

    return answer;
}