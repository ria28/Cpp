#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
// Minimum swaps required to bring all elements less than or equal to k together =============================================================
int minSwap(int arr[], int n, int k)
{
    int count = 0, bad = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++;

    for (int i = 0; i < n; i++)
        if (arr[i] > k)
            bad++;

    int ans = bad;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        if (arr[i] > k)
            bad--;
        if (arr[j] > k)
            bad++;

        ans = min(ans, bad);
    }
    return ans;
}

// Minimum no. of swaps to make 2 arrays identical====================================================================
// https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/   -->comments

int MinSwaps(int data1[], int data2[])
{
    int n = sizeof(data1) / sizeof(data1[0]);

    if (n <= 1)
        return 0;
    int count = 0;
    // modify data2 into data2 so we create a hashmap of data2 elements with their indexes
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[data2[i]] = i;

    for (int i = 0; i < n; i++)
    {
        if (data1[i] != data2[i])
        {
            int ind1 = i;
            int val1 = data2[i];
            int ind2 = hash[data1[i]];
            int val2 = data2[ind2];

            std::swap(data2[ind1], data2[ind2]);
            hash[val1] = ind2;
            hash[val2] = ind2;
            count++;
        }
    }
    return count;
}

// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// minimum-number-swaps-required-sort-array============================================================


int main(int args, char **argc)
{

    // Minimum swaps required to bring all elements less than or equal to k together =============================================================
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";

    // int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    // n = sizeof(arr1) / sizeof(arr1[0]);
    // k = 5;
    // cout << minSwap(arr1, n, k);

    // Minimum no. of swaps to make 2 arrays identical====================================================================
    int data1[] = {3, 6, 4, 8};
    int data2[] = {4, 6, 8, 3};
    cout << MinSwaps(data1, data2);

    
    return 0;
}