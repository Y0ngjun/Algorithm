// 1248.[S / W 문제해결 응용] 3일차 - 공통조상
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solve(const vector<vector<int>>& adj, int node, int a, int b, bool& aval, bool& bval)
{
    if (adj[node].size() == 0)
    {
        aval = (node == a);
        bval = (node == b);

        return { node, 1 };
    }
    else if (adj[node].size() == 1)
    {
        bool aval0 = false;
        bool bval0 = false;

        auto ret0 = solve(adj, adj[node][0], a, b, aval0, bval0);

        aval = (node == a || aval0);
        bval = (node == b || bval0);

        if (aval0 && bval0)
        {
            return ret0;
        }

        return { node, ret0.second + 1 };
    }
    else
    {
        bool aval0 = false;
        bool bval0 = false;
        auto ret0 = solve(adj, adj[node][0], a, b, aval0, bval0);

        bool aval1 = false;
        bool bval1 = false;
        auto ret1 = solve(adj, adj[node][1], a, b, aval1, bval1);

        aval = (node == a || aval0 || aval1);
        bval = (node == b || bval0 || bval1);

        if (aval0 && bval0)
        {
            return ret0;
        }

        if (aval1 && bval1)
        {
            return ret1;
        }

        return { node, ret0.second + ret1.second + 1 };
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int V, E, a, b;
        cin >> V >> E >> a >> b;

        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; ++i)
        {
            int p, c;
            cin >> p >> c;

            adj[p].push_back(c);
        }

        bool aval, bval;
        auto ans = solve(adj, 1, a, b, aval, bval);

        cout << '#' << t << ' ' << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
