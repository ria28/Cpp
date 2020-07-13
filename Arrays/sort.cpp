// Quick Sort

#include <iostream>

using namespace std;

void rearrage(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    int pos = j + 1, neg = 0;
    while (pos < n && arr[neg] < 0)
    {
        swap(arr[pos], arr[neg]);
        neg = neg + 2;
        pos++;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Sort array of 0 1 2's  / Dutch National flag problem / 3 way sort

void sort_012(int arr[], int n)
{
    int lo = 0, mid = 0, hi = n - 1;

    while (mid <= hi)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[lo++], arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[hi--]);
            break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(int args, char **argv)
{
    // Rearrage array alternatively -ve and +ve terms
    int arr[] = {-1, 2, -3, 4,
                 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrage(arr, n);

    // Sort array of 0 1 2's  / Dutch National flag problem / 3 way sort
    int arr2[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sort_012(arr2, n2);

    


}
