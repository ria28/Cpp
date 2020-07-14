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
    
    int index = 0;
    s.push(arr[index]);
    for (int i = 1; i < n; i++)
    {
        pair<int,int> top = s.top();
        if (top.second < arr[i].first) 
            s.push(arr[i]); 
        else if (top.second < arr[i].second) 
        { 
            top.second = arr[i].second; 
            s.pop(); 
            s.push(top); 
        } 
    }

    while(!s.empty())
    {
        pair<int,int> ele= s.top();
        cout<<"{"<<ele.first<<","<<ele.second<<"}";
        s.pop();
    }


}

int main(int args, char **argc)
{
    pair<int, int> arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeInterval(arr, n);
    return 0;
}
