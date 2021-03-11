#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

// int longestMountain(vector<int> &A)
// {
//     if (A.size() == 0 || A.size() == 1)
//         return 0;
//     vector<int> inc(A.size());
//     vector<int> dec(A.size());
//     bool dec_flag = false, inc_flag = false;
//     int k1, k2;

//     inc[0] = 1;
//     dec[A.size() - 1] = 1;
//     for (int i = 1; i < A.size(); i++)
//     {
//         if (A[i] > A[i - 1])
//         {
//             inc[i] += inc[i - 1] + 1;
//             inc_flag = true;
//             k1 = i;
//         }
//         else
//             inc[i] = 1;
//     }
//     for (int i = A.size() - 2; i >= 0; i--)
//     {
//         if (A[i] > A[i + 1])
//         {
//             dec[i] += dec[i + 1] + 1;
//             dec_flag = true;
//             k2 = i;
//         }
//         else
//             dec[i] = 1;
//     }
//     cout << k1 << k2;
//     if (!inc_flag || !dec_flag || k1 != k2)
//         return 0;
//     int max_val = inc[0] + dec[0] - 1;
//     for (int i = 1; i < A.size(); i++)
//     {
//         max_val = max(max_val, inc[i] + dec[i] - 1);
//     }

//     return max_val == 1 ? 0 : max_val;
// }
// vector<vector<int>> merge(vector<vector<int>> arr)
// {
//     stack<pair<int, int>> st;
//     st.push(make_pair(arr[0][0], arr[0][1]));
//     for (int i = 1; i < arr.size(); i++)
//     {
//         pair<int, int> top = st.top();
//         if (top.second < arr[i][0])
//             st.push(make_pair(arr[i][0], arr[i][1]));
//         else if (top.second < arr[i][1])
//         {
//             top.second = arr[i][1];
//             st.pop();
//             st.push(top);
//         }
//     }
//     vector<vector<int>> res(arr.size(),vector<int>(2));
//     int i = 0;
//     while (!st.empty())
//     {
//         // cout<<st.top().first<<st.top().second;
//         res[i][0] = st.top().first;
//         res[i][1] = st.top().second;
//         st.pop();
//         i++;
//         // cout<<res[i][0];
//     }
//     // for (int i = 0; i < res.size(); i++)
//     // {
//     //     cout << "[" << res[i][0] << "," << res[i][1] << "]";
//     // }
//     return res;
// }
bool binarySearch(vector<int> &arr, int low, int high, int target)
{
    // cout<<low<<high;
    if (low > high)
        return false;
    int mid = low + (high - low) / 2;
    if (target == arr[mid])
        return true;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    return binarySearch(arr, low, mid - 1, target);
}
int findPivot(vector<int> &arr, int low, int high)
{
    cout<<low<<high<<"\n";
    if (low > high)
        return -1;
    if (low == high)
        return -1;
    int mid = low + (high - low) / 2;
    cout<<mid;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;
    if (arr[low] > arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
bool search(vector<int> &nums, int target)
{
    if (nums.size()==0)
        return false;
    int pi = findPivot(nums, 0, nums.size() - 1);
    cout<<pi;
    if (pi == -1)
        return binarySearch(nums, 0, nums.size() - 1, target);
    if (nums[pi] == target)
        return true;
    if (nums[0] <= target)
        return binarySearch(nums, 0, pi - 1, target);
    return binarySearch(nums, pi + 1, nums.size() - 1, target);
}
int main()
{
    vector<int> nums{2,2,2,3,1};
    cout<<(boolalpha)<<search(nums,1);
    return 0;


   
}