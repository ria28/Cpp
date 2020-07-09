// https://www.geeksforgeeks.org/trapping-rain-water/
#include <iostream>
#include <algorithm>

using namespace std;

int findWater(int h[], int n)
{
    int l = 0, r = n - 1, l_max = 0, r_max = 0;
    int ans = 0;

    while (l <= r)
    {
        if (h[l] < h[r])
        {
            if (h[l] >= l_max)
            {
                l_max = h[l];
            }
            else
            {
                ans += l_max - h[l];
            }
            l++;
        }
        else
        {
            if (h[r] > r_max)
            {
                r_max = h[r];
            }
            else
            {
                ans += r_max - h[r];
            }
            r--;
        }
    }

    return ans;
}
int main(int args, char **argc)
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
    return 0;
}