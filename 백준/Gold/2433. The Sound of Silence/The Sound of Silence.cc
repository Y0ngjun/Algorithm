// BOJ 2433. The Sound of Silence

#include <iostream>

#include <vector>

#include <algorithm>

#include <deque>

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    int n, m, c;

    cin >> n >> m >> c;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)

    {

        cin >> a[i];

    }

    deque<int> maxDQ;

    deque<int> minDQ;

    vector<int> silence;

    for (int i = 1; i <= n; i++)

    {

        while (!maxDQ.empty() && maxDQ.front() + m <= i)

        {

            maxDQ.pop_front();

        }

        while (!minDQ.empty() && minDQ.front() + m <= i)

        {

            minDQ.pop_front();

        }

        while (!maxDQ.empty() && a[maxDQ.back()] <= a[i])

        {

            maxDQ.pop_back();

        }

        while (!minDQ.empty() && a[minDQ.back()] >= a[i])

        {

            minDQ.pop_back();

        }

        maxDQ.push_back(i);

        minDQ.push_back(i);

        int maxVal = a[maxDQ.front()];

        int minVal = a[minDQ.front()];

        if (i >= m && maxVal - minVal <= c)

        {

            silence.push_back(i - m + 1);

        }

    }

    if (silence.size() == 0)

    {

        cout << "NONE" << '\n';

    }

    else

    {

        for (int i : silence)

        {

            cout << i << '\n';

        }

    }

    return 0;

}