#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Job
{
    int num;
    int time_enqueued;
    int time_required;

    bool operator()(const Job& a, const Job& b)
    {
        if (a.time_required != b.time_required)
        {
            return a.time_required > b.time_required;
        }

        if (a.time_enqueued != b.time_enqueued)
        {
            return a.time_enqueued > b.time_enqueued;
        }

        return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs)
{
    int n = jobs.size();

    vector<Job> job_vec;
    for (int i = 0; i < n; i++)
    {
        job_vec.push_back({ i, jobs[i][0], jobs[i][1] });
    }

    sort(job_vec.begin(), job_vec.end(), [](const auto& a, const auto& b)
        {
            return a.time_enqueued < b.time_enqueued;
        });

    priority_queue<Job, vector<Job>, Job> pq;
    int t = 0;
    int i = 0;
    int sum = 0;

    while (i < n || !pq.empty())
    {
        while (i < n && job_vec[i].time_enqueued <= t)
        {
            pq.push(job_vec[i++]);
        }

        if (pq.empty())
        {
            t = job_vec[i].time_enqueued;
            continue;
        }

        Job job = pq.top();
        pq.pop();

        t += job.time_required;
        sum += t - job.time_enqueued;
    }

    return sum / n;
}
