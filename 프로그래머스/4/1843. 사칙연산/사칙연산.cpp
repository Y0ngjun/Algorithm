#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int solution(vector<string> arr)
{
    int n = arr.size();
    int numOfnums = n / 2 + 1;

    vector<vector<int>> biggest(numOfnums, vector<int>(numOfnums, INT_MIN));
    vector<vector<int>> smallest(numOfnums, vector<int>(numOfnums, INT_MAX));

    for (int i = 0; i < numOfnums; i++)
    {
        int num = stoi(arr[i * 2]);
        biggest[i][i] = num;
        smallest[i][i] = num;
    }

    for (int len = 2; len <= numOfnums; len++)
    {
        for (int start = 0; start + len <= numOfnums; start++)
        {
            for (int left = 1; left < len; left++)
            {
                int right = len - left;

                if (arr[(start + left) * 2 - 1] == "+")
                {
                    biggest[start][start + len - 1] = max(biggest[start][start + len - 1],
                        biggest[start][start + left - 1] + biggest[start + left][start + len - 1]);
                    smallest[start][start + len - 1] = min(smallest[start][start + len - 1],
                        smallest[start][start + left - 1] + smallest[start + left][start + len - 1]);
                }
                else
                {
                    biggest[start][start + len - 1] = max(biggest[start][start + len - 1],
                        biggest[start][start + left - 1] - smallest[start + left][start + len - 1]);
                    smallest[start][start + len - 1] = min(smallest[start][start + len - 1],
                        smallest[start][start + left - 1] - biggest[start + left][start + len - 1]);
                }
            }
        }
    }

    return biggest[0][numOfnums - 1];
}
