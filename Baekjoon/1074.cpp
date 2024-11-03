#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 2^n * 2^n 칸에서 Z자로 순회할 때 r행, c열에는 몇번째로 방문하는가.
	// 현재 보드를 좌상단 점의 위치와 한 변의 크기(2^z)로 나타낸다.
	// 카운트 = 0으로 시작한다.
	// n > 1 인 경우 n의 위치가 좌상단, 우상단, 좌하단, 우하단으로 나뉜다.
	// 각 각 0, (2^(n-1))^2, (2^(n-1))^2*2, (2^(n-1))^2*3 을 카운트에 더한다.
	// n이 1인경우 카운트에 1, 2, 3, 4를 더한다.

	int n, r, c;
	cin >> n >> r >> c;

	int x = 0, y = 0, z = n, count = 0;
	while (z > 0)
	{
		int size = pow(2, z);
		int midX = x + size / 2;
		int midY = y + size / 2;
		if (z > 1)
		{
			if (c < midX)
			{
				// 좌상단
				if (r < midY)
				{

				}
				// 좌하단
				else
				{
					count += size * size / 2;
					y = midY;
				}
			}
			else
			{
				// 우상단
				if (r < midY)
				{
					count += size * size / 4;
					x = midX;
				}
				// 우하단
				else
				{
					count += size * size / 4 * 3;
					x = midX;
					y = midY;
				}
			}
		}
		else if (z == 1)
		{
			if (c == x)
			{
				if (r != y)
					count += 2;
			}
			else
			{
				if (r == y)
					count += 1;
				else
					count += 3;
			}
		}
		--z;
	}
	cout << count;
	return 0;
}

