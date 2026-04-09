// BOJ 18185. 라면 사기 (Small)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 2);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // i+1 > i+2 라면 i, i+1을 묶어서 사도 손해가 아님
    // 5(i, i+1) + 5(i+1, i+2) = 3(i+1) + 7(i, i+1, i+2)

    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int two = min(A[i], max(0, A[i + 1] - A[i + 2]));
        A[i] -= two;
        A[i + 1] -= two;
        answer += two * 5;

        int three = min({ A[i], A[i + 1], A[i + 2] });
        A[i] -= three;
        A[i + 1] -= three;
        A[i + 2] -= three;
        answer += three * 7;

        int one = A[i];
        A[i] -= one;
        answer += one * 3;
    }

    cout << answer;

    return 0;
}
