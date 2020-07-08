#include <iostream>
#include <stdio.h>

using namespace std;

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
            cout << "position indices" << start << "," <<i-1;
        }

        curr_sum+=arr[i];
    }
}
int main(int args, char **_argc)
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    // subArraySum(arr, n, sum);
    subArraySum2(arr, n, sum);
    return 0;
}