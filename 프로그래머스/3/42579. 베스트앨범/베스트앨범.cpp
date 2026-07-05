#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> pog; // plays of genres
    unordered_map<string, vector<int>> sog; // songs of genres

    int n = genres.size();

    for (int i = 0; i < n; i++)
    {
        const auto& genre = genres[i];
        pog[genre] += plays[i];
        sog[genre].push_back(i);
    }

    for (auto& [genre, vec] : sog)
    {
        sort(vec.begin(), vec.end(), [plays](const int& a, const int& b)
            {
                return plays[a] > plays[b];
            });

        for (int i = 0; i < 2 && i < vec.size(); i++)
        {
            answer.push_back(vec[i]);
        }
    }

    sort(answer.begin(), answer.end(), [&](const int& a, const int& b)
        {
            if (genres[a] == genres[b])
            {
                if (plays[a] == plays[b])
                    return a < b;

                return plays[a] > plays[b];
            }

            return pog[genres[a]] > pog[genres[b]];
        });

    return answer;
}
