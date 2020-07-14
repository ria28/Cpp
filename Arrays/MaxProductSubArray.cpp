#include <iostream>

using namespace std;

int MaxProduct(int arr[], int n)
{
    int curr_max = arr[0], curr_min = arr[0], final_max = arr[0];
    for (int i = 0; i < n; i++)
    {
        int temp = curr_max;
        curr_max = max(max(curr_max * arr[i], curr_min * arr[i]), arr[i]);
        curr_min = min(min(curr_max * arr[i], curr_min * arr[i]), arr[i]);

        if(final_max<curr_max)
            final_max= curr_max;
    }

    return final_max;
}

int main(int args, char **argc)
{
    int arr[] = {1, 6, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxProduct(arr, n);

    return 0;
}