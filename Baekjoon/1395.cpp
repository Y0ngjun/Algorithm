// BOJ 1395. 스위치
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<bool> lazy;

void propagate(int node, int left, int right)
{
    if (!lazy[node])
    {
        return;
    }

    tree[node * 2] = ((left + right) / 2 - left + 1) - tree[node * 2];
    lazy[node * 2] = !lazy[node * 2];

    tree[node * 2 + 1] = (right - ((left + right) / 2 + 1) + 1) - tree[node * 2 + 1];
    lazy[node * 2 + 1] = !lazy[node * 2 + 1];

    lazy[node] = false;
}

void updateTree(int node, int left, int right, int S, int T)
{
    if (T < left || S > right)
    {
        return;
    }

    if (S <= left && right <= T)
    {
        tree[node] = (right - left + 1) - tree[node];
        lazy[node] = !lazy[node];
        return;
    }

    propagate(node, left, right);
    updateTree(node * 2, left, (left + right) / 2, S, T);
    updateTree(node * 2 + 1, (left + right) / 2 + 1, right, S, T);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int S, int T)
{
    if (T < left || S > right)
    {
        return 0;
    }

    if (S <= left && right <= T)
    {
        return tree[node];
    }

    propagate(node, left, right);

    long long sum = 0;
    sum += query(node * 2, left, (left + right) / 2, S, T);
    sum += query(node * 2 + 1, (left + right) / 2 + 1, right, S, T);

    return sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    tree.assign(N * 4, 0);
    lazy.assign(N * 4, false);

    for (int i = 0; i < M; i++)
    {
        int O, S, T;
        cin >> O >> S >> T;

        if (O == 0)
        {
            updateTree(1, 1, N, S, T);
        }
        else if (O == 1)
        {
            cout << query(1, 1, N, S, T) << '\n';
        }
    }

    return 0;
}
