#include <string>
#include <algorithm>

using namespace std;

int DFS(string& curr, const string& word, const string& ref, int& i)
{
    if (curr == word) return i;
    if (curr.length() == 5) return 0;

    for (char c : ref)
    {
        curr.push_back(c);
        int temp = DFS(curr, word, ref, ++i);
        if (temp) return temp;
        curr.pop_back();
    }

    return 0;
}

int solution(string word)
{
    string curr = "";
    int i = 0;

    return DFS(curr, word, "AEIOU", i);
}
