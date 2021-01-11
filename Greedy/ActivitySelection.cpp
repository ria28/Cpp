#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
void activitySel(vector<pair<int, int>> &schedule)
{
    sort(schedule.begin(), schedule.end());
    // print the no of max activities that can be performed by a person one actv at a time
    int actv = 1;             // we assume first activity performed obv
    int finish_last_time = 0; // what was the finishing time of the last activity
    for (int i = 1; i < schedule.size(); i++)
    {
        if (schedule[i].second >= schedule[finish_last_time].first) // next actvty can only be started if its starting time is > = finishing time of the last activity
        {
            actv++;
            finish_last_time = i;
        }
    }
    cout << actv << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    vector<pair<int, int>> schedule;
    for (int i = 0; i < start.size(); i++)
        schedule.push_back(make_pair(finish[i], start[i]));
    // pair { finish time, start time}  ------> why because we need to sort on the basis of finish time

    activitySel(schedule);
    return 0;
}