#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int n = name.length();
    int updown = 0;

    // updown count
    for (char c : name)
    {
        updown += min(c - 'A', 'Z' - c + 1);
    }

    vector<int> points = { 0 };

    // non A points
    for (int i = 1; i < n; i++)
    {
        if (name[i] != 'A')
        {
            points.push_back(i);
        }
    }

    int m = points.size();
    // back - front interval
    int leftright = points.back() - points.front();

    // no leftright move
    if (m < 2)
    {
        return updown;
    }

    // check all interval i - (i - 1)
    // (i) --left-- (0) --right-- (i - 1)
    for (int i = 1; i < m; i++)
    {
        int left = n - points[i];
        int right = points[i - 1];
        int dist = min(left, right) * 2 + max(left, right);

        leftright = min(leftright, dist);
    }

    return updown + leftright;
}
