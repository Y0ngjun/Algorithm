#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    int dy = r - x; // 1
    int dx = c - y; // -2
    int dist = abs(dy) + abs(dx); // 3
    int remain = k - dist; // 2

    if (dist > k || remain % 2)
    {
        return "impossible";
    }

    int Y = x, X = y;
    string answer = "";
    for (int i = 0; i < k; i++)
    {
        if (Y < n && Y < r)
        {
            answer += 'd';
            Y++;
        }
        else if (Y < n && remain > 0)
        {
            answer += 'd';
            Y++;
            remain -= 2;
        }
        else if (X > 1 && X > c)
        {
            answer += 'l';
            X--;
        }
        else if (X > 1 && remain > 0)
        {
            answer += 'l';
            X--;
            remain -= 2;
        }
        else if (X < m && X < c)
        {
            answer += 'r';
            X++;
        }
        else if (X < m && remain > 0)
        {
            answer += 'r';
            X++;
            remain -= 2;
        }
        else if (Y > 1 && Y > r)
        {
            answer += 'u';
            Y--;
        }
        else if (Y > 1 && remain > 0)
        {
            answer += 'u';
            Y--;
            remain -= 2;
        }
    }

    return answer;
}
