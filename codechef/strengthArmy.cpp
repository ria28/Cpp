#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        float n, mi, ma;
        cin >> n >> mi >> ma;
        vector<float> arr;
        for (float i = 0; i < n; i++)
        {
            float ele;
            cin >> ele;
            arr.push_back(ele);
        }
        sort(arr.begin(), arr.end());
        float sum = 0;
        int cnt = 0;
        float avg = 0;
        for (int i = n - 1; i >= 0 && cnt <= mi; i--)
        {
            sum += arr[i];
            cnt++;
            // cout << sum << " ";
            if (cnt == mi)
            {
                avg += sum / mi;
                sum = 0;
                cnt =0;
            }
        }
        cout << avg << "\n";
    }
    return 0;
}