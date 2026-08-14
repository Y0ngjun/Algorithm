#include <vector>
#include <algorithm>

// A 정렬, B 정렬 후
// A 순회:
// A보다 큰 가장 작은 B를 탐색
// A or B가 범위를 벗어나면 종료

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0;
    int j = 0;
    int n = A.size();
    int m = B.size();
    int answer = 0;

    while (i < n && j < m)
    {
        if (A[i] >= B[j])
        {
            j++;
            continue;
        }

        i++;
        j++;
        answer++;
    }

    return answer;
}
