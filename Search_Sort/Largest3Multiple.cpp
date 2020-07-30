#include <iostream>
#include <algorithm>
using namespace std;


// https://www.geeksforgeeks.org/minimum-swaps-to-make-two-array-identical/
void removeAndPrint(int arr[], int n, int idx1, int idx2 = -1)
{
    for (int i = n-1; i >0 ; i--)
        if (i != idx1 && i != idx2)
            cout << arr[i];
}

bool largest3Multiple(int arr[], int n)
{
    int sum;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 3 == 0)
        return true;
    sort(arr, arr + n);

    int remainder = sum % 3;

    if (remainder == 1)
    {
        int rem_2[2] = {-1, -1};
        // cout<<rem_2[0]<<rem_2[1];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 3 == 1)
            {
                removeAndPrint(arr, n, i);
                return true;
            }
            else if (arr[i] % 3 == 2)
            {
                if (rem_2[0] == -1)
                    rem_2[0] = i;
                else if (rem_2[1] == -1)
                    rem_2[1] = i;
            }
        }
        if (rem_2[0] != -1 && rem_2[1] != -1)
        {
            removeAndPrint(arr, n, rem_2[0], rem_2[1]);
            return true;
        }
    }
    else if (remainder == 2)
    {

        int rem_1[2] = {-1, -1};
        // cout<<rem_2[0]<<rem_2[1];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 3 == 2)
            {
                removeAndPrint(arr, n, i);
                return true;
            }
            else if (arr[i] % 3 == 1)
            {
                if (rem_1[0] == -1)
                    rem_1[0] = i;
                else if (rem_1[1] == -1)
                    rem_1[1] = i;
            }
        }
        if (rem_1[0] != -1 && rem_1[1] != -1)
        {
            removeAndPrint(arr, n, rem_1[0], rem_1[1]);
            return true;
        }
    }
}

int main(int args, char **argc)
{
    int arr[] = {4, 4, 1, 1, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    largest3Multiple(arr, n);
    return 0;
}