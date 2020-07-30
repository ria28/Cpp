#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

void productArray(int arr[], int n)
{
    if (n == 1)
    {
        cout << 0;
        return;
    }
    int temp = 1;
    int prod[n];

    for (int i = 0; i < n; i++)
    {
        prod[i] = temp;
        temp *= arr[i];
    }

    temp = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        prod[i] *= temp;
        temp *= arr[i];
    }

    for (int i = 0; i < n; i++)
        cout << prod[i] << ", ";
}

// https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/
// find-pair-with-greatest-product-in-array
int findGreatest(int arr[], int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    sort(arr, arr + n);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i && arr[j] <= sqrt(arr[i]); j++)
        {
            if (arr[i] % arr[j] == 0)
            {
                int dividend = arr[i]/arr[j];
                if(dividend != arr[j] && map[dividend]>0)
                    return arr[i];
                else if(dividend == arr[j] && map[dividend]>1)
                    return arr[i];
            }
        }
    }

    return -1;
}

int main(int args, char **argc)
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // productArray(arr, n);

    int arr2[] = {17, 2, 1, 15, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << findGreatest(arr2, n2);
}