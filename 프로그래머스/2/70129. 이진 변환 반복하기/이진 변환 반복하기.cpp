#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(string s)
{
    int cnt = 0;
    int zero = 0;

    while (s != "1")
    {
        cnt++;

        int num = 0;
        for (char ch : s)
        {
            if (ch == '1')
                num++;
            else
                zero++;
        }

        stack<char> stk;
        while (num > 0)
        {
            stk.push(num % 2 + '0');
            num /= 2;
        }

        string temp = "";
        while (!stk.empty())
        {
            temp += stk.top();
            stk.pop();
        }

        s = temp;
    }

    return { cnt, zero };
}
