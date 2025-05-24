#include <iostream>
#include <vector>

using namespace std;

// È¦¼ö: a, Â¦¼ö: b, ±¸¸Û: c

char board[512][512][2][2];

void tromino(int y, int x, int size, int a, int b, int aa, int bb)
{
	if (size == 1)
	{
		char color = ((y + x) % 2) ? 'a' : 'b';

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				board[y][x][i][j] = color;
		board[y][x][aa][bb] = 'c';
	}
	else
	{
		int nsize = size / 2;
		int ymid = y + nsize;
		int xmid = x + nsize;
		if (a < ymid)
		{
			if (b < xmid)
			{
				tromino(y, x, nsize, a, b, aa, bb);
				tromino(y, xmid, nsize, ymid - 1, xmid, 1, 0);
				tromino(ymid, x, nsize, ymid, xmid - 1, 0, 1);
				tromino(ymid, xmid, nsize, ymid, xmid, 0, 0);
			}
			else
			{
				tromino(y, x, nsize, ymid - 1, xmid - 1, 1, 1);
				tromino(y, xmid, nsize, a, b, aa, bb);
				tromino(ymid, x, nsize, ymid, xmid - 1, 0, 1);
				tromino(ymid, xmid, nsize, ymid, xmid, 0, 0);
			}
		}
		else
		{
			if (b < xmid)
			{
				tromino(y, x, nsize, ymid - 1, xmid - 1, 1, 1);
				tromino(y, xmid, nsize, ymid - 1, xmid, 1, 0);
				tromino(ymid, x, nsize, a, b, aa, bb);
				tromino(ymid, xmid, nsize, ymid, xmid, 0, 0);
			}
			else
			{
				tromino(y, x, nsize, ymid - 1, xmid - 1, 1, 1);
				tromino(y, xmid, nsize, ymid - 1, xmid, 1, 0);
				tromino(ymid, x, nsize, ymid, xmid - 1, 0, 1);
				tromino(ymid, xmid, nsize, a, b, aa, bb);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, k;
	cin >> t >> k;

	int size = (1 << (k - 1));

	while (t--)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		int aa = a % 2, bb = b % 2;
		a = a / 2;
		b = b / 2;

		tromino(0, 0, size, a, b, aa, bb);
		board[a][b][aa][bb] = '@';

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < size; ++k)
				{
					for (int l = 0; l < 2; ++l)
					{
						cout << board[i][k][j][l];
					}
				}
				cout << '\n';
			}
		}
	}

	return 0;
}