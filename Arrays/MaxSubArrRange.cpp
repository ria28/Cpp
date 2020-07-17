#include <iostream>
using namespace std;

int MaxInBoundary(int arr[], int n, int L, int R)
{
    int res = 0, invalid = -1, valid = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > R)
        {
            invalid = i;
            valid = i;
        }
        else if (arr[i] >= L && arr[i] <= R)
        {
            valid =i;
        }
        res += valid-invalid;
    }
    return res;
}
int main(int args, char **argc)
{
    int arr[] = {1, 2, 5, 3, 4, 1, 2};
    int L = 3, R = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MaxInBoundary(arr, n, L, R);
    return 0;
}