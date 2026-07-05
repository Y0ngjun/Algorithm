#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    int n = id_list.size();

    unordered_map<string, int> id2idx;
    for (int idx = 0; idx < n; idx++)
        id2idx[id_list[idx]] = idx;

    vector<unordered_set<string>> reporters(n);
    for (const auto& line : report)
    {
        istringstream iss(line);
        string reporter, reported;
        iss >> reporter >> reported;
        reporters[id2idx[reported]].insert(reporter);
    }

    vector<int> answer(n, 0);
    for (int idx = 0; idx < n; idx++)
    {
        if (reporters[idx].size() >= k)
        {
            for (const auto& reporter : reporters[idx])
            {
                answer[id2idx[reporter]]++;
            }
        }
    }

    return answer;
}
