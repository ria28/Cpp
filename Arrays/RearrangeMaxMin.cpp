#include <iostream>

using namespace std;

void Rearrange(int arr[], int n)
{
    int max_ele = arr[n - 1] + 1, min_idx = 0, max_idx = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[max_idx] % max_ele) * max_ele;
            max_idx--;
        }
        else
        {
            arr[i] += (arr[min_idx] % max_ele) * max_ele;
            min_idx++;
        }
    }

    for(int i =0; i<n ; i++)
        arr[i]= arr[i]/max_ele;

    for(int i =0; i<n ; i++)
        cout<<arr[i];
    
}
int main(int args, char **argc)
{
    int arr[] = {2, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Rearrange(arr, n);
}