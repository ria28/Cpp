// https://www.geeksforgeeks.org/trapping-rain-water/
#include <iostream>
#include <algorithm>

using namespace std;

int findWater(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // ??
    }
}
int main(int args, char **argc)
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
    return 0;
}