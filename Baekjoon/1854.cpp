// BOJ 1854. K번째 최단경로 찾기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 인접 리스트
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
    }

    // 몇번째 방문인지
    vector<int> visited(n + 1);

    // 정답 배열
    vector<int> answer(n + 1, -1);

    // 우선순위 큐
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 1 });

    // 다익스트라
    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        // 이미 k번 이상 방문했다면 건너뜀
        if (visited[node] >= k)
        {
            continue;
        }

        visited[node]++;

        // 이번이 k번째 방문이라면 정답 배열에 기록
        if (visited[node] == k)
        {
            answer[node] = -cost;
        }

        for (auto [b, c] : adj[node])
        {
            // 이미 k번 이상 방문했다면 건너뜀
            if (visited[b] >= k)
            {
                continue;
            }

            pq.push({ cost - c, b });
        }
    }

    // 정답 출력
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}