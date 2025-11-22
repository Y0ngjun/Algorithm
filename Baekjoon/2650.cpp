// BOJ 2650 교차점개수
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool crossLine(pair<int, int> l1, pair<int, int> l2)
{
    if ((l1.first < l2.first && l2.first < l1.second) != (l1.first < l2.second && l2.second < l1.second))
    {
        return true;
    }

    return false;
}

int pairToInt(pair<int, int> p)
{
    int Int = 0;

    if (p.first == 1)
    {
        Int += p.second;
    }
    else if (p.first == 2)
    {
        Int += 100 + (51 - p.second);
    }
    else if (p.first == 3)
    {
        Int += 150 + (51 - p.second);
    }
    else if (p.first == 4)
    {
        Int += 50 + p.second;
    }

    return Int;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    N /= 2;

    vector<pair<int, int>> lines(N);
    vector<int> cross(N, 0);

    for (int i = 0; i < N; i++)
    {
        pair<int, int> u, v;
        cin >> u.first >> u.second >> v.first >> v.second;

        int uInt = pairToInt(u), vInt = pairToInt(v);

        if (uInt > vInt)
        {
            int temp = uInt;
            uInt = vInt;
            vInt = temp;
        }

        lines[i] = pair<int, int>(uInt, vInt);

        for (int j = 0; j < i; ++j)
        {
            if (crossLine(lines[i], lines[j]))
            {
                cross[i]++;
                cross[j]++;
            }
        }
    }

    int crossSum = 0, crossMax = 0;

    for (int i = 0; i < N; ++i)
    {
        crossSum += cross[i];
        crossMax = max(crossMax, cross[i]);
    }

    cout << crossSum / 2 << ' ' << crossMax << '\n';

    return 0;
}
