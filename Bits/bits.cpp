#include <iostream>
using namespace std;

int sumBitDifferences(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] & (1 << i))
                count++;

        ans += (count * (n = count));
    }
    return ans;
}

int main(int args, char **argc)
{
    int arr[] = {1, 3, 5};
    int n = sizeof arr / sizeof arr[0];
    cout << sumBitDifferences(arr, n) << endl;
    return 0;
}