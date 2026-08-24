#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(scoville.begin(), scoville.end());

    int cnt = 0;

    while (minHeap.size() >= 2 && minHeap.top() < K)
    {
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int mix = first + second * 2;
        minHeap.push(mix);

        cnt++;
    }

    if (minHeap.top() >= K)
    {
        return cnt;
    }
    else
    {
        return -1;
    }
}
