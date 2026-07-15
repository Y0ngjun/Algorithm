#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    unordered_map<int, int> a;
    unordered_map<int, int> b;

    for (int i = 0; i < topping.size(); i++)
        b[topping[i]]++;

    for (int i = 0; i < topping.size(); i++)
    {
        a[topping[i]]++;
        b[topping[i]]--;

        if (!b[topping[i]])
            b.erase(topping[i]);

        if (a.size() == b.size())
            answer++;
    }

    return answer;
}