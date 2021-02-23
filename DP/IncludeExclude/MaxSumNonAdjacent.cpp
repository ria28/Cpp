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

// find max sum of the subset such that there should be no adjacent elements of array
void maxSum(vector<int> &arr)
{
    int prev_inc = 0;
    int prev_exc = 0;
    int next_inc, next_exc;

    for (int i = 0; i < arr.size(); i++)
    {
        next_inc = prev_exc + arr[i];
        next_exc = max(prev_inc, prev_exc);
        prev_inc = next_inc;
        prev_exc = next_exc;
        cout << next_inc << " " << next_exc << "\n";
    }
    cout << "maximum sum "<<max(next_inc, next_exc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {5, 10, 10, 100, 5, 6};
    maxSum(arr);
    return 0;
}