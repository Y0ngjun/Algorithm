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
        for (int ll = 0, rr = ll + len - 1; rr < numOfnums; ll++, rr++)
        {
            for (int lr = ll, rl = lr + 1; lr < rr; lr++, rl++)
            {
                if (arr[lr * 2 + 1] == "+")
                {
                    biggest[ll][rr] = max(biggest[ll][rr],
                        biggest[ll][lr] + biggest[rl][rr]);
                    smallest[ll][rr] = min(smallest[ll][rr],
                        smallest[ll][lr] + smallest[rl][rr]);
                }
                else
                {
                    biggest[ll][rr] = max(biggest[ll][rr],
                        biggest[ll][lr] - smallest[rl][rr]);
                    smallest[ll][rr] = min(smallest[ll][rr],
                        smallest[ll][lr] - biggest[rl][rr]);
                }
            }
        }
    }

    return biggest[0][numOfnums - 1];
}
