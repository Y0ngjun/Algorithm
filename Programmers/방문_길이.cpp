#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string dirs)
{
	int answer = 0;
	set<pair<pair<int, int>, pair<int, int>>> visited;

	int y = 0, x = 0;
	for (char c : dirs)
	{
		int ny = y, nx = x;
		if (c == 'U')
			ny += 1;
		else if (c == 'D')
			ny -= 1;
		else if (c == 'R')
			nx += 1;
		else if (c == 'L')
			nx -= 1;

		if (ny > 5 || nx > 5 || ny < -5 || nx < -5)
			continue;

		if (visited.count({ {y,x},{ny,nx} }) == 0)
		{
			answer += 1;
			visited.insert({ {y,x},{ny,nx} });
			visited.insert({ {ny,nx},{y,x}, });
		}

		y = ny, x = nx;
	}

	return answer;
}