#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/merge-sorted-array/submissions/
vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];

    return nums1;
}

int main(int args, char **argc)
{
    vector<int> nums1{1, 5, 9, 10, 15, 20};
    int m = nums1.size();
    vector<int> nums2{2, 3, 8, 13};
    int n = nums2.size();

    vector<int> output = merge(nums1, m, nums2, n);
}