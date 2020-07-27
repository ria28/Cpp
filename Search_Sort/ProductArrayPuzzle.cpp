#include <iostream>

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

int main(int args, char **argc)
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    productArray(arr, n);
}