#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>


// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k == 0)
            return arr;
        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (carry == 0)
            {
                arr[i] += k % 10;
                if (arr[i] < 10)
                    carry = 0;
                else
                {
                    carry = arr[i] / 10;
                    arr[i] = arr[i] % 10;
                }
            }
            else
            {
                arr[i] += k % 10 + 1;
                if (arr[i] < 10)
                    carry = 0;
                else
                {
                    carry = arr[i] / 10;
                    arr[i] = arr[i] % 10;
                }
            }

            k = k / 10;
        }
        if (k != 0)
        {
            while (k)
            {
                int ele = carry + k % 10;
                if (ele < 10)
                {
                    arr.insert(arr.begin(), ele);
                    carry = 0;
                }
                else
                {
                    carry = ele / 10;
                    ele = ele % 10;
                    arr.insert(arr.begin(), ele);
                }

                k = k / 10;
            }
        }
        if (carry != 0)
        {
            arr.insert(arr.begin(), carry);
        }

        return arr;
    }
};