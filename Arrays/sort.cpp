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

// Sort array of 0 1 2's  / Dutch National flag problem / 3 way sort===============================================

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
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 3 WAY sort ==============================================================================

void partition3Way(int arr[], int low, int high, int &i, int &j)
{
    int mid = low;
    int pivot = arr[high];

    while (mid <= high)
    {
        if (arr[mid] < pivot)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == pivot)
            mid++;
        else if (arr[mid] > pivot)
            swap(arr[mid], arr[high--]);
    }

    i = low - 1;
    j = high + 1; // or j =mid
}

void ThreeWaySort(int arr[], int low, int high)
{
    if (low >= high) //1 or 0 elements
        return;
    int i, j;
    partition3Way(arr, low, high, i, j);

    ThreeWaySort(arr, low, i);
    ThreeWaySort(arr, j, high);
}

// 3 way partitioning==========================================================================

void ThreeWayPartioning(int arr[], int n, int lowVal, int highVal)
{
    int start = 0, end = n - 1;

    for (int i = 0; i <= end;)
    {
        if (arr[i] < lowVal)
            swap(arr[i++], arr[start++]);
        else if (arr[i] > highVal)
            swap(arr[i], arr[end--]);
        else
            i++;
    }
}
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = right;
    int inv_count = 0;

    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]= arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv_count += mid - i;
        }
    }

    while(i<=mid-1)
        temp[k++]= arr[i++];
    while(j<=right)
        temp[k++]= arr[j++];

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int inv_count = 0;
    if (right > left)
    {
        int mid = right + left / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}
int main(int args, char **argv)
{
    // Rearrage array alternatively -ve and +ve terms=========================================================
    int arr[] = {-1, 2, -3, 4,
                 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // rearrage(arr, n);

    // Sort array of 0 1 2's  / Dutch National flag problem / 3 way sort========================================
    int arr2[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // sort_012(arr2, n2);

    // quickSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    // 3 WAY sort=========================================================
    int arr3[] = {4, 9, 4, 4, 9, 1, 1, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    ThreeWaySort(arr3, 0, n3 - 1);
    // for (int item = 0; item < n3; item++)
    //     cout << arr3[item] << " ";

    // 3 way partitioning===================================================

    int arr4[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int lowVal = 14, highVal = 20;
    ThreeWayPartioning(arr4, n, lowVal, highVal);
    for (int item = 0; item < n4; item++)
        cout << arr4[item] << " ";

    int arr5[] = {1, 20, 6, 7, 5, 8, 11, 13};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int temp[n5];
    _mergeSort(arr5, temp, 0, n5 - 1);
}
