// https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <iostream>
#include <stdio.h>

using namespace std;

void equilibrium(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    int leftSum = 0;
    for (int i = 0; i < len; i++)
    {
        sum -= arr[i];
        if (leftSum == sum)
        {
            cout<<"equilibrium pos : "<<i<<"\n";
        }
        leftSum += arr[i];
    }
}

int main(int args, char **argc)
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    equilibrium(arr, arr_size);
}