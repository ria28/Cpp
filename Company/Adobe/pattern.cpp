#include <iostream>
#include <unordered_map>
using namespace std;

/* 
    * * * * * * * 
      * * * * *
        * * *
          *
*/
void pat_1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int space = 0; space < i - 1; space++)
        {
            cout << " ";
        }
        for (int star = 2 * n - (2 * i - 1); star > 0; star--)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

// count pair with sum
int pairSum(int arr[], int sum, int n)
{
    unordered_map<int, int> map;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cnt += map[sum - arr[i]];

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            cnt--;
    }
    return cnt/2;
}

int main()
{
    // pat_1(4);
    int arr[] = {10, 12, 10, 15, -1, 7, 6,
                 5, 4, 2, 1, 1, 1};
    int sum = 11;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << pairSum(arr, sum, n);
}
