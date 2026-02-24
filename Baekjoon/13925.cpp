// BOJ 13925. 수열과 쿼리 13
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
vector<int> A;
vector<int> tree;
vector<pair<int, int>> lazy;

void initTree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = A[start];
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    initTree(leftNode, start, mid);
    initTree(rightNode, mid + 1, end);
    tree[node] = (tree[leftNode] + tree[rightNode]) % MOD;
}

void propagate(int node, int start, int end)
{
    if (lazy[node].first == 1 && lazy[node].second == 0)
    {
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;
    int leftLength = mid - start + 1;
    int rightLength = end - (mid + 1) + 1;

    tree[leftNode] = (1LL * tree[leftNode] * lazy[node].first + 1LL * lazy[node].second * leftLength) % MOD;
    tree[rightNode] = (1LL * tree[rightNode] * lazy[node].first + 1LL * lazy[node].second * rightLength) % MOD;

    lazy[leftNode] = { (1LL * lazy[leftNode].first * lazy[node].first) % MOD,
        (1LL * lazy[leftNode].second * lazy[node].first + lazy[node].second) % MOD };
    lazy[rightNode] = { (1LL * lazy[rightNode].first * lazy[node].first) % MOD,
        (1LL * lazy[rightNode].second * lazy[node].first + lazy[node].second) % MOD };
    lazy[node] = { 1, 0 };
}

void lazyUpdateTree(int node, int start, int end, int left, int right, int mult, int plus)
{
    if (right < start || end < left)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        int length = (end - start + 1);
        tree[node] = (1LL * tree[node] * mult + 1LL * plus * length) % MOD;
        lazy[node] = { (1LL * lazy[node].first * mult) % MOD,
            (1LL * lazy[node].second * mult + plus) % MOD };
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    propagate(node, start, end);
    lazyUpdateTree(leftNode, start, mid, left, right, mult, plus);
    lazyUpdateTree(rightNode, mid + 1, end, left, right, mult, plus);
    tree[node] = (tree[leftNode] + tree[rightNode]) % MOD;
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

    int leftn = node * 2;
    int rightn = node * 2 + 1;
    int mid = (start + end) / 2;

    propagate(node, start, end);
    return (query(leftn, start, mid, left, right) +
        query(rightn, mid + 1, end, left, right)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    A.resize(N + 1);
    tree.resize(N * 4);
    lazy.assign(N * 4, { 1, 0 });

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

        if (1 <= cmd && cmd <= 3)
        {
            int x, y, v;
            cin >> x >> y >> v;

            int mult = 1, plus = 0;

            if (cmd == 1)
            {
                plus = v;
            }
            else if (cmd == 2)
            {
                mult = v;
            }
            else if (cmd == 3)
            {
                mult = 0;
                plus = v;
            }

            lazyUpdateTree(1, 1, N, x, y, mult, plus);
        }
        else if (cmd == 4)
        {
            int x, y;
            cin >> x >> y;

            cout << query(1, 1, N, x, y) << '\n';
        }
    }

    return 0;
}
