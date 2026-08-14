#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
    int al;
    int co;
    int dist;

    bool operator()(const Node& a, const Node& b)
    {
        return a.dist > b.dist;
    }
};

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int alp_req_max = 0;
    int cop_req_max = 0;

    for (const auto& p : problems)
    {
        alp_req_max = max(alp_req_max, p[0]);
        cop_req_max = max(cop_req_max, p[1]);
    }

    problems.push_back({ 0, 0, 1, 0, 1 });
    problems.push_back({ 0, 0, 0, 1, 1 });

    priority_queue<Node, vector<Node>, Node> pq;
    vector<vector<char>> visited(alp_req_max + 1, vector<char>(cop_req_max + 1, false));

    pq.push({ min(alp, alp_req_max), min(cop, cop_req_max), 0 });

    while (!pq.empty())
    {
        auto [al, co, dist] = pq.top();
        pq.pop();

        if (al == alp_req_max && co == cop_req_max)
        {
            return dist;
        }

        if (visited[al][co])
        {
            continue;
        }

        visited[al][co] = true;

        for (const auto& p : problems)
        {
            if (al >= p[0] && co >= p[1])
            {
                int nal = min(al + p[2], alp_req_max);
                int nco = min(co + p[3], cop_req_max);

                if (!visited[nal][nco])
                {
                    pq.push({ nal, nco, dist + p[4] });
                }
            }
        }
    }

    return -1;
}
