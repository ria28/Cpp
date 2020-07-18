// https://www.codechef.com/JAN18/problems/MAXSC/

#include <iostream>

using namespace std;
int N;
int MaxScore(int N, int **arr, int testCases)
{
    int max_sum = 0, max1 = 0, max2 = 0;

    while (testCases--)
    {
        for (int i = 0; i < N; i++)
        {
            max1 = 0;
            for (int j = 0; j < N; j++)
            {
                if (max1 < arr[i][j] && arr[i][j] >= max2)
                    max1 = arr[i][j];
            }

            if (max1 == 0)
                return -1;
            else
            {
                max_sum += max1;
                max2 = max1;
            }
        }
        return max_sum;
    }
}
int main(int args, char **argc)
{
    int N, T;
    cout << "enter testcase";
    cin >> T;
    cout << "enter N ";
    cin >> N;
    // int arr[N][N];

    // dynamically create array of pointers of size m
    int **arr = (int **)malloc(N * sizeof(int *));

    // dynamically allocate memory of size n for each row
    for (int r = 0; r < N; r++)
        arr[r] = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << MaxScore(N, arr, T);
}