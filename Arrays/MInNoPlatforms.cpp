// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
#include <iostream>
#include <algorithm>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0, max_plat = 1, plat_needed = 1;
    while (i < n && j < n)
    {
        if (arr[i] > dep[j])
        {
            j++;
            max_plat--;
        }
        if (arr[i] <= dep[j])
        {
            i++;
            max_plat++;
        }
        if (plat_needed < max_plat)
        {
            plat_needed = max_plat;
        }
    }

    return plat_needed;
}

int main(int args, char **argc)
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}