#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void Pay(int idx, int money, const vector<int>& boss, vector<int>& answer)
{
    if (idx == -1)
        return;

    int incentive = money / 10;

    Pay(boss[idx], incentive, boss, answer);

    answer[idx] += money - incentive;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    int n = enroll.size();
    int m = seller.size();

    unordered_map<string, int> name2idx;
    name2idx["-"] = -1;
    for (int idx = 0; idx < n; idx++)
        name2idx[enroll[idx]] = idx;

    vector<int> boss(n);
    for (int idx = 0; idx < n; idx++)
        boss[idx] = name2idx[referral[idx]];

    vector<int> answer(n);
    for (int i = 0; i < m; i++)
        Pay(name2idx[seller[i]], amount[i] * 100, boss, answer);

    return answer;
}
