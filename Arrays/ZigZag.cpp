// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
#include <iostream>

using namespace std;

void zigZag(int arr[], int len)
{
    bool flag = false;

    for (int i = 0; i < len - 1; i++)
    {
        if (flag == false)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
            flag = true;
        }
        else
        {
            if (arr[i] < arr[i + 1])
                swap(arr[i], arr[i + 1]);
            flag = false;
        }
    }

    for (int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
}

int main(int args, char **argc)
{
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    zigZag(arr, n);
}