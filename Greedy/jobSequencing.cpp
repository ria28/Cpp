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

struct Job
{
    char jobID;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

/* 
    JobID   Deadline  Profit
    a       2        100
    b       1        19
    c       2        27
    d       1        25
    e       3        15


    sorting on the basis of profit decreasing order....
    JobID   Deadline  Profit
    a       2        100
    c       2        27
    d       1        25
    b       1        19
    e       3        15

    we would schedule the job with max profit on the verge of deadline 
    time span----

    0----------1-----------2------------3
    | Job C    |    Job A  | Job E      |



    Example:
    JobID   Deadline  Profit
    a       2        100
    c       1        27             <<<<------------ suppose duration of c job is 1
    d       1        25
    b       1        19
    e       3        15

    timespan ---

    0----------1-----------2------------3
    |Job A     |           |    Job E   |     ---->>>>> not eficient 

    time from 1-----2 is empty not efficient. If we would have placed Job A towards the end of deadline
    then others jobs would have been performed and the profit would be more.
    
    0----------1-----------2------------3
    | Job C    |    Job A  | Job E      |
 */
void maxProfit(vector<Job> &arr)
{
    sort(arr.begin(), arr.end(), comparison);
    int n = arr.size();
    vector<bool> usedSlot(n, false);
    string ans = "";
    int profit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // job takes 1 sec to complete
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (!usedSlot[j])
            {
                usedSlot[j] = true;
                ans += arr[i].jobID;
                ans.append(" ");
                profit += arr[i].profit;
                break;
            }
        }
    }

    cout << ans << " " << profit << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Job> arr = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    maxProfit(arr);
    return 0;
}