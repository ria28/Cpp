#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 3 8 1 6 4 ---> arr : 4 6 1 8 3
int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> maxHeap;
    int temp = n;
    vector<int> arr;
    while (temp)
    {
        int rem = temp % 10;
        temp = temp / 10;
        arr.push_back(rem);
    }
    temp = n;
    for (int i = 0; i < arr.size(); i++)
    {
        maxHeap.push(make_pair(arr[i], arr.size()-1-i));
    }
    for (int i = 0, j = arr.size() - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int idx = 0;
    // while (!maxHeap.empty())
    // {
    //     pair<int, int> top = maxHeap.top();
    //     maxHeap.pop();
    //     cout << top.first << "-->" << top.second << "\n";
    // }

    while (k--)
    {
        pair<int, int> top = maxHeap.top();
        maxHeap.pop();
        if (arr[idx] < top.first)
        {
            int temp = arr[idx];
            arr[idx] = top.first;
            arr[top.second] = temp;
            idx++;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}