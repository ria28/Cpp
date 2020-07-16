#include <iostream>
#include <unordered_map>
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
        sum = max(max(sum + arr[i], sum + arr[i] - arr[i - k]),sum);
    }
    cout<<sum;
}

int main(int args, char **_argc)
{
    // int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int sum = 23;
    // // subArraySum(arr, n, sum);
    // subArraySum2(arr, n, sum);

    // Maximm sum of i*arr[i] among all rotations of a given array

    int arr2[] = {8, 3, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // cout << maxSum(arr2, n2);

    // Largest subarray with equal no of 0's and 1's
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // cout << maxLen(arr, n);

    //largest-sum-subarray-at-least-k-numbers=============================================================================

    int a[] = {1, 1, 1, 1, 1, 1};
    int k = 4;
    int n_ = sizeof(a) / sizeof(a[0]);
    maxSumWithK(a, n_, k);
    return 0;
}