// BOJ 10999. 구간 합 구하기 2
#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> tree;
vector<long long> lazy;

void initTree(int node, int left, int right)
{
    if (left == right)
    {
        tree[node] = arr[left];
        return;
    }

    initTree(node * 2, left, (left + right) / 2);
    initTree(node * 2 + 1, (left + right) / 2 + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void propagate(int node, int left, int right)
{
    tree[node * 2] += lazy[node] * ((left + right) / 2 - left + 1);
    lazy[node * 2] += lazy[node];

    tree[node * 2 + 1] += lazy[node] * (right - ((left + right) / 2 + 1) + 1);
    lazy[node * 2 + 1] += lazy[node];

    lazy[node] = 0;
}

void updateTree(int node, int left, int right, int b, int c, long long d)
{
    if (c < left || b > right)
    {
        return;
    }

    if (left == right)
    {
        tree[node] += d;
        return;
    }

    if (b <= left && right <= c)
    {
        tree[node] += d * (right - left + 1);
        lazy[node] += d;
        return;
    }

    propagate(node, left, right);
    updateTree(node * 2, left, (left + right) / 2, b, c, d);
    updateTree(node * 2 + 1, (left + right) / 2 + 1, right, b, c, d);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int b, int c)
{
    if (c < left || b > right)
    {
        return 0ll;
    }

    if (b <= left && right <= c)
    {
        return tree[node];
    }

    propagate(node, left, right);

    long long sum = 0;
    sum += query(node * 2, left, (left + right) / 2, b, c);
    sum += query(node * 2 + 1, (left + right) / 2 + 1, right, b, c);

    return sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.assign(N * 4, 0);
    lazy.assign(N * 4, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    initTree(1, 1, N);

    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            long long d;
            cin >> d;

            updateTree(1, 1, N, b, c, d);
        }
        else if (a == 2)
        {
            cout << query(1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}
