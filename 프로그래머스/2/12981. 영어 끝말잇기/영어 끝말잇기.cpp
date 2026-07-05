#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer = { 0, 0 };
    unordered_set<string> us = { words[0] };
    string prev = words[0];
    int i = 0;

    while (++i < words.size())
    {
        if (us.count(words[i]) || prev.back() != words[i].front())
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }

        us.insert(words[i]);
        prev = words[i];
    }

    return answer;
}
