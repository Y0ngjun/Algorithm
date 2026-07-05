#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void Comb(const string& order, const int& len, int st, string& comb, unordered_map<string, int>& cnt)
{
    if (comb.length() == len)
    {
        cnt[comb]++;
        return;
    }

    int remain = len - comb.length();
    for (int i = st; i + remain <= order.length(); i++)
    {
        comb.push_back(order[i]);
        Comb(order, len, i + 1, comb, cnt);
        comb.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    unordered_map<string, int> cnt;
    for (auto& order : orders)
    {
        sort(order.begin(), order.end());
        for (const auto& len : course)
        {
            if (order.size() < len)
                break;

            int st = 0;
            string comb = "";
            Comb(order, len, st, comb, cnt);
        }
    }

    unordered_map<int, int> maxCnt;
    for (const auto& [s, i] : cnt)
    {
        int m = s.length();
        if (i > maxCnt[m])
            maxCnt[m] = i;
    }

    vector<string> answer;
    for (const auto& [s, i] : cnt)
    {
        int m = s.length();
        if (i >= 2 && i == maxCnt[m])
            answer.push_back(s);
    }

    sort(answer.begin(), answer.end());

    return answer;
}
