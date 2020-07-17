#include <iostream>
using namespace std;

//https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

int findMinOps(int arr[], int n)
{
    int merge=0;
    for (int i = 0, j = n - 1; i <= j;)
    {
        if(arr[i]==arr[j])
        {
            i++;
            j--;
        }
        else if(arr[i]>arr[j])
        {
            arr[j-1] += arr[j];
            j--;
            merge++;
        }
        else
        {
            arr[i+1]+=arr[i];
            i++;
            merge++;
        }
        
    }
    return merge;
}

int main(int args, char **argc)
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is "
         << findMinOps(arr, n) << endl;
}