#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int max_len = 0;
	int fruit1 = -1, start1 = -1, end1 = -1;
	int fruit2 = -1, start2 = -1, end2 = -1;
	for (int i = 0; i < n; ++i)
	{
		int fruit;
		cin >> fruit;
		if (fruit == fruit1)
		{
			end1 = i;
		}
		else if (fruit == fruit2)
		{
			end2 = i;
		}
		else
		{
			if (fruit1 == -1)
			{
				fruit1 = fruit;
				start1 = i;
				end1 = i;
				continue;
			}
			else if (fruit2 == -1)
			{
				fruit2 = fruit;
				start2 = i;
				end2 = i;
				continue;
			}
			int st = start2 == -1 ? start1 : (start1 < start2 ? start1 : start2);
			int ed = end2 == -1 ? end1 : (end1 > end2 ? end1 : end2);
			int le = ed - st + 1;
			max_len = le > max_len ? le : max_len;
			if (end1 < end2)
			{
				start2 = end1 + 1;
				fruit1 = fruit;
				start1 = i;
				end1 = i;
			}
			else
			{
				start1 = end2 + 1;
				fruit2 = fruit;
				start2 = i;
				end2 = i;
			}
		}
	}
	int st = start2 == -1 ? start1 : (start1 < start2 ? start1 : start2);
	int ed = end2 == -1 ? end1 : (end1 > end2 ? end1 : end2);
	int le = ed - st + 1;
	max_len = le > max_len ? le : max_len;

	cout << max_len;

	return 0;
}

// 과일1, 과일2
// 과일1 또는 2가 들어오면 끝1 또는 2의 값을 현재 좌표로 수정한다.
// 과일3이 들어오면
// 지금까지의 길이를 계산 한다. min(start) 부터 max(end) 까지
// 끝1 과 끝2중 더 작은 좌표까지의 과일을 모두제거
// 만약 끝1이 더 작다면 시작2는 끝1 + 1이된다
// 시작1과 끝1은 현재좌표가 된다
// 루프가 끝나고 현재 길이를 계산한다.
// 길이의 최대값을 출력한다.