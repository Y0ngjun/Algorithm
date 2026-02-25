// BOJ 12858. Range GCD
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> arr;            // 원본 배열
vector<long long> leftVal;  // 구간의 첫 번째 노드의 값
vector<long long> rightVal; // 구간의 첫 번째 노드를 제외한 값들의 gcd
vector<long long> tree;     // 구간의 gcd
vector<long long> lazy;     // lazy 값

long long myGcd(long long a, long long b)
{
    if (a == -1)
        return abs(b);

    if (b == -1)
        return abs(a);

    return gcd(abs(a), abs(b));
}

void initTree(int node, int start, int end)
{
    if (start == end)
    {
        leftVal[node] = arr[start];
        rightVal[node] = -1;
        tree[node] = arr[start];
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    initTree(leftNode, start, mid);
    initTree(rightNode, mid + 1, end);

    leftVal[node] = leftVal[leftNode];
    rightVal[node] = myGcd(rightVal[leftNode], tree[rightNode]);
    tree[node] = myGcd(leftVal[node], rightVal[node]);
}

void updateLazy(int node, int start, int end)
{
    if (lazy[node] == 0)
    {
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    leftVal[leftNode] += lazy[node];
    leftVal[rightNode] += lazy[node];

    tree[leftNode] = myGcd(leftVal[leftNode], rightVal[leftNode]);
    tree[rightNode] = myGcd(leftVal[rightNode], rightVal[rightNode]);

    lazy[leftNode] += lazy[node];
    lazy[rightNode] += lazy[node];
    lazy[node] = 0;
}

void updateTree(int node, int start, int end, int T, int A, int B)
{
    if (B < start || end < A)
    {
        return;
    }

    if (A <= start && end <= B)
    {
        leftVal[node] += T;
        tree[node] = myGcd(leftVal[node], rightVal[node]);
        lazy[node] += T;
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    updateLazy(node, start, end);
    updateTree(leftNode, start, mid, T, A, B);
    updateTree(rightNode, mid + 1, end, T, A, B);

    leftVal[node] = leftVal[leftNode];
    rightVal[node] = myGcd(rightVal[leftNode], tree[rightNode]);
    tree[node] = myGcd(leftVal[node], rightVal[node]);
}

int query(int node, int start, int end, int A, int B)
{
    if (B < start || end < A)
    {
        return -1;
    }

    if (A <= start && end <= B)
    {
        return tree[node];
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    updateLazy(node, start, end);

    return myGcd(query(leftNode, start, mid, A, B), query(rightNode, mid + 1, end, A, B));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    arr.resize(N + 1);
    leftVal.resize(N * 4);
    rightVal.resize(N * 4);
    tree.resize(N * 4);
    lazy.resize(N * 4);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    initTree(1, 1, N);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 0)
        {
            cout << query(1, 1, N, A, B) << '\n';
        }
        else
        {
            updateTree(1, 1, N, T, A, B);
        }
    }

    return 0;
}
