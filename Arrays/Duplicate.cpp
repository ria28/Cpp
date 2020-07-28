#include <iostream>
#include <math.h>
#include <unordered_set>
using namespace std;

void printDuplicate2(int arr[], int n)
{
    unordered_set<int> set;
    for (int i = 0; i < n; i++)
    {
        if(set.find(arr[i]) != set.end())
            cout<<arr[i]<<", ";
        else
            set.insert(arr[i]);        
    }
}

// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
void printDuplicate1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << ", ";
    }
}
int main(int args, char **argc)
{
    int arr[] = {2, 3, 4, 5, 5, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // repeating when nos range from 0 to n-1 in O(n) time with O(1) space
    printDuplicate1(arr, size);
    // printMIssing  the index which is positive

    // nos are not in range if 0 to n-1 ... done in O(n) and O(n) time and space resp.
    int arr2[] = {20, 13, 4, 20, 13, 6, 2};
    printDuplicate2(arr2, size);

}