#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int val1 = static_cast<int>(nums.size() / 2);
    int val2 = static_cast<int>(unique(nums.begin(), nums.end()) - nums.begin());
    return min(val1, val2);
}
