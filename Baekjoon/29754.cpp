// BOJ 29754 세상에는 많은 유튜버가 있고, 그중에서 버츄얼 유튜버도 존재한다
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minute(string start, string end)
{
    int h = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    int m = stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));

    return h * 60 + m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, vector<pair<int, int>>> history;

    for (int i = 0; i < N; ++i)
    {
        string name, start, end;
        int day;

        cin >> name >> day >> start >> end;

        if (history.count(name) == 0)
        {
            history[name] = vector<pair<int, int>>((M + 6) / 7, { 0, 0 });
        }

        int m = minute(start, end);
        history[name][(day - 1) / 7].first += 1;
        history[name][(day - 1) / 7].second += m;
    }

    vector<string> ans;
    for (const auto& [name, record] : history)
    {
        bool b = true;

        for (const auto& entry : record)
        {
            if (entry.first < 5 || entry.second < 60 * 60)
            {
                b = false;
                break;
            }
        }

        if (b)
        {
            ans.push_back(name);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() != 0)
    {
        for (const auto& name : ans)
        {
            cout << name << '\n';
        }
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}
