#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/counting-sort/
void count_sort(vector<int> &arr, int n)
{
    int max_ = *max_element(arr.begin(), arr.end()); // Returns an iterator pointing to the element with the largest value in the range [first,last).
    int min_ = *min_element(arr.begin(), arr.end());
    int range = max_ - min_ + 1;

    vector<int> output(n), count(range);

    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min_]++;
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = 0; i < arr.size(); i++)
    {
        output[count[arr[i] - min_] - 1] = arr[i];
        count[arr[i] - min_]--;
    }

    for (int i = 0; i < n; i++)
        // arr[i] = output[i];
        cout << output[i];
}

// https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/

bool checkReverse(int arr[], int n)
{
    int i = 0, j, k;
    int startD;
    for (j = 1; j < n; j++)
    {
        if (arr[j - 1] < arr[j])
            continue;
        else
            break;
    }
    startD = j - 1;
    // cout<<startD;
    for (k = j; k < n; k++)
    {
        if (arr[k - 1] > arr[k])
            continue;
        else
            break;
    }
    int stopD = k - 1;
    // cout<<stopD;

    if (arr[startD] > arr[stopD + 1] && stopD + 1 < n)
        return false;

    if (arr[stopD] < arr[startD - 1])
        return false;

    if (k == n - 1)
        return true;
}

// NEARLY SORTED ALGORITHM (K -SORTED)============================================================
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

void sortK(int arr[], int n, int k)
{
    // kind of window sliding approach using min heap

    // put first k element (0,1,2...k) int min heap
    priority_queue<int, vector<int>, greater<int>> min_heap(arr, arr + k + 1);

    int index = 0; // to recreate array --> result i.e, array sorted

    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = min_heap.top();
        min_heap.pop();
        min_heap.push(arr[i]);
    }

    // left over elements
    while (min_heap.empty() == false)
    {
        arr[index++] = min_heap.top();
        min_heap.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " , ";
    }
}

// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// sort-integers-by-the-number-of-1-bits

int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
vector<int> sortByBits(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> count(32);
    int setbitcount = 0;
    for (int i = 0; i < n; i++)
    {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }

    int j = 0; // Used as an index in final sorted array

    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i = 0; i < 31; i++)
    {
        vector<int> v1 = count[i];
        if (v1.size() == n)
        {
            sort(arr.begin(), arr.end());
            return arr;
        }
        sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size(); i++)

            arr[j++] = v1[i];
    }

    return arr;
}

int main(int args, char **argc)
{
    vector<int> arr{1, 4, 1, 2, 7, 5, 2};
    int n = arr.size();
    // count_sort(arr, n);

    // int arr2[] = {1, 3, 4, 10, 9, 8};
    // int arr2[]={ 1, 2, 4, 5, 3};
    // int arr2[] ={1,2,3,4,20,9,16,17};
    int arr2[] = {1, 2, 3, 4, 20, 9, 21, 22};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // cout << boolalpha << checkReverse(arr2, n2);

    //  NEARLY SORTED ALGORITHM (K -SORTED)
    int arr3[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    // sortK(arr3, n, k);

    // Sort an array according to count of set bits

    // vector<int> arr4{0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr4{1024,512,256,128,64,32,16,8,4,2,1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> out = sortByBits(arr4);
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";
}