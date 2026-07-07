#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent, parent[u]);
    }

    return parent[u];
}

bool unite(vector<int>& parent, int u, int v)
{
    u = find(parent, u);
    v = find(parent, v);

    if (u != v)
    {
        parent[u] = v;
        return true;
    }

    return false;
}

int solution(int n, vector<vector<int>> costs)
{
    int m = costs.size();
    int answer = 0;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    sort(costs.begin(), costs.end(),
        [](const auto& a, const auto& b)
        {
            return a[2] < b[2];
        });

    for (int i = 0; i < m; i++)
    {
        int u = costs[i][0];
        int v = costs[i][1];

        if (unite(parent, u, v))
        {
            answer += costs[i][2];
        }
    }

    return answer;
}
