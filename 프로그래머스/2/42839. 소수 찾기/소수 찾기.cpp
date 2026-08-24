#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    if (num == 2)
    {
        return true;
    }

    if (num % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers)
{
    unordered_set<int> nums;

    sort(numbers.begin(), numbers.end());

    for (int size = 1; size <= numbers.length(); size++)
    {
        for (int start = 0; start + size <= numbers.length(); start++)
        {
            do
            {
                nums.insert(stoi(numbers.substr(start, size)));
            } while (next_permutation(numbers.begin(), numbers.end()));
        }
    }

    int answer = 0;

    for (int i : nums)
    {
        if (isPrime(i))
        {
            answer++;
        }
    }

    return answer;
}
