/*
0 ~ 10 까지 라이언이 점수를 얻거나 or 못얻거나 2^11 = 2048가지
*/
#include <vector>

using namespace std;

void backtracking(int n, const vector<int>& info, vector<int>& answer, vector<int>& record, int& maxgap, int step)
{
    if (n < 0)
        return;

    if (step == 11)
    {
        int ryan = 0;
        int apeach = 0;

        for (int i = 0; i < 10; i++)
        {
            if (record[i] > info[i])
                ryan += 10 - i;
            else if (info[i] > record[i])
                apeach += 10 - i;
        }

        int gap = ryan - apeach;

        if (gap > maxgap)
        {
            maxgap = gap;

            record[10] = n;
            answer = record;
            record[10] = 0;
        }

        return;
    }

    record[10 - step] = info[10 - step] + 1;
    backtracking(n - (info[10 - step] + 1), info, answer, record, maxgap, step + 1);
    record[10 - step] = 0;
    backtracking(n, info, answer, record, maxgap, step + 1);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer = { -1 };
    vector<int> record(11, 0);
    int maxgap = 0;

    backtracking(n, info, answer, record, maxgap, 1);

    return answer;
}
