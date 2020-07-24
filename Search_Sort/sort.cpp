#include <iostream>
#include <vector>
#include <algorithm>

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
        cout<<output[i];
  
}

int main(int args, char **argc)
{
    vector<int> arr{1, 4, 1, 2, 7, 5, 2};
    int n = arr.size();
    count_sort(arr, n);
}