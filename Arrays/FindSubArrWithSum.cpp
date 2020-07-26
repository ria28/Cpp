#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 2 pointer Naive approch========================
void subArraySum(int arr[], int len, int sum)
{
    int curr_sum = 0;
    for (int i = 0; i < len; i++)
    {
        curr_sum = arr[i];
        for (int j = i + 1; j < len; j++)
        {
            if (curr_sum > sum)
            {

                break;
            }

            if (curr_sum == sum)
            {
                cout << "position indices" << i << "," << j;
                break;
            }
            curr_sum += arr[j];
        }
    }
}

// Window sliding approach ======================

void subArraySum2(int arr[], int n, int sum)
{
    int curr_sum = arr[0];
    int start = 0;
    for (int i = 1; i < n; i++)
    {
        while (curr_sum > sum && start <= i)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        if (curr_sum == sum)
        {
            cout << "position indices" << start << "," << i - 1;
        }

        curr_sum += arr[i];
    }
}

// Maximm sum of i*arr[i] among all rotations of a given array
int maxSum(int arr[], int n)
{
    int cum_sum = 0;
    for (int i = 0; i < n; i++)
        cum_sum += arr[i];

    int curr_val = 0;

    for (int i = 0; i < n; i++)
        curr_val += i * arr[i];

    int res = curr_val;
    for (int i = 1; i < n; i++)
    {
        int next_val = curr_val - (cum_sum - arr[i - 1]) + arr[i - 1] * (n - 1);
        curr_val = next_val;

        res = max(res, curr_val);
    }
    return res;
}

// Largest subarray with equal no of 0's and 1's =================================================================

int maxLen(int arr[], int n)
{
    unordered_map<int, int> counts;
    counts[0] = -1;
    int max_len = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count += -1;
        else
            count += 1;
        if (counts.find(count) != counts.end())
            max_len = max(max_len, i - counts[count]);
        else
            counts[count] = i;
    }

    return max_len;
}

//largest-sum-subarray-at-least-k-numbers=============================================================================
// https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/

void maxSumWithK(int arr[], int n, int k)
{
    int sum = arr[0];
    for (int i = 1; i < k; i++)
    {
        sum += arr[i];
    }

    for (int i = k; i < n; i++)
    {
        sum = max(max(sum + arr[i], sum + arr[i] - arr[i - k]), sum);
    }
    cout << sum;
}

// Subarray sum divisible by K==============================================================================
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    unordered_map<int, int> map;
    map[0] = 1;
    int cumm_sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cumm_sum += arr[i];
        int rem = cumm_sum % k;

        if (map.find(rem) != map.end())
        {
            ans = ans + map[rem];
            map[rem]++;
        }
        else
            map[rem] = 1;
    }

    return ans;
}

// Print all Subarray with 0 sum
// https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/

vector<pair<int, int>> findSubarrays(int arr[], int n)
{
    unordered_map<int, vector<int>> map;
    vector<pair<int, int>> output;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            output.push_back(make_pair(0, i));

        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];

            for (int j = 0; j < vc.size(); j++)
            {
                output.push_back(make_pair(vc[j] + 1, i));
            }
        }
        map[sum].push_back(i);
    }
    return output;
}

int main(int args, char **_argc)
{
    // int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int sum = 23;
    // // subArraySum(arr, n, sum);
    // subArraySum2(arr, n, sum);

    //  Print all subarray with 0 sum=============================================================
    int arr4[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<pair<int, int>> out = findSubarrays(arr4, n4);
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i].first << ", " << out[i].second<<"\n";
    }

    // Maximm sum of i*arr[i] among all rotations of a given array==============================

    int arr2[] = {8, 3, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // cout << maxSum(arr2, n2);

    // Largest subarray with equal no of 0's and 1's===============================================
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << maxLen(arr, n);

    //largest-sum-subarray-at-least-k-numbers=============================================================================

    int a[] = {1, 1, 1, 1, 1, 1};
    int k = 4;
    int n_ = sizeof(a) / sizeof(a[0]);
    // maxSumWithK(a, n_, k);

    // No of Subarray sum divisible by K==============================================================================

    int arr3[] = {4, 5, 0, -2, -3, 1}; // {4,5,0,-2,-3,1}
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int k3 = 5; //k=5
    // cout << "Length = " << longSubarrWthSumDivByK(arr3, n3, k3);

    return 0;
}