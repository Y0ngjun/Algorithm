#include <vector>

using namespace std;

int zeroOneKnapsack(vector<pair<int, int>>& items, int weight)
{
	// pair<weight, value>

	vector<int> dp(weight + 1, 0);
	for (int item = 0; item < items.size(); ++item)
	{
		for (int cost = weight; cost >= items[item].first; --cost)
		{
			// 물건을 담았을 경우와 담지 않았을 경우
			dp[cost] = max(dp[cost], dp[cost - items[item].first] + items[item].second);
		}
	}

	return dp[weight];
}