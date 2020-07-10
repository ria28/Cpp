// https://www.geeksforgeeks.org/find-k-pairs-smallest-sums-two-arrays/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void kSmallestPair(vector<int> A, vector<int> B, int k)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    //  Min heap priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));

    while (k > 0)
    {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        int i = temp.second.first;
        int j = temp.second.second;
        int sum = A[i + 1] + B[j];

        cout<<"( "<<A[i]<<","<<B[j]<<" )";

        pq.push(make_pair(sum,make_pair(i+1,j)));

        sum = A[i]+ B[j+1];

        pq.push(make_pair(sum,make_pair(i,j+1)));

        k--;

    }
}
int main(int args, char **argc)
{
    vector<int> A = {1, 3, 11};
    vector<int> B = {2, 4, 8};
    int K = 4;
    kSmallestPair(A, B, K);
    return 0;
}
