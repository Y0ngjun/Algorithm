#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>

using namespace std;

// 1. node 번호 담은 배열 생성
// 2. y 내림차순, x 오름차순 정렬
// 3. 루트 노드 설정
// 4. child 배열 생성
// 5. 전위 순회 기록
// 6. 후위 순회 기록

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    int n = nodeinfo.size();

    // 1
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 0);

    // 2
    sort(nodes.begin(), nodes.end(), [&](int a, int b)
        {
            if (nodeinfo[a][1] == nodeinfo[b][1])
                return nodeinfo[a][0] < nodeinfo[b][0];
            return nodeinfo[a][1] > nodeinfo[b][1];
        });

    // 3
    int root = nodes[0];

    // 4
    vector<vector<int>> child(n, vector<int>(2, -1));
    for (int i = 1; i < n; i++)
    {
        int curr = root;
        int val = nodeinfo[nodes[i]][0];

        while (true)
        {
            if (val < nodeinfo[curr][0])
            {
                if (child[curr][0] == -1)
                {
                    child[curr][0] = nodes[i];
                    break;
                }
                curr = child[curr][0];
            }
            else
            {
                if (child[curr][1] == -1)
                {
                    child[curr][1] = nodes[i];
                    break;
                }
                curr = child[curr][1];
            }
        }
    }

    // 5
    vector<vector<int>> answer(2);
    stack<int> stk;
    stk.push(root);
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();

        answer[0].push_back(curr + 1);

        if (child[curr][1] != -1)
            stk.push(child[curr][1]);

        if (child[curr][0] != -1)
            stk.push(child[curr][0]);
    }

    // 6
    vector<int> visited(n, 0);
    stk.push(root);
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();

        if (visited[curr] == 1)
        {
            answer[1].push_back(curr + 1);
            continue;
        }

        visited[curr] = 1;
        stk.push(curr);

        if (child[curr][1] != -1)
            stk.push(child[curr][1]);

        if (child[curr][0] != -1)
            stk.push(child[curr][0]);
    }

    return answer;
}
