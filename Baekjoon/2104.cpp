// BOJ 2104 부분배열 고르기
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N + 2);
    A[0] = A[N + 1] = 0;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    vector<long long> prefixSum(N + 2);
    prefixSum[0] = 0;
    for (int i = 1; i <= N + 1; i++)
        prefixSum[i] = prefixSum[i - 1] + A[i];

    long long maxScore = 0;

    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= N + 1; i++)
    {
        while (A[stk.top()] > A[i])
        {
            int lowest = A[stk.top()];
            stk.pop();

            // (stk.top(), i - 1] 의 구간을 계산
            long long sum = prefixSum[i - 1] - prefixSum[stk.top()];
            long long score = sum * lowest;
            maxScore = max(maxScore, score);
        }

        stk.push(i);
    }

    cout << maxScore;

    return 0;
}
