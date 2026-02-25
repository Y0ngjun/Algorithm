// BOJ 12858. Range GCD
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> A;              // 원본 배열
vector<int> D;              // 차분 배열
vector<long long> addTree;  // 더해진 기록을 저장하는 트리
vector<long long> gcdTree;  // 차분값의 gcd를 저장하는 트리

void initAddTree(int node, int start, int end)
{
    if (start == end)
    {
        addTree[node] = A[start];
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    initAddTree(leftNode, start, mid);
    initAddTree(rightNode, mid + 1, end);
}

void updateAddTree(int node, int start, int end, int T, int A, int B)
{
    if (B < start || end < A)
    {
        return;
    }

    if (A <= start && end <= B)
    {
        addTree[node] += T;
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    updateAddTree(leftNode, start, mid, T, A, B);
    updateAddTree(rightNode, mid + 1, end, T, A, B);
}

long long queryAddTree(int node, int start, int end, int k)
{
    if (k < start || end < k)
    {
        return 0ll;
    }

    if (start == end)
    {
        return addTree[node];
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    return addTree[node] + queryAddTree(leftNode, start, mid, k) + queryAddTree(rightNode, mid + 1, end, k);
}

void initGcdTree(int node, int start, int end)
{
    if (start == end)
    {
        gcdTree[node] = D[start];
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    initGcdTree(leftNode, start, mid);
    initGcdTree(rightNode, mid + 1, end);

    gcdTree[node] = gcd(gcdTree[leftNode], gcdTree[rightNode]);
}

void updateGcdTree(int node, int start, int end, int k, int T)
{
    if (k < start || end < k)
    {
        return;
    }

    if (start == end)
    {
        gcdTree[node] += T;
        return;
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    updateGcdTree(leftNode, start, mid, k, T);
    updateGcdTree(rightNode, mid + 1, end, k, T);

    gcdTree[node] = gcd(gcdTree[leftNode], gcdTree[rightNode]);
}

long long queryGcdTree(int node, int start, int end, int A, int B)
{
    if (B < start || end < A)
    {
        return 0ll;
    }

    if (A <= start && end <= B)
    {
        return gcdTree[node];
    }

    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (start + end) / 2;

    return gcd(queryGcdTree(leftNode, start, mid, A, B), queryGcdTree(rightNode, mid + 1, end, A, B));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    A.resize(N + 1);
    D.resize(N + 1);
    addTree.resize(N * 4);
    gcdTree.resize(N * 4);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        D[i] = A[i] - A[i - 1];
    }

    initAddTree(1, 1, N);
    initGcdTree(1, 1, N);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int T, A, B;
        cin >> T >> A >> B;

        if (T == 0)
        {
            if (A == B)
            {
                cout << queryAddTree(1, 1, N, A) << '\n';
            }
            else
            {
                cout << gcd(queryAddTree(1, 1, N, A), queryGcdTree(1, 1, N, A + 1, B)) << '\n';
            }
        }
        else
        {
            updateAddTree(1, 1, N, T, A, B);
            updateGcdTree(1, 1, N, A, T);
            updateGcdTree(1, 1, N, B + 1, -T);
        }
    }

    return 0;
}
