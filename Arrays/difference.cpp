// https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
#include <iostream>
#include <algorithm>

using namespace std;

bool findPair(int arr[], int len, int difference)
{
    sort(arr, arr + len);
    int i = 0;
    int j = 0;
    while (i < len && j < len)
    {
        if (i != j && arr[j] - arr[i] == difference)
        {
            cout << "pair: " << arr[j] << ", " << arr[i];
            return true;
        }

        else if (arr[j] - arr[i] < difference)
            j++;

        else
            i++;
    }

    cout<<"no such pair";
    return false;
}

int main(int args, char **argv)
{
    // int arr[] = {1, 8, 30, 40, 100};
    int arr[] = {5, 20, 3, 2, 50, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    // int n = 60;
    int n= 70;
    findPair(arr, size, n);
    return 0;
}
