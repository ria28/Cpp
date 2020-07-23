#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums.empty() || nums.size() < 3)
        {
            return output;
        }

        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1;
            int high = nums.size() - 1;
            int sum = 0 - nums[i];
            while (low < high)
            {
                // cout<< low<<" "<<high<<"\n";
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> list{nums[i], nums[low], nums[high]};
                    // cout<<nums[i]<<nums[low]<<nums[high];
                    output.push_back(list);
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
    return output;
}
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    unordered_map<int, pair<int, int>> map;

    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            map[nums[i] + nums[j]] = {i, j};
        }
    }

    vector<vector<int>> output;
    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int sum = nums[i] + nums[j];

            if (map.find(target - sum) != map.end())
            {
                pair<int, int> p = map[target - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout<<"{ "<<nums[i]<<","<<nums[j]<<","<<nums[p.first]<<","<<nums[p.second]<<" }";
                    vector<int> list{nums[i], nums[j], nums[p.first], nums[p.second]};
                    output.push_back(list);
                }
            }
        }
    }

    return output;
}
int main(int args, char **argc)
{
    // 3 Sum=====================================================================================================
    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    // vector<vector<int>> output = threeSum(nums);
    // for (int i = 0; i < output.size(); i++)
    // {
    //     for (int j = 0; j < output[i].size(); j++)
    //         cout << output[i][j] << " ";
    //     cout << endl;
    // }

    // 4 sum =====================================================================================================
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> output2 = fourSum(nums,0);
    for (int i = 0; i < output2.size(); i++)
    {
        for (int j = 0; j < output2[i].size(); j++)
            cout << output2[i][j] << " ";
        cout << endl;
    }
}
