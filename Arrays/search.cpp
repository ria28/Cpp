#include <iostream>

using namespace std;

// find element i n sorted and rotated array================================================================
int binarySearch(int arr[], int low, int high, int key)
{

    if (high < low)
        return -1;

    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;

    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);

    // else
    return binarySearch(arr, low, (mid - 1), key);
}

int findPivot(int arr[], int low, int high)
{
    if (low > high)
        return -1;

    int mid = high / 2;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;

    if (arr[low] > arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

// find sum in sorted and rotated array==================================================================
void pairInSortedRotated(int arr[], int n, int sum)
{
    int r = findPivot(arr, 0, n - 1);
    int l = (r + 1) % n;

    while (l != r)
    {
        if (arr[l] + arr[r] == sum)
            cout << l << r;
        if (arr[l] + arr[r] < sum)
            l = (l + 1) % n;
        else
            r= (r+n-1)%n;
    }
}

int main(int args, char **argc)
{
    // int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key = 6;

    // int pivot = findPivot(arr, 0, n - 1);
    // if (pivot = -1)
    //     cout<<binarySearch(arr, 0, n, key);

    // else if (arr[pivot] == key)
    //     cout << pivot;
    // else if (arr[0] <= key)
    //     cout<<binarySearch(arr, 0, pivot - 1, key);
    // else
    //     cout<<binarySearch(arr, pivot + 1, n - 1, key);

    int arr2[] = {11, 15, 6, 8, 9, 10};
    int sum = 16;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    pairInSortedRotated(arr2, n2, sum);
}