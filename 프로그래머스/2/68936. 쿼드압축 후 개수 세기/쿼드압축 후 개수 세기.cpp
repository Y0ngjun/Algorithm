#include <string>
#include <vector>

using namespace std;

pair<int, int>& operator+=(pair<int, int>& a, const pair<int, int>& b)
{
    a.first += b.first;
    a.second += b.second;
    return a;
}

pair<int, int> compress(const vector<vector<int>>& arr, int row, int col, int size)
{
    if (size == 1)
    {
        if (arr[row][col]) return { 0, 1 };
        return { 1, 0 };
    }

    pair<int, int> ret(0, 0);
    int newSize = size / 2;
    ret += compress(arr, row, col, newSize);
    ret += compress(arr, row, col + newSize, newSize);
    ret += compress(arr, row + newSize, col, newSize);
    ret += compress(arr, row + newSize, col + newSize, newSize);

    if (ret.first == 0) return { 0, 1 };
    if (ret.second == 0) return { 1,0 };
    return ret;
}

vector<int> solution(vector<vector<int>> arr)
{
    pair<int, int> temp = compress(arr, 0, 0, arr.size());
    return { temp.first, temp.second };
}