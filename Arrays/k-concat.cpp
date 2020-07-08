#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// K-Concatenation ==================================================================================================

int kConcat(vector<int> &A, int k)
{
    int sum = 0;
    int maxSum=0;
    vector<int> B;
    for (int i = 0; i < k; i++)
    {
        B.insert(B.end(), A.begin(), A.end());
    }

    for (int i = 0; i < B.size(); i++)
    {
        sum = sum + B.at(i);
        if(sum>=maxSum){
            maxSum=sum;
        }
        else
        {
            sum =0;
        }
        

    }
    return maxSum;
}

int main(int args, char **argv)
{
    int testCases;
    int N, k, input, maxSum;
    vector<int> A;
    // cin >> testCases;
    
    cin >> N >> k;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        A.push_back(input);
    }

    maxSum = kConcat(A, k);
    cout << "Max Sum " << maxSum;

    return 0;
}
