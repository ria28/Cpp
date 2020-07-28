#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// void mergeInterval(pair<int, int> arr[], int n)
// {
//     sort(arr, arr + n);
//     // for (int i = 0; i < n; i++)
//     //     cout << "{" << arr[i].first << "," << arr[i].second << "}";

//     int index = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i].first <= arr[index].second)
//         {
//             arr[index].first = min(arr[index].first, arr[i].first);
//             arr[index].second = max(arr[index].second,arr[i].second);
//         }
//         else
//         {

//             index++;
//         }
//     }
//     for (int i = 0; i <= index; i++)
//         cout << "{" << arr[i].first << "," << arr[i].second << "}";

// }

void mergeInterval(pair<int, int> arr[], int n)
{
    stack<pair<int, int>> s;
    sort(arr, arr + n);

    // int index = 0;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        pair<int, int> top = s.top();
        if (top.second < arr[i].first)
            s.push(arr[i]);
        else if (top.second < arr[i].second)
        {
            top.second = arr[i].second;
            s.pop();
            s.push(top);
        }
    }

    while (!s.empty())
    {
        pair<int, int> ele = s.top();
        cout << "{" << ele.first << "," << ele.second << "}";
        s.pop();
    }
}

void mergeInterval2(pair<int, int> arr[], int n, pair<int, int> newPair)
{
    stack<pair<int, int>> stk;

    stk.push(arr[0]);

    pair<int, int> top = stk.top();
    if (newPair.first < top.second)
    {
        stk.pop();
        top.first = min(top.first, newPair.first);
        top.second = max(top.second, newPair.second);
        stk.push(top);
    }
    else
    {
        stk.push(newPair);
    }

    for (int i = 1; i < n; i++)
    {
        
        pair<int, int> top = stk.top();
        if (arr[i].first < top.second)
        {
            
            stk.pop();
            top.first = min(top.first, arr[i].first);
            top.second = max(top.second, arr[i].second);
            stk.push(top);
        }
        
        else
        {
            
            stk.push(arr[i]);
        }
    }

    while (stk.empty() != true)
    {
        pair<int, int> ele = stk.top();
        stk.pop();
        cout << "{ " << ele.first << ", " << ele.second << " }  ";
    }
}

int main(int args, char **argc)
{
    pair<int, int> arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    // mergeInterval(arr, n);

    // pair<int, int> arr2[]= {{1,3}, {6,9}};
    // pair<int, int> newPair{4, 9};
    pair<int, int> arr2[] = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    pair<int, int> newPair{2,5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeInterval2(arr2, n2, newPair);
    return 0;
}
