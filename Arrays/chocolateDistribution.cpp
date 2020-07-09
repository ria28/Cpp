// https://www.geeksforgeeks.org/chocolate-distribution-problem/

#include <iostream>
#include <algorithm>
#include<climits>

using namespace std;
int findMinDiff(int arr[], int len, int students)
{
    int minDiff= INT_MAX;
    sort(arr, arr + len);
    for (int i = 0; i+students-1 < len; i++)
    {
        int curr_diff =arr[i+students-1]-arr[i];
        if(minDiff>curr_diff)
            minDiff=curr_diff;
    }
    return minDiff;
}

int main(int args, char **argc)
{
//     int arr[] = {12, 4, 7, 9, 2, 23, 25, 41,
//                  30, 40, 28, 42, 30, 44, 48,
//                  43, 50};
//     int m = 7; // Number of students

    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int m =5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}