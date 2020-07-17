#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
// Print all possible combinations of r elements in a given array of size n======================================
void Combination(int arr[], int n, int r, int data[], int index, int i)
{
    if (index == r)
    {
        for (int i = 0; i < r; i++)
            cout << data[i];
        cout << "\n";
        return;
    }
    if (i == n)
        return;

    data[index] = arr[i];
    Combination(arr, n, r, data, index + 1, i + 1);

    Combination(arr, n, r, data, index, i + 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int data[r];
    Combination(arr, n, r, data, 0, 0);

    int curr_sum=-5, k=3;
    cout<<((curr_sum % k) + k) % k;
}