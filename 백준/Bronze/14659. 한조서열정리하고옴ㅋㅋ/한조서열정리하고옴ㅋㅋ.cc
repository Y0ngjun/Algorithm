#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int answer = 0;
    int pivot = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;

        if (h > pivot)
        {
            answer = max(answer, count);
            pivot = h;
            count = 0;
        }
        else
        {
            count++;
            answer = max(answer, count);
        }
    }

    cout << answer;

    return 0;
}
