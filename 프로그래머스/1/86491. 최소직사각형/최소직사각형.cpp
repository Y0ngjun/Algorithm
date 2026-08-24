#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int w = 0;
    int h = 0;

    for (const auto& v : sizes)
    {
        w = max(w, max(v[0], v[1]));
        h = max(h, min(v[0], v[1]));
    }

    return w * h;
}
