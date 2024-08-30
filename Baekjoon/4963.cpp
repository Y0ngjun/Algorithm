#include <stack>
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::pair<int, int> dir[8] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

	while (true)
	{
		int w, h;
		std::cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		// 지도
		bool** map = new bool* [h];
		for (int i = 0; i < h; ++i)
		{
			map[i] = new bool[w] {};
		}

		// 방문
		bool** check = new bool* [h];
		for (int i = 0; i < h; ++i)
		{
			check[i] = new bool[w] {};
		}

		// 입력
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
				std::cin >> map[i][j];
		}

		// 탐색
		int count = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 0 || check[i][j] == 1)
					continue;

				count++;
				check[i][j] = 1;

				std::stack<std::pair<int, int>> stk;
				stk.push({ i,j });

				while (!stk.empty())
				{
					int y = stk.top().first;
					int x = stk.top().second;
					stk.pop();
					for (int k = 0; k < 8; ++k)
					{
						int ny = y + dir[k].first;
						int nx = x + dir[k].second;
						// 맵 바깥
						if (ny<0 || ny>h - 1 || nx<0 || nx>w - 1)
							continue;
						if (!map[ny][nx])
							continue;
						// 방문 경험, 바다
						if (check[ny][nx])
							continue;
						check[ny][nx] = 1;
						// ny, nx 기준으로 순회 하게 됨
						stk.push({ ny,nx });
					}

				}
			}
		}

		std::cout << count << '\n';

		// 해제
		for (int i = 0; i < h; ++i)
		{
			delete[] map[i];
		}
		delete[] map;

		for (int i = 0; i < h; ++i)
		{
			delete[] check[i];
		}
		delete[] check;
	}

	return 0;
}