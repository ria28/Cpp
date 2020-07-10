#include <iostream>
#include <stdio.h>

using namespace std;

int kadane(int a[], int len)
{
    int curr_max = 0;
    int final_max = 0;

    for (int i = 0; i < len; i++)
    {
        curr_max = curr_max + a[i];

        if (curr_max < 0)
            curr_max = 0;

        if (final_max < curr_max)
            final_max = curr_max;
    }
    return final_max;
}

int MaxCirSubArraySum(int a[], int len)
{
    int max_kadane = kadane(a, len);

    int max_wrap = 0;
    for (int i = 0; i < len; i++)
    {
        max_wrap = max_wrap + a[i];
        a[i] = -a[i];
    }
    // array sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, len);

    return max_kadane>=max_wrap?max_kadane:max_wrap;
}

int main(int args, char **argc)
{
    // int a[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};
    // int a[] = {10, -3, -4, 7, 6, 5, -4, -1} ;
    int a[] = {-1, 40, -14, 7, 6, 5, -4, -1};
    int len = sizeof(a) / sizeof(a[0]);
    cout<<MaxCirSubArraySum(a, len);
    return 0;
}