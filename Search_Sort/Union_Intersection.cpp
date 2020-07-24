#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set{nums1.begin(), nums1.end()};
    vector<int> intersect;

    for (auto n : nums2)
    {
        if (set.find(n) != set.end())
        {
            intersect.push_back(n);
            set.erase(n);
        }
    }

    return intersect;
}

void intersection_three(int arr1[], int arr2[], int arr3[], int & n1, int & n2, int & n3)
{
    int i = 0, j = 0, k = 0;
    // vector<int> intersect;

    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j]==arr2[k])
        {
            // intersect.push_back(arr1[i]);
            cout<<arr1[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j])
            i++;
        else if(arr2[j]<arr3[k])
            j++;
        else
            k++;
    }

    // return intersect;
}

int main(int args, char **argc)
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    // vector<int> nums1{1, 2, 3, 4};
    // vector<int> nums2{2, 4, 6, 8};
    // vector<int> intersect = intersection(nums1, nums2);
    // for (int i = 0; i < intersect.size(); i++)
    // {
    //     cout << intersect[i];
    // }

    intersection_three(ar1,ar2,ar3,n1,n2,n3);
    // for (int i = 0; i < intersect2.size(); i++)
    // {
    //     cout << intersect2[i];
    // }

    

}