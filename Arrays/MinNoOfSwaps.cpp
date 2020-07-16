// https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/

// Minimum swaps required to bring all elements less than or equal to k together =============================================================
#include <iostream>

using namespace std;

int minSwap(int arr[], int n, int k)
{
    int count = 0, bad =0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++;
    
    for (int i = 0; i < n; i++)
        if (arr[i] > k)
            bad++;

    int ans = bad;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        if(arr[i]>k)
            bad--;
        if(arr[j]>k)
            bad++;
        
        ans = min(ans, bad);

    }
    return ans;
}

int main(int args, char **argc)
{

    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";

    // int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    // n = sizeof(arr1) / sizeof(arr1[0]);
    // k = 5;
    // cout << minSwap(arr1, n, k);
    return 0;
}