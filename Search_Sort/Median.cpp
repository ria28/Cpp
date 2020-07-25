#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include<math.h>

using namespace std;

int findMedian(int x[], int n1, int y[], int n2)
{
    if (n1 > n2)
        return findMedian(y, n2, x, n1);

    int low = 0;
    int high = n1;

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (n1 + n2 + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT64_MIN : x[partitionX - 1];
        int minRightX = (partitionX == n1) ? INT64_MAX : x[partitionX];

        int maxLeftY = (partitionY == 0) ? INT64_MIN : y[partitionY - 1];
        int minRightY = (partitionY == n2) ? INT64_MAX : y[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY) / 2);
            }
            else
                return max(maxLeftX, maxLeftY);
        }
        else if (maxLeftX > minRightY)
        {
            high = partitionX - 1;
        }
        else
        {
            low = partitionX + 1;
        }
    }
}

// https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/?ref=rp
void printMedian(double arr[], int n)
{
    priority_queue<double> s;                                  // max heap
    priority_queue<double, vector<double>, greater<double>> g; // min heap

    double med = arr[0];
    s.push(med);
    cout << med << "\n";

    for (int i = 1; i < n; i++)
    {
        double x = arr[i];

        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }

            med = (double)(s.top() + g.top()) / 2;
        }
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)(s.top());
            }
            else
            {
                g.push(x);
                med = (double)(g.top());
            }
        }
        else
        {
            if (x < med)
            {
                s.push(x);
            }
            else
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            med = (double)(s.top() + g.top()) / 2;
        }

        cout << med << "\n";
    }
}

// https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/
void minCostToMakeElementEqual(int arr[], int n)
{
    double median;
    if (n % 2 == 0)
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        median = arr[n / 2];
    int sum = 0;

    for(int i=0; i<n;i++)
    {
        sum+=abs(arr[i]-median);
    }
    cout<<sum;
}

int main(int args, char **argc)
{
    // median of  sorted array of differnt size.======================================================
    int x[] = {1, 3, 8, 9, 15};
    int n1 = sizeof(x) / sizeof(x[0]);
    int y[] = {7, 11, 19, 21, 18, 25};
    int n2 = sizeof(y) / sizeof(y[0]);

    // cout << findMedian(x, n1, y, n2);

    // median-of-stream-of-running-integers-using-stl=================================================
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // printMedian(arr, n);

    // make-array-elements-equal-minimum-cost====================================================

    // int arr3[]= {1,100,101};
    int arr3[]={4,6};
    int n3=sizeof(arr3) / sizeof(arr3[0]);
    minCostToMakeElementEqual(arr3,n3);
    return 0;
}