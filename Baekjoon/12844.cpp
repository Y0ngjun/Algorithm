// BOJ 12844. XOR
#include <iostream>
#include <vector>

using namespace std;

// A: 원본 배열
// tree: 구간의 XOR 결과
// lazy: 현재 노드에는 적용되었지만 자식 노드에는 전파하지 않은 xor값
vector<int> A;
vector<int> tree;
vector<int> lazy;

void initTree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
        return;
    }

    initTree(node * 2, start, (start + end) / 2);
    initTree(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void propagate(int node, int start, int end)
{
    if (lazy[node] == 0)
    {
        return;
    }

    if (((start + end) / 2 - start + 1) % 2 == 1)
    {
        tree[node * 2] ^= lazy[node];
    }

    if ((end - ((start + end) / 2 + 1) + 1) % 2 == 1)
    {
        tree[node * 2 + 1] ^= lazy[node];
    }

    lazy[node * 2] ^= lazy[node];
    lazy[node * 2 + 1] ^= lazy[node];
    lazy[node] = 0;
}

void lazyUpdateTree(int node, int start, int end, int left, int right, int k)
{
    if (right < start || end < left)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        if ((end - start + 1) % 2 == 1)
        {
            tree[node] ^= k;
        }

        lazy[node] ^= k;
        return;
    }

    propagate(node, start, end);
    lazyUpdateTree(node * 2, start, (start + end) / 2, left, right, k);
    lazyUpdateTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    propagate(node, start, end);
    return query(node * 2, start, (start + end) / 2, left, right) ^
        query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    A.resize(N + 1);
    tree.resize(N * 4);
    lazy.resize(N * 4);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    initTree(1, 1, N);

    int M;
    cin >> M;

    for (int m = 0; m < M; m++)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;

            lazyUpdateTree(1, 1, N, i + 1, j + 1, k);
        }
        else if (cmd == 2)
        {
            int i, j;
            cin >> i >> j;

            cout << query(1, 1, N, i + 1, j + 1) << '\n';
        }
    }

    return 0;
}
