#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    int left = -(board[0] - 1) / 2;
    int right = (board[0] - 1) / 2;
    int up = (board[1] - 1) / 2;
    int down = -(board[1] - 1) / 2;

    unordered_map<string, pair<int, int>> move;
    move["left"] = { -1, 0 };
    move["right"] = { 1, 0 };
    move["up"] = { 0, 1 };
    move["down"] = { 0, -1 };

    int x = 0;
    int y = 0;

    for (const string& key : keyinput)
    {
        int nx = x + move[key].first;
        int ny = y + move[key].second;

        if (nx < left || nx > right || ny < down || ny >up)
            continue;

        x = nx;
        y = ny;
    }

    return { x, y };
}
