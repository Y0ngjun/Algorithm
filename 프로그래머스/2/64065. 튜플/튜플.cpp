#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. 집합 모두 찾음
2. 집합의 크기를 기준으로 오름차순 정렬
3. 새로운 원소가 등장하는 순서대로 answer에 삽입
*/

// {num, idx}
pair<int, int> scan_num(const string& s, int start)
{
    int num = 0;
    for (int i = start; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
            num = num * 10 + s[i] - '0';
        else
            return { num, i - 1 };
    }
    return { -1, -1 };
}

// {set, idx}
pair<vector<int>, int> scan_set(const string& s, int start)
{
    vector<int> set;
    for (int i = start; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == ',')
        {
            auto [num, idx] = scan_num(s, i + 1);
            set.push_back(num);
            i = idx;
        }
        else if (s[i] == '}')
        {
            return { set, i };
        }
    }
    return { { -1 }, -1 };
}

bool in(int num, const vector<int> set)
{
    for (int i : set)
        if (i == num)
            return true;
    return false;
}

vector<int> solution(string s)
{
    vector<vector<int>> sets;
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '{')
        {
            auto [set, idx] = scan_set(s, i);
            i = idx;

            sets.push_back(set);
        }
    }

    sort(sets.begin(), sets.end(), [](const auto& a, const auto& b) { return a.size() < b.size(); });

    vector<int> answer;
    for (const auto& set : sets)
        for (int num : set)
            if (!in(num, answer))
                answer.push_back(num);

    return answer;
}
