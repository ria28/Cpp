#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums.empty() || nums.size() < 3)
        {
            return output;
        }

        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1;
            int high = nums.size() - 1;
            int sum = 0 - nums[i];
            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> list{nums[i], nums[low], nums[high]};
                    output.push_back(list);
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
    return output;
}

int threeSumClosest(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n < 3)
        return 0;
    int closest = arr[0] + arr[1] + arr[2];
    int o_dif = INT_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        int low = i + 1;
        int high = n - 1;
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        while (low < high)
        {
            int sum = arr[i] + arr[low] + arr[high];
            if (abs(target - sum) < abs(target - closest))
                closest = sum;
            if (sum < target)
                low++;
            else
                high--;
        }
    }
    return closest;
}

int threeSumMulti(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int ans = 0;
    int M = 1e9 + 7;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums.empty() || nums.size() < 3)
        {
            return 0;
        }

        // if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        // {
        int low = i + 1;
        int high = nums.size() - 1;
        int sum = target - nums[i];
        while (low < high)
        {
            if (nums[low] + nums[high] == sum)
            {
                // vector<int> list{nums[i], nums[low], nums[high]};
                int cnt_l = 1;
                int cnt_r = 1;
                while (low < high && nums[low] == nums[low + 1])
                {
                    cnt_l++;
                    low++;
                }
                while (low < high && nums[high] == nums[high - 1])
                {
                    cnt_r++;
                    high--;
                }
                if (low == high)
                    ans = (ans + cnt_l * (cnt_l - 1) / 2) % M;
                else
                    ans = (ans + cnt_l * cnt_r) % M;
                low++;
                high--;
            }
            else if (nums[low] + nums[high] < sum)
                low++;
            else
                high--;
        }
        // }
    }
    return ans;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vi arr = {-1, 2, 1, -4};
        cout << threeSumClosest(arr, 1);
        return 0;
    }