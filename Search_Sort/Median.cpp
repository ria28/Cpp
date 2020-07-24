#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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

int main(int args, char **argc)
{
    int x[] = {1, 3, 8, 9, 15};
    int n1 = sizeof(x) / sizeof(x[0]);
    int y[] = {7, 11, 19, 21, 18, 25};
    int n2 = sizeof(y) / sizeof(y[0]);

    cout << findMedian(x, n1, y, n2);
}