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

// ����1, ����2
// ����1 �Ǵ� 2�� ������ ��1 �Ǵ� 2�� ���� ���� ��ǥ�� �����Ѵ�.
// ����3�� ������
// ���ݱ����� ���̸� ��� �Ѵ�. min(start) ���� max(end) ����
// ��1 �� ��2�� �� ���� ��ǥ������ ������ �������
// ���� ��1�� �� �۴ٸ� ����2�� ��1 + 1�̵ȴ�
// ����1�� ��1�� ������ǥ�� �ȴ�
// ������ ������ ���� ���̸� ����Ѵ�.
// ������ �ִ밪�� ����Ѵ�.