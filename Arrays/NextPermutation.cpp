#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(vector<int> &nums,int i)
{
    int j =nums.size()-1;
    while(i<j)
    {
        swap(nums,i,j);
        i++;
        j--;
    }
}

void printArr(vector<int> &nums)
{
    for(int i =0; i<nums.size();i++)
        cout<<nums[i]<<" ";
    
}
void nextPermutation(vector<int> &nums)
{
    int n = nums.size() - 2;
    int i = n;

    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    int start = i + 1;
    int j;
    if(i>=0)
    for (j = nums.size()-1; j >= start; j--)
    {
        if (nums[j] > nums[i])
            break;
    }
    swap(nums, i, j);
    // printArr(nums);
    // cout<<"\n";

    reverse(nums,i+1);

    printArr(nums);
}
int main(int args, char **argc)
{
    // vector<int> nums{1, 5, 8, 4, 7, 6, 5, 3, 1};
     vector<int> nums{1,2,3};
    nextPermutation(nums);
    return 0;
}