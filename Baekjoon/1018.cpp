#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char chessBoard[51][51];
	for (int i = 0; i < n; i++)
	{
		cin >> chessBoard[i];
	}
	int min = 64;
	for (int i = 0; i < n - 7; ++i)
	{
		for (int j = 0; j < m - 7; ++j)
		{
			int count = 0;
			for (int y = i; y < i + 8; ++y)
			{
				for (int x = j; x < j + 8; ++x)
				{
					if ((x+y) % 2)
					{
						if (chessBoard[y][x] == 'W')
							count++;
					}
					else
					{
						if (chessBoard[y][x] == 'B')
							count++;
					}
				}
			}
			count = (count < (64 - count) ? count : (64 - count));
			min = (count < min ? count : min);
		}
	}
	cout << min;
	return 0;
}