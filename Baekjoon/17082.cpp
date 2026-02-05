// BOJ 17082. 쿼리와 쿼리
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    vector<int> l(M);
    for (int i = 0; i < M; i++)
        cin >> l[i];

    vector<int> r(M);
    for (int i = 0; i < M; i++)
        cin >> r[i];

    vector<pair<int, int>> query(Q);
    for (int i = 0; i < Q; i++)
        cin >> query[i].first >> query[i].second;

    // 계산 시작
    vector<int> ans(Q);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    // 예외 처리
    for (int i = 0; i < M; i++)
    {
        if (l[i] > r[i])
        {
            for (int i = 0; i < Q; i++)
                cout << (int)1e9 << '\n';

            return 0;
        }
    }

    // 최적의 합집합 전처리
    vector<int> isInSet(N + 1, 0);
    for (int i = l[0]; i <= r[0]; i++)
        isInSet[i] = 1;

    for (int i = 1; i < M; i++)
    {
        int s = l[i], e = r[i];

        if (s <= r[i - 1])
            s = r[i - 1] + 1;

        for (int j = s; j <= e; j++)
            isInSet[j] = 1;
    }

    // 집합 초기화
    multiset<int> ms;
    for (int i = 1; i <= N; i++)
    {
        if (isInSet[i] == 1)
        {
            ms.insert(a[i]);
        }
    }

    // 쿼리
    for (int q = 0; q < Q; q++)
    {
        int max_val = 1e9;
        int i_idx = query[q].first, j_idx = query[q].second;

        // i, j의 집합 포함 여부가 다르다면 집합을 업데이트
        if (isInSet[i_idx] != isInSet[j_idx])
        {
            if (isInSet[i_idx] == 1)
            {
                ms.erase(ms.find(a[i_idx]));
                ms.insert(a[j_idx]);
            }
            else
            {
                ms.insert(a[i_idx]);
                ms.erase(ms.find(a[j_idx]));
            }
        }

        swap(a[i_idx], a[j_idx]);
        ans[q] = *(--ms.end());
    }

    // 출력
    for (int i = 0; i < Q; i++)
        cout << ans[i] << '\n';

    return 0;
}
