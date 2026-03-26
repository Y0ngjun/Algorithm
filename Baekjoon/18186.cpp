// BOJ 18186. 라면 사기 (Large)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B, C;
    cin >> N >> B >> C;

    if (B <= C)
    {
        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;

            sum += num;
        }

        cout << sum * B;
        return 0;
    }

    vector<int> A(N + 2);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        int two = min(A[i], max(0, A[i + 1] - A[i + 2]));
        A[i] -= two;
        A[i + 1] -= two;
        answer += 1LL * two * (B + C);

        int three = min({ A[i], A[i + 1], A[i + 2] });
        A[i] -= three;
        A[i + 1] -= three;
        A[i + 2] -= three;
        answer += 1LL * three * (B + C * 2);

        int one = A[i];
        A[i] -= one;
        answer += 1LL * one * B;
    }

    cout << answer;
    return 0;
}
