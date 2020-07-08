// https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/

#include <iostream>
#include <stdio.h>

using namespace std;

void reorder(int arr[], int idx[], int len)
{
    int temp[len];
    for (int i = 0; i < len; i++)
        temp[idx[i]] = arr[i];
    
    for(int i =0; i<len;i++){
        cout<<temp[i];
    }

}

int main(int args, char **argc)
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3, 0, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    reorder(arr, index, n);
}